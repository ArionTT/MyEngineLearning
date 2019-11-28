
set(GE_INC
${GE_SOURCE_PATH}/libMath
)

set(I_SYS
${GE_SYSTEM_PATH}
)

set(GE_SRC
  Color.cpp
  Color.h
  Config.h
  Curve.h
  Math.cpp
  Math.h
  Matrix4x4.cpp
  Matrix4x4.h
  #Octree.h
  Quaternion.cpp
  Quaternion.h
  stdhead.h
  Vector.cpp
  Vector.h
  String.h
)

set(GE_LIB

)

add_library(libMath ${GE_SRC})

# target_link_libraries(libMath PUBLIC ${GE_LIB})

target_include_directories(libMath PUBLIC
                           "${PROJECT_BINARY_DIR}"
                          #  "${GE_INC}"
                           )

set(GE_SRC_INC
${GE_SOURCE_PATH}/libMath/Color.h
${GE_SOURCE_PATH}/libMath/Config.h
${GE_SOURCE_PATH}/libMath/Curve.h
${GE_SOURCE_PATH}/libMath/Math.h
${GE_SOURCE_PATH}/libMath/Matrix4x4.h
${GE_SOURCE_PATH}/libMath/Quaternion.h
${GE_SOURCE_PATH}/libMath/stdhead.h
${GE_SOURCE_PATH}/libMath/Vector.h
${GE_SOURCE_PATH}/libMath/String.h
)

# 设置INSTALL操作的目标文件夹和目标文件移动
install(TARGETS libMath DESTINATION lib)
install(FILES ${GE_SRC_INC}
        DESTINATION include/libMath)

