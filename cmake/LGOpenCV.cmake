function(debug_target TARGET_NAME)
    message(STATUS "===== Debugging target: ${TARGET_NAME} =====")

    get_target_property(INC ${TARGET_NAME} INTERFACE_INCLUDE_DIRECTORIES)
    message(STATUS "Include dirs: ${INC}")

    get_target_property(LIBS ${TARGET_NAME} INTERFACE_LINK_LIBRARIES)
    message(STATUS "Link libs: ${LIBS}")

    get_target_property(DEFS ${TARGET_NAME} INTERFACE_COMPILE_DEFINITIONS)
    message(STATUS "Compile defs: ${DEFS}")

    get_target_property(LOC ${TARGET_NAME} IMPORTED_LOCATION)
    message(STATUS "Library file: ${LOC}")

    get_target_property(LOCS ${TARGET_NAME} IMPORTED_LOCATION_RELEASE)
    message(STATUS "Library file (Release): ${LOCS}")

    get_target_property(LOCD ${TARGET_NAME} IMPORTED_LOCATION_DEBUG)
    message(STATUS "Library file (Debug): ${LOCD}")

    message(STATUS "===== End debug for: ${TARGET_NAME} =====")
endfunction()

message(STATUS "===== BLEEP 1 =====")
if(CMAKE_TOOLCHAIN_FILE MATCHES "vcpkg.cmake")
    find_package(OpenCV CONFIG REQUIRED)
endif()

message(STATUS "===== BLEEP 2 =====")
if(WIN32)
    set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")
    find_package(OpenCV REQUIRED)
endif()

message(STATUS "===== BLEEP 3 =====")
if(UNIX)
    set(CUDAToolkit_ROOT "/opt/cuda")
    find_package(OpenCV REQUIRED)
endif()

message(STATUS "===== BLEEP 4 =====")
target_include_directories(LibGame
        PRIVATE
        ${OpenCV_INCLUDE_DIRS}
)

message(STATUS "===== BLEEP 5 =====")
target_link_libraries(LibGame
        PRIVATE
        ${OpenCV_LIBRARIES}
)

#get_target_property(OPENCV_CORE_INCLUDES opencv_core INTERFACE_INCLUDE_DIRECTORIES)
#message(STATUS "LibGame@@@opencv_core include dirs = ${OpenCV_INCLUDE_DIRS}")

function(debug_all_opencv_targets)
    get_property(allTargets DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY BUILDSYSTEM_TARGETS)

    foreach(t ${allTargets})
        if(t MATCHES "^opencv_")
            debug_target(${t})
        endif()
    endforeach()
endfunction()