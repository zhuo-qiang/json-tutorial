cmake_minimum_required (VERSION 2.6)
# 指明Cmake最低版本是 2.6

project (leptjson_test C)
# 声明项目名为 leptjson, 赋值给 PROJECT_NAME
# project (example_project C CXX) 可以定义为c/c++
# project (example_project VERSION 1.0.0) 还可以定义 PROJECT_VERSION
# 还有 PROJECT_VERSION_MAJOR、PROJECT_VERSION_MINOR和PROJECT_VERSION_PATCH等变量。


if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
# 检查编译器是否是GNU或者Clang, MATCH 支持正则表达式
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
    # 设置编译器标志(全局设置)
    # -ansi 编译器遵循 ansi 标准(ANSI C或C89标准, 也可以称为 ISO C, 是C语言第一个官方标准)
    # -pedantic 要求编译器报告所有标准违规 (强制编译器遵守ISO C和ISO C++的所有标准)
    # -Wall 开启编译器所有warning
    # 还可以加 -DEBUG 等等标志
endif()



add_library(leptjson leptjson.c)
# 定义一个 leptjson 的静态库, 它由 leptjson.c 文件构建
# add_library命令用于添加一个库到项目中，无论是静态库（默认情况下）还是动态库。

add_executable(leptjson_test test.c)
# 创建了一个名为leptjson_test的可执行文件，它由test.c源文件构建
# target_compile_definitions(myapp PRIVATE -DUSE_MYAPP) 可以添加宏定义

target_link_libraries(leptjson_test leptjson)
# 这行代码指示CMake将leptjson库链接到leptjson_test可执行文件。
# target_compile_options(myapp PRIVATE -Wall -O3) 还可以局部添加编译器标志


##############
# 使用方法
# cmake . -> 根据CMakeLists.txt文件在当前目录生成适合你系统的构建系统（例如Makefile）
# 如果生成的是Makefile，你只需运行make命令。

# 常用法是建一个 build 文件
# mkdir build
# cd build 
# cmake -DCMAKE_BUILD_TYPE=Debug .. (也可以指定Release)
# make  (执行makefile)