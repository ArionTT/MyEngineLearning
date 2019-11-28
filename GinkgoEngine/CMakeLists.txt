# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
# 银杏Engine
project (GinkgoEngine CXX)

# Nicer makefiles with -I/1/foo/ instead of -I/1/2/3/../../foo/
# use it instead of include_directories()
function(GE_include_dirs
  includes
  )

  set(_ALL_INCS "")
  foreach(_INC ${ARGV})
    get_filename_component(_ABS_INC ${_INC} ABSOLUTE)
    list(APPEND _ALL_INCS ${_ABS_INC})
    # for checking for invalid includes, disable for regular use
    ##if(NOT EXISTS "${_ABS_INC}/")
    ##  message(FATAL_ERROR "Include not found: ${_ABS_INC}/")
    ##endif()
  endforeach()
  include_directories(${_ALL_INCS})
endfunction()

function(GE_include_dirs_sys
  includes
  )

  set(_ALL_INCS "")
  foreach(_INC ${ARGV})
    get_filename_component(_ABS_INC ${_INC} ABSOLUTE)
    list(APPEND _ALL_INCS ${_ABS_INC})
    ##if(NOT EXISTS "${_ABS_INC}/")
    ##  message(FATAL_ERROR "Include not found: ${_ABS_INC}/")
    ##endif()
  endforeach()
  include_directories(SYSTEM ${_ALL_INCS})
endfunction()


function(GE_source_group
  sources
  )

  #if enabled, use the sources directories as filters.
  if(WINDOWS_USE_VISUAL_STUDIO_SOURCE_FOLDERS)
    foreach(_SRC ${sources})
      # remove ../'s
      get_filename_component(_SRC_DIR ${_SRC} REALPATH)
      get_filename_component(_SRC_DIR ${_SRC_DIR} DIRECTORY)
      string(FIND ${_SRC_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/" _pos)
      if(NOT _pos EQUAL -1)
        string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" GROUP_ID ${_SRC_DIR})
        string(REPLACE "/" "\\" GROUP_ID ${GROUP_ID})
        source_group("${GROUP_ID}" FILES ${_SRC})
      endif()
      unset(_pos)
    endforeach()
  else()
    # Group by location on disk
    source_group("Source Files" FILES CMakeLists.txt)
    foreach(_SRC ${sources})
      get_filename_component(_SRC_EXT ${_SRC} EXT)
      if((${_SRC_EXT} MATCHES ".h") OR
         (${_SRC_EXT} MATCHES ".hpp") OR
         (${_SRC_EXT} MATCHES ".hh"))

        set(GROUP_ID "Header Files")
      elseif(${_SRC_EXT} MATCHES ".glsl$")
        set(GROUP_ID "Shaders")
      else()
        set(GROUP_ID "Source Files")
      endif()
      source_group("${GROUP_ID}" FILES ${_SRC})
    endforeach()
  endif()
endfunction()


function(list_assert_duplicates
  list_id
  )

  # message(STATUS "list data: ${list_id}")

  list(LENGTH list_id _len_before)
  list(REMOVE_DUPLICATES list_id)
  list(LENGTH list_id _len_after)
  # message(STATUS "list size ${_len_before} -> ${_len_after}")
  if(NOT _len_before EQUAL _len_after)
    message(FATAL_ERROR "duplicate found in list which should not contain duplicates: ${list_id}")
  endif()
  unset(_len_before)
  unset(_len_after)
endfunction()


# only MSVC uses SOURCE_GROUP
function(GE_lib__impl
  name
  sources
  includes
  includes_sys
  library_deps
  )

  # message(STATUS "Configuring library ${name}")

  # include_directories(${includes})
  # include_directories(SYSTEM ${includes_sys})
  GE_include_dirs("${includes}")
  GE_include_dirs_sys("${includes_sys}")

  add_library(${name} ${sources})

  if(NOT "${library_deps}" STREQUAL "")
    target_link_libraries(${name} "${library_deps}")
  endif()

  # works fine without having the includes
  # listed is helpful for IDE's (QtCreator/MSVC)
  GE_source_group("${sources}")

  #if enabled, set the FOLDER property for visual studio projects
  if(WINDOWS_USE_VISUAL_STUDIO_PROJECT_FOLDERS)
    get_filename_component(FolderDir ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
    string(REPLACE ${CMAKE_SOURCE_DIR} "" FolderDir ${FolderDir})
    set_target_properties(${name} PROPERTIES FOLDER ${FolderDir})
  endif()

  list_assert_duplicates("${sources}")
  list_assert_duplicates("${includes}")
  # Not for system includes because they can resolve to the same path
  # list_assert_duplicates("${includes_sys}")

endfunction()


set(GLFW_DIR ${PROJECT_SOURCE_DIR}/3rdParty/glfw-3.3)
set(GLAD_DIR ${PROJECT_SOURCE_DIR}/3rdParty/GLAD)
set(GLM_DIR ${PROJECT_SOURCE_DIR}/3rdParty/glm)
set(STB_DIR ${PROJECT_SOURCE_DIR}/3rdParty/stb_img)
set(ASSIMP_DIR ${PROJECT_SOURCE_DIR}/3rdParty/assimp)
set(FREETYPE_DIR ${PROJECT_SOURCE_DIR}/3rdParty/freetype-2.9)

# 3rdparty
# add_subdirectory(3rdParty/glfw-3.3)
# add_subdirectory(3rdParty/assimp)
# add_subdirectory(3rdParty/freetype-2.9)

# main
add_subdirectory (source)
add_subdirectory (thirdparty)





