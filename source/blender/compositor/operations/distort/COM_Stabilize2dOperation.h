/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
<<<<<<< HEAD
 * Copyright 2011, Blender Foundation.
=======
 * Copyright 2020, Blender Foundation.
>>>>>>> upstream/compositor-up
 */

#pragma once

<<<<<<< HEAD
=======
<<<<<<< HEAD:source/blender/compositor/util/COM_UiConvert.h
#include "COM_Pixels.h"

namespace UiConvert {

PixelInterpolation pixelInterpolation(short ui_value);

};  // namespace UiConvert
=======
>>>>>>> upstream/compositor-up
#include "COM_TransformOperation.h"

class Stabilize2dOperation : public TransformOperation {
 public:
  Stabilize2dOperation();

 protected:
  virtual void hashParams() override;
};
<<<<<<< HEAD
=======
>>>>>>> upstream/compositor-up:source/blender/compositor/operations/distort/COM_Stabilize2dOperation.h
>>>>>>> upstream/compositor-up
