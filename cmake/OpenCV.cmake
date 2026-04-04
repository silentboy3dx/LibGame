if(CMAKE_TOOLCHAIN_FILE MATCHES "vcpkg.cmake")
    find_package(OpenCV CONFIG REQUIRED)
endif()

if(WIN32)
    set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")
    find_package(OpenCV REQUIRED)
endif()

if(UNIX)
    set(CUDAToolkit_ROOT "/opt/cuda")
    find_package(OpenCV REQUIRED)
endif()

target_include_directories(LibGame
        PRIVATE
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(LibGame
        PRIVATE
        ${OpenCV_LIBRARIES}
)

get_target_property(OPENCV_CORE_INCLUDES opencv_core INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "LibGame@@@opencv_core include dirs = ${OpenCV_INCLUDE_DIRS}")