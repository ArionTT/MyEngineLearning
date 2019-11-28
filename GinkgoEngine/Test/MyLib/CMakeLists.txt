


add_library(MyLib mysqrt.cxx)

# 设置INSTALL操作的目标文件夹和目标文件移动
install(TARGETS MyLib DESTINATION lib)
install(FILES mysqrt.h DESTINATION include)

# 这里声明当前库的引用包含目录为 INTERFACE模式则表示当前库是一个接口引用，
# 对外暴露，外部引用库是不需要添加include路径
# target_include_directories(MyLib
#           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
#           )