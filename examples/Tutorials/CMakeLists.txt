cmake_minimum_required(VERSION 2.8)

project(tutorial_1)

include(FindPkgConfig)
find_package(PkgConfig)
	pkg_check_modules(GSTREAMER QUIET gstreamer-1.0)
#    pkg_check_modules(GST_APP REQUIRED gstreamer-app-1.0)

## set c++11 编译选项
# -std=c++11 包含C++11特性
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#INCLUDE for c/C++ include
include_directories(
    /usr/include/gstreamer-1.0
    /usr/lib/${CMAKE_SYSTEM_PROCESSOR}-linux-gnu/gstreamer-1.0/include
    /usr/include/glib-2.0
    /usr/include/libxml2 
    /usr/lib/${CMAKE_SYSTEM_PROCESSOR}-linux-gnu/glib-2.0/include
)

add_executable(tutorial_1  ${CMAKE_CURRENT_SOURCE_DIR}/basic_tutorial-1.c)

target_link_libraries(tutorial_1 ${GSTREAMER_LIBRARIES})