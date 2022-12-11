cmake_minimum_required(VERSION 3.1)
project(imgui)

set(imgui_FILES
    imgui.h
    imgui.cpp
    imconfig.h
    imgui_demo.cpp
    imgui_draw.cpp
    imgui_internal.h
    imgui_tables.cpp
    imgui_widgets.cpp
    imstb_rectpack.h
    imstb_textedit.h
    imstb_truetype.h
    backends/imgui_impl_glfw.h
    backends/imgui_impl_glfw.cpp
    backends/imgui_impl_opengl3.h
    backends/imgui_impl_opengl3.cpp

)

add_library(imgui
    ${imgui_FILES}
)

target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/backends)
