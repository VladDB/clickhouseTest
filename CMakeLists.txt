cmake_minimum_required(VERSION 3.0.0)
project(clickhouseTest VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        main.cpp 
        testModel.h testModel.cpp
        dbService.h dbService.cpp)

# ImGUI
set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/contribs/imgui")

set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp

    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp)

# ClickHouse
add_subdirectory(contribs/clickhouse-cpp)

add_executable(clickhouseTest ${SOURCES} ${IMGUI_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE contribs/clickhouse-cpp/  
                                                                                                 contribs/clickhouse-cpp/contrib/absl  
                                                                                                 contribs/imgui
                                                                                                 contribs/imgui/backends)

target_link_libraries(${PROJECT_NAME} PRIVATE clickhouse-cpp-lib glfw OpenGL pthread ${CMAKE_DL_LIBS} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
