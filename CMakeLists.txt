cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0074 NEW)

project(LibGame VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(OpenCV-LibGame)
include(JSON-LibGame)

add_library(${PROJECT_NAME} STATIC

        include/LibGame/io/Screenshot.hpp
        include/LibGame/io/Clipboard.hpp
        include/LibGame/io/Keyboard.hpp
        include/LibGame/io/Mouse.hpp

        include/LibGame/detect/DArgs.hpp
        include/LibGame/detect/Detector.hpp
        include/LibGame/detect/DResult.hpp

        include/LibGame/asset/Assets.hpp
        include/LibGame/asset/AssetCache.hpp

        include/LibGame/Interactions.hpp
        include/LibGame/LibGame.hpp

        include/LibGame/statuses/primary/IdlePrimaryStatus.hpp
        include/LibGame/statuses/primary/SlowDanceStatus.hpp
        include/LibGame/statuses/primary/DanceStatus.hpp
        include/LibGame/statuses/primary/ActionStatus.hpp

        include/LibGame/statuses/secondary/MovementSpeedSecondaryStatus.hpp
        include/LibGame/statuses/secondary/StraponSecondaryStatus.hpp
        include/LibGame/statuses/secondary/PartnerSecondaryStatus.hpp
        include/LibGame/statuses/secondary/NakedSecondaryStatus.hpp


        include/LibGame/module/ImageReader.hpp
        include/LibGame/module/Moderation.hpp
        include/LibGame/module/SexActions.hpp
        include/LibGame/module/BaseModule.hpp
        include/LibGame/module/Slowdance.hpp
        include/LibGame/module/Interface.hpp
        include/LibGame/module/Clothing.hpp
        include/LibGame/module/Movement.hpp
        include/LibGame/module/Friends.hpp
        include/LibGame/module/Context.hpp
        include/LibGame/module/Strapon.hpp
        include/LibGame/module/Profile.hpp
        include/LibGame/module/Actions.hpp
        include/LibGame/module/Dances.hpp
        include/LibGame/module/Camera.hpp
        include/LibGame/module/Chat.hpp
        include/LibGame/module/Idle.hpp
        include/LibGame/module/Item.hpp
        include/LibGame/module/Gift.hpp

        include/LibGame/misc/KvStore.hpp
        include/LibGame/misc/Point.hpp

        include/LibGame/state/BaseState.hpp
        include/LibGame/state/JsonFile.hpp

        src/modules/ImageReader.cpp
        src/modules/Moderation.cpp
        src/modules/SexActions.cpp
        src/modules/Slowdance.cpp
        src/modules/Interface.cpp
        src/modules/Movement.cpp
        src/modules/Clothing.cpp
        src/modules/Profile.cpp
        src/modules/Actions.cpp
        src/modules/Context.cpp
        src/modules/Strapon.cpp
        src/modules/Friends.cpp
        src/modules/Dances.cpp
        src/modules/Camera.cpp
        src/modules/Chat.cpp
        src/modules/Idle.cpp
        src/modules/Item.cpp
        src/modules/Gift.cpp

        src/detect/Detector.cpp

        src/asset/AssetCache.cpp
        src/asset/Assets.cpp

        src/statuses/primary/IdlePrimaryStatus.cpp
        src/statuses/primary/SlowDanceStatus.cpp
        src/statuses/primary/ActionStatus.cpp
        src/statuses/primary/DanceStatus.cpp

        src/statuses/secondary/MovementSpeedSecondaryStatus.cpp
        src/statuses/secondary/StraponSecondaryStatus.cpp
        src/statuses/secondary/PartnerSecondaryStatus.cpp
        src/statuses/secondary/NakedSecondaryStatus.cpp


        src/state/JsonFile.cpp

        src/io/Screenshot.cpp
        src/io/Clipboard.cpp
        src/io/Keyboard.cpp
        src/io/Mouse.cpp

        src/Interactions.cpp
        src/main.cpp


)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        ${OpenCV_INCLUDE_DIRS}
)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_WINDOWS)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_LINUX)
endif()


if (SPARKLE_SUPERBUILD)
    message(STATUS "❤️  ${PROJECT_NAME} USING Superbuild")

    target_link_libraries(LibGame PUBLIC LibScreenshots)
    target_link_libraries(LibGame PUBLIC LibGraphics)
    target_link_libraries(LibGame PUBLIC LibIO)
    target_link_libraries(LibGame PUBLIC LibOS)


else()

    include(LibGraphics-LibGame)
    include(LibScreenshots-LibGame)
    include(LibIO-LibGame)
    include(LibOS-LibGame)

    find_package(LibGraphics REQUIRED)

    target_link_libraries(LibScreenshots
            PRIVATE
            LibIO::LibIO
            LibOS::LibOS
            LibScreenshots::LibScreenshots
            LibGraphics::LibGraphics
    )
endif()

target_link_libraries(LibGame
        PRIVATE
            nlohmann_json::nlohmann_json
            opencv_core
            opencv_imgproc
            opencv_highgui
            opencv_imgcodecs
            opencv_videoio
            opencv_calib3d
)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT ${PROJECT_NAME}Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/LibGameConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/LibGameConfig.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/LibGameConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/LibGameConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/LibGameConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)