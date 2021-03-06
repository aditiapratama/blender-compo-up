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
 */

#ifndef __BPY_RNA_CALLBACK_H__
#define __BPY_RNA_CALLBACK_H__

/** \file
 * \ingroup pythonintern
 */

struct BPy_StructRNA;
struct PyObject;

#ifdef __cplusplus
extern "C" {
#endif

#if 0
PyObject *pyrna_callback_add(BPy_StructRNA *self, PyObject *args);
PyObject *pyrna_callback_remove(BPy_StructRNA *self, PyObject *args);
#endif

PyObject *pyrna_callback_classmethod_add(PyObject *cls, PyObject *args);
PyObject *pyrna_callback_classmethod_remove(PyObject *cls, PyObject *args);

#ifdef __cplusplus
}
#endif

#endif /* __BPY_RNA_CALLBACK_H__ */
