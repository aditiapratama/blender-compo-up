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
 * Copyright 2011, Blender Foundation.
 */

#include "BLI_threads.h"

#include "BLT_translation.h"

#include "BKE_node.h"
#include "BKE_scene.h"

#include "COM_BufferManager.h"
#include "COM_ComputeNoneManager.h"
#include "COM_Debug.h"
#include "COM_ExecutionSystem.h"
#include "COM_GlobalManager.h"
#include "COM_WorkScheduler.h"
#include "COM_compositor.h"
#include "clew.h"
#include <boost/lexical_cast.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>  // streaming operators etc.

static ThreadMutex s_compositorMutex;
static bool is_compositorMutex_init = false;
static boost::uuids::random_generator uuid_generator;

<<<<<<< HEAD
void COM_execute(struct Main *main,
                 struct Depsgraph *depsgraph,
                 RenderData *rd,
                 Scene *scene,
                 ViewLayer *view_layer,
                 bNodeTree *editingtree,
                 int rendering,
                 const ColorManagedViewSettings *viewSettings,
                 const ColorManagedDisplaySettings *displaySettings,
                 const char *viewName)
=======
static void assureGlobalMan()
{
  if (!GlobalMan) {
    GlobalMan.reset(new GlobalManager());
  }
}

void COM_execute(CompositTreeExec *exec_data)
>>>>>>> upstream/compositor-up
{
  /* initialize mutex, TODO this mutex init is actually not thread safe and
   * should be done somewhere as part of blender startup, all the other
   * initializations can be done lazily */
  if (is_compositorMutex_init == false) {
    BLI_mutex_init(&s_compositorMutex);
    is_compositorMutex_init = true;
  }

  BLI_mutex_lock(&s_compositorMutex);

<<<<<<< HEAD
  if (editingtree->test_break && editingtree->test_break(editingtree->tbh)) {
=======
  if (exec_data->ntree->test_break && exec_data->ntree->test_break(exec_data->ntree->tbh)) {
>>>>>>> upstream/compositor-up
    // during editing multiple calls to this method can be triggered.
    // make sure one the last one will be doing the work.
    BLI_mutex_unlock(&s_compositorMutex);
    return;
  }

<<<<<<< HEAD
  if (!GlobalMan) {
    GlobalMan.reset(new GlobalManager());
  }

  DebugInfo::start_benchmark();

  /* build context */
  const std::string execution_id = boost::lexical_cast<std::string>(uuid_generator());
  CompositorContext context = CompositorContext::build(execution_id,
                                                       main,
                                                       depsgraph,
                                                       rd,
                                                       scene,
                                                       view_layer,
                                                       editingtree,
                                                       rendering,
                                                       viewSettings,
                                                       displaySettings,
                                                       viewName);
=======
  assureGlobalMan();

  DebugInfo::start_benchmark();

  /* build context */
  const std::string execution_id = boost::lexical_cast<std::string>(uuid_generator());
  CompositorContext context = CompositorContext::build(execution_id, exec_data);
>>>>>>> upstream/compositor-up
#if COM_CURRENT_THREADING_MODEL == COM_TM_NOTHREAD
  int m_cpu_work_threads = 1;
#else
  int m_cpu_work_threads = BLI_system_thread_count();
#endif
  context.setNCpuWorkThreads(m_cpu_work_threads);

  /* set progress bar to 0% and status to init compositing */
<<<<<<< HEAD
  editingtree->progress(editingtree->prh, 0.0);
  editingtree->stats_draw(editingtree->sdh, IFACE_("Compositing"));
=======
  exec_data->ntree->progress(exec_data->ntree->prh, 0.0);
  exec_data->ntree->stats_draw(exec_data->ntree->sdh, IFACE_("Compositing"));
>>>>>>> upstream/compositor-up

  GlobalMan->initialize(context);

  ExecutionSystem *system = new ExecutionSystem(context);

  system->execute();

  GlobalMan->deinitialize(context);
  delete system;

  DebugInfo::end_benchmark();

  DebugInfo::clear();

  BLI_mutex_unlock(&s_compositorMutex);
}

void COM_deinitialize()
{
<<<<<<< HEAD
  delete GlobalMan.get();
  GlobalMan.release();
=======
  if (GlobalMan) {
    delete GlobalMan.get();
    GlobalMan.release();
  }
>>>>>>> upstream/compositor-up
  if (is_compositorMutex_init) {
    BLI_mutex_lock(&s_compositorMutex);
    WorkScheduler::deinitialize();
    is_compositorMutex_init = false;
    BLI_mutex_unlock(&s_compositorMutex);
    BLI_mutex_end(&s_compositorMutex);
  }
}
