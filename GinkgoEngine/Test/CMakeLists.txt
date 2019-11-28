# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.10)

# 银杏Engine

# 项目信息 版本信息
project (GinkgoEngine VERSION 1.0)

# 配置一个USE_MATH 标志，用于控制是否添加MyLib
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# 版本信息配置头文件
configure_file(GinkgoEngineConfig.h.in GinkgoEngineConfig.h)

# 声明C++ 11 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行程序
add_executable(GinkgoEngine main.cxx)

if(USE_MYMATH)
  add_subdirectory(MyLib)
  list(APPEND EXTRA_LIBS MyLib)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MyLib")
endif()

# add_subdirectory(MyLib)
# target_link_libraries(GinkgoEngine PUBLIC MyLib)
# target_include_directories(GinkgoEngine PUBLIC 
#               "${PROJECT_BINARY_DIR}"
#               "${PROJECT_SOURCE_DIR}/MathFunctions"
#               )

# 添加目录MyLib
target_link_libraries(GinkgoEngine PUBLIC ${EXTRA_LIBS})
# 设置包含目录，第一个参数为 add_lib 或者add_exe的名字
# 第二个参数为 PUBLIC 或者 PRIVATE
# 添加二进制目录到包含，所以可以包含Config.h
target_include_directories(GinkgoEngine PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES})

# 设置INSTALL操作的目标文件夹和目标文件移动
install(TARGETS GinkgoEngine DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/GinkgoEngineConfig.h"
        DESTINATION include)


# 检测函数存在，如果存在声明 HAVE_XXX 宏在Config.h里
include(CheckSymbolExists)
set(CMAKE_REQUIRED_LIBRARIES "m")
check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)
if(HAVE_LOG AND HAVE_EXP)
  target_compile_definitions(MyLib PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()

# 设置编译标志，警告
# target_compile_options 比较万能
# 例如声明C++11版本
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)
# 可以用 target_compile_options 改为：
# add_library(tutorial_compiler_flags INTERFACE)
# target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(GinkgoEngine_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)
