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

set(GE_INC
${GE_SOURCE_PATH}
${GE_SOURCE_PATH}/libMath
)

set(INC_SYS
# ${GE_SYSTEM_PATH}
)

set(GE_SRC
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
Hitable.h
Hitable.cpp
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

set(GE_LIB
  libMath
)

add_library(libRay ${GE_SRC})

target_link_libraries(libRay PUBLIC ${GE_LIB})

target_include_directories(libRay PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${GE_INC}"
                           )

set(GE_SRC_INC
${GE_SOURCE_PATH}/libRay/Aabb.h
${GE_SOURCE_PATH}/libRay/Base64.h
${GE_SOURCE_PATH}/libRay/BinaryTree.h
${GE_SOURCE_PATH}/libRay/BVH.h
${GE_SOURCE_PATH}/libRay/Capsule.h
${GE_SOURCE_PATH}/libRay/drand48.h
${GE_SOURCE_PATH}/libRay/Graph.h
${GE_SOURCE_PATH}/libRay/Heap.h
${GE_SOURCE_PATH}/libRay/Hash.h
${GE_SOURCE_PATH}/libRay/Hitable.h
${GE_SOURCE_PATH}/libRay/List.h
${GE_SOURCE_PATH}/libRay/Map.h
${GE_SOURCE_PATH}/libRay/Material.h
${GE_SOURCE_PATH}/libRay/noise.h
${GE_SOURCE_PATH}/libRay/Plane.h
${GE_SOURCE_PATH}/libRay/Ray.h
${GE_SOURCE_PATH}/libRay/RayCamera.h
${GE_SOURCE_PATH}/libRay/RayTexture.h
${GE_SOURCE_PATH}/libRay/RayTrace.h
${GE_SOURCE_PATH}/libRay/Rect.h
${GE_SOURCE_PATH}/libRay/Sphere.h
${GE_SOURCE_PATH}/libRay/Stack.h
${GE_SOURCE_PATH}/libRay/Triangle.h
)

# 设置INSTALL操作的目标文件夹和目标文件移动
install(TARGETS libRay DESTINATION lib)
install(FILES ${GE_SRC_INC}
        DESTINATION include/libRay)
