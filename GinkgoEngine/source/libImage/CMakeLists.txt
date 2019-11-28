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
${GE_SOURCE_PATH}/
${GE_SOURCE_PATH}/libMath/
)

set(INC_SYS
# ${GE_SYSTEM_PATH}
)

set(GE_SRC
  libImage.cpp
  libImage.h
  stb/stb_image.cpp
  stb/stb_image.h
  stb/stb_image_write.h
  stb/stb_image_resize.h
)

set(GE_LIB
  libMath
)

add_library(libImage ${GE_SRC})

target_link_libraries(libImage PUBLIC ${GE_LIB})

target_include_directories(libImage PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${GE_INC}"
                           )

set(GE_SRC_INC
${GE_SOURCE_PATH}/libImage/libImage.h
${GE_SOURCE_PATH}/libImage/stb/stb_image.h
${GE_SOURCE_PATH}/libImage/stb/stb_image_write.h
${GE_SOURCE_PATH}/libImage/stb/stb_image_resize.h
)

# 设置INSTALL操作的目标文件夹和目标文件移动
install(TARGETS libImage DESTINATION lib)
install(FILES ${GE_SRC_INC}
        DESTINATION include/libImage)
