# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.10)

# 银杏Engine
# 项目信息 版本信息
project (GinkgoEngine VERSION 1.0)

# 版本信息配置头文件
configure_file(GinkgoEngineConfig.h.in GinkgoEngineConfig.h)

# 设置源代码路径
set(GE_SOURCE_PATH ${PROJECT_SOURCE_DIR}/source)
# set(GE_SYSTEM_PATH ${PROJECT_SOURCE_DIR}/sys)

# 声明C++ 11 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加目录
add_subdirectory(source)




