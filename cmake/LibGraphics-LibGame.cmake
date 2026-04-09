message(STATUS "  🔨 Linking LibGraphics")

if (WIN32)
    list(APPEND CMAKE_PREFIX_PATH "C:/Program Files/LibGraphics")
endif()

if(OpenCV_CUDA_VERSION)
    add_definitions(-DOPENCV_WITH_CUDA)
endif

find_package(LibGraphics REQUIRED) # FindUnreadMessages.cpp