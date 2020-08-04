#include "COM_OpenCLPlatform.h"
#include "BLI_assert.h"
#include "COM_OpenCLKernel.h"
#include "COM_OpenCLManager.h"
#include "COM_Pixels.h"

const cl_image_format IMAGE_FORMAT_COLOR = {
    CL_RGBA,
    CL_FLOAT,
};
const cl_image_format IMAGE_FORMAT_VECTOR = {
    CL_RGB,
    CL_FLOAT,
};
const cl_image_format IMAGE_FORMAT_VALUE = {
    CL_R,
    CL_FLOAT,
};

OpenCLPlatform::OpenCLPlatform(OpenCLManager &man, cl_context context, cl_program program)
    : m_context(context), m_program(program), m_man(man)
{
}

OpenCLPlatform::~OpenCLPlatform()
{
  if (m_program) {
    m_man.printIfError(clReleaseProgram(m_program));
  }
  if (m_context) {
    m_man.printIfError(clReleaseContext(m_context));
  }
  deleteSamplers(
      [&](void *sampler) { m_man.printIfError(clReleaseSampler((cl_sampler)sampler)); });
}

const cl_image_format *OpenCLPlatform::getImageFormat(int elem_chs) const
{
  switch (elem_chs) {
    case 1:
      return &IMAGE_FORMAT_VALUE;
    case 3:
      return &IMAGE_FORMAT_VECTOR;
    case 4:
      return &IMAGE_FORMAT_COLOR;
    default:
      BLI_assert(!"Non implemented image format for OpenCL");
      return NULL;
  }
}

int OpenCLPlatform::getMemoryAccessFlag(MemoryAccess mem_access) const
{
  switch (mem_access) {
    case MemoryAccess::READ:
      return CL_MEM_READ_ONLY;
    case MemoryAccess::WRITE:
      return CL_MEM_WRITE_ONLY;
    case MemoryAccess::READ_WRITE:
      return CL_MEM_READ_WRITE;
    default:
      BLI_assert(!"Non implemented MemoryAccess case");
      break;
  }
  return 0;
}

ComputeKernel *OpenCLPlatform::createKernel(std::string kernel_name, ComputeDevice *device)
{
  cl_int error;
  cl_kernel cl_kernel = clCreateKernel(m_program, kernel_name.c_str(), &error);
  m_man.printIfError(error);

  auto kernel = new OpenCLKernel(m_man, *this, (OpenCLDevice *)device, kernel_name, cl_kernel);
  kernel->initialize();
  return (ComputeKernel *)kernel;
}

void *OpenCLPlatform::createSampler(PixelsSampler pix_sampler)
{
  cl_int error;
  cl_addressing_mode address;
  cl_filter_mode filter;
  switch (pix_sampler.extend) {
    case PixelExtend::UNCHECKED:
      address = CL_ADDRESS_NONE;
      break;
    case PixelExtend::CLIP:
      address = CL_ADDRESS_CLAMP;
      break;
    case PixelExtend::EXTEND:
      address = CL_ADDRESS_CLAMP_TO_EDGE;
      break;
    case PixelExtend::REPEAT:
      address = CL_ADDRESS_REPEAT;
      break;
    case PixelExtend::MIRROR:
      address = CL_ADDRESS_MIRRORED_REPEAT;
      break;
    default:
      BLI_assert(!"Non implemented PixelExtend case");
  }
  switch (pix_sampler.filter) {
    case PixelInterpolation::NEAREST:
      filter = CL_FILTER_NEAREST;
      break;
    case PixelInterpolation::BILINEAR:
      filter = CL_FILTER_LINEAR;
      break;
    default:
      BLI_assert(!"Non implemented PixelInterpolation case");
  }

  cl_sampler sampler = clCreateSampler(m_context, CL_FALSE, address, filter, &error);
  m_man.printIfError(error);
  return sampler;
}
