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

class CombineColorNode : public Node {
 public:
  CombineColorNode(bNode *editorNode);
  void convertToOperations(NodeConverter &converter, CompositorContext &context) const;

 protected:
  virtual NodeOperation *getColorConverter(CompositorContext &context) const = 0;
};

class CombineRGBANode : public CombineColorNode {
 public:
  CombineRGBANode(bNode *editorNode) : CombineColorNode(editorNode)
  {
  }

  NodeOperation *getColorConverter(CompositorContext &context) const;
};

class CombineHSVANode : public CombineColorNode {
 public:
  CombineHSVANode(bNode *editorNode) : CombineColorNode(editorNode)
  {
  }

  NodeOperation *getColorConverter(CompositorContext &context) const;
};

class CombineYCCANode : public CombineColorNode {
 public:
  CombineYCCANode(bNode *editorNode) : CombineColorNode(editorNode)
  {
  }

  NodeOperation *getColorConverter(CompositorContext &context) const;
};

class CombineYUVANode : public CombineColorNode {
 public:
  CombineYUVANode(bNode *editorNode) : CombineColorNode(editorNode)
  {
  }

  NodeOperation *getColorConverter(CompositorContext &context) const;
};
