message(STATUS "  🔨 Linking Opencv")

if (WIN32)
    find_package(OpenCV REQUIRED)
endif ()

if (UNIX)
    set(CUDAToolkit_ROOT "/opt/cuda")
    find_package(OpenCV REQUIRED)
endif ()

target_include_directories(LibGame
        PUBLIC
        ${OpenCV_INCLUDE_DIRS}
)