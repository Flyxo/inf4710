#####################
## cmake config below
cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE INTERNAL "")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_BINARY_DIR}/bin")
endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)
if(WIN32)
    list(APPEND CMAKE_PREFIX_PATH
        "$ENV{USER_DEVELOP}/opencv/build/install"
        "${CMAKE_SOURCE_DIR}/external/opencv"
    )
endif()
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE INTERNAL "")
set(DATA_ROOT_PATH "${CMAKE_SOURCE_DIR}/data" CACHE INTERNAL "")

########################
## solution config below
project(INF4710_TP3)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS $<$<CONFIG:Debug>:DEBUG>)
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS $<$<CONFIG:Debug>:_DEBUG>)
find_package(OpenCV 3.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})
mark_as_advanced(OPENCV_FOUND OpenCV_FOUND OpenCV_DIR)
if((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
    add_definitions(-march=native)
    add_definitions(-Wall)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif("x${CMAKE_CXX_COMPILER_ID}" STREQUAL "xMSVC")
    if((MSVC_VERSION GREATER 1899) AND (CMAKE_SIZEOF_VOID_P EQUAL 8) AND ("${OpenCV_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}/external/opencv"))
        file(GLOB OpenCV_DEBUG_DLLS "${CMAKE_SOURCE_DIR}/external/opencv/x64/vc15/bin/*330d.dll")
        list(APPEND OpenCV_DEBUG_DLLS "${CMAKE_SOURCE_DIR}/external/opencv/x64/vc15/bin/opencv_ffmpeg330_64.dll")
        file(COPY ${OpenCV_DEBUG_DLLS} DESTINATION "${CMAKE_BINARY_DIR}/bin/")
        file(GLOB OpenCV_RELEASE_DLLS "${CMAKE_SOURCE_DIR}/external/opencv/x64/vc15/bin/*330.dll")
        list(APPEND OpenCV_RELEASE_DLLS "${CMAKE_SOURCE_DIR}/external/opencv/x64/vc15/bin/opencv_ffmpeg330_64.dll")
        file(COPY ${OpenCV_RELEASE_DLLS} DESTINATION "${CMAKE_BINARY_DIR}/bin/")
    endif()
    add_definitions(-DUNICODE -D_UNICODE)
    add_definitions(-D_SCL_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(/openmp)
    add_definitions(/arch:AVX)
    add_definitions(/W4)
endif()
include_directories(
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_BINARY_DIR}/include"
)

#############################
## TP3 projects configs below
include_directories("include")
configure_file(
    "${CMAKE_SOURCE_DIR}/include/defines.hpp.conf"
    "${CMAKE_BINARY_DIR}/include/defines.hpp"
)
add_library(tp3_lib STATIC
    "src/calcCarteForce.cpp"
    "src/lireVideo.cpp"
    "src/calcConvo.cpp"
    "src/calcArete.cpp"
    "src/calcRatio.cpp"
    "include/common.hpp"
    "include/defines.hpp"
)
target_link_libraries(tp3_lib ${OpenCV_LIBRARIES})
add_executable(main "src/main.cpp")
target_link_libraries(main tp3_lib)
