# CMakeList.txt: designMode 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

set(BinName design)

set(CMAKE_INCLUE_CURRENT_DIR ON)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(GLOB_RECURSE SrcFiles "*.h" "*.cpp")

include_directories(. ${ShareHeaders} ${QtHeaders} ${thirdHeaders})


IF(CMAKE_BUILD_TYPE STREQUAL Debug)
    SET(BinName ${BinName}d)
ENDIF()

# 将源代码添加到此项目的可执行文件。
add_executable (${BinName} ${SrcFiles})

# TODO: 如有需要，请添加测试并安装目标。
