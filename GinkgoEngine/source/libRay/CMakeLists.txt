# ***** BEGIN GPL LICENSE BLOCK *****
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
#
# ***** END GPL LICENSE BLOCK *****

set(INC
  .
  ../libMath
)

set(INC_SYS

)

set(SRC
Aabb.cpp
Aabb.h
BinaryTree.h
Base64.h
BVH.h
Capsule.h
drand48.cpp
drand48.h
Graph.h
Hash.h
Heap.h
List.h
Map.h
Material.cpp
Material.h
noise.cpp
noise.h
Plane.cpp
Plane.h
Ray.cpp
Ray.h
RayCamera.cpp
RayCamera.h
RayTexture.cpp
RayTexture.h
RayTrace.cpp
RayTrace.h
Rect.cpp
Rect.h
Sphere.cpp
Sphere.h
Stack.h
Triangle.h
)

set(LIB
  libMath
)

# Disabled for makesdna/makesrna.
add_definitions(-DWITH_CLOG_PTHREADS)

GE_lib__impl(libRay "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
