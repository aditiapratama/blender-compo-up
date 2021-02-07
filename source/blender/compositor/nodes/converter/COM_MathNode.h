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

#pragma once

#include "COM_Node.h"

/**
 * \brief MathNode
 * \ingroup Node
 */
class MathNode : public Node {
 public:
  MathNode(bNode *editorNode) : Node(editorNode)
  {
  }
<<<<<<< HEAD:source/blender/compositor/nodes/converter/COM_MathNode.h
  void convertToOperations(NodeConverter &converter,
                           const CompositorContext &context) const override;
=======
  void convertToOperations(NodeConverter &converter, CompositorContext &context) const override;
>>>>>>> upstream/compositor-up:source/blender/compositor/nodes/COM_MathNode.h
};
