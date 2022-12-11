cmake_minimum_required(VERSION 3.16.3)

project(ItemViewer LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 17)

### set directories - begin ###
set(SRC_DIRECTORY               "${CMAKE_SOURCE_DIR}/src")
    set(ALGORITHMS_DIRECTORY        "${SRC_DIRECTORY}/algorithms")
    set(GRAPHICS_DIRECTORY          "${SRC_DIRECTORY}/graphics")
        set(GUI_DIRECTORY               "${GRAPHICS_DIRECTORY}/gui")
            set(GUI_ELEMENTS_DIRECTORY      "${GUI_DIRECTORY}/elements")
    set(IO_DIRECTORY                "${SRC_DIRECTORY}/io")
    set(WINDOW_DIRECTORY            "${SRC_DIRECTORY}/window")

set(THIRD_PARTY_DIRECTORY       "${CMAKE_SOURCE_DIR}/third_party")
### set directories - end ###

### add third party libraries - begin ###
### add glfw - begin ###
if (WIN32)
    find_package(OpenGL REQUIRED)
    
    include_directories(${OPENGL_INCLUDE_DIRS})
    
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
    set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")
    
    add_subdirectory(${THIRD_PARTY_DIRECTORY}/glfw)

    if (MSVC)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
    endif()

    include_directories(glfw PUBLIC ${THIRD_PARTY_DIRECTORY}/glfw/include/)
elseif (UNIX)
    find_package(OpenGL REQUIRED)
    include_directories(${OPENGL_INCLUDE_DIRS})

    find_package(glfw3 REQUIRED)
endif ()
### add glfw - end ###

### add glad - begin ###
if (WIN32)
    add_subdirectory(${THIRD_PARTY_DIRECTORY}/glad)
elseif (UNIX)
    add_subdirectory(${THIRD_PARTY_DIRECTORY}/glad)
endif()
### add glad - end ###

### add glm - begin ###
if (WIN32)
    add_subdirectory(${THIRD_PARTY_DIRECTORY}/glm)
    include_directories(${THIRD_PARTY_DIRECTORY}/glm)
elseif (UNIX)
    add_subdirectory(${THIRD_PARTY_DIRECTORY}/glm)
    include_directories(${THIRD_PARTY_DIRECTORY}/glm)
endif()
### add glm - end ###

### add imgui - begin ###
if (WIN32)
    add_subdirectory(${THIRD_PARTY_DIRECTORY}/imgui)
elseif (UNIX)
    add_subdirectory(${THIRD_PARTY_DIRECTORY}/imgui)
   endif()
### add imgui - end ###
### add third party libraries - end ###

set(SRC_FILES
    "${SRC_DIRECTORY}/main.cpp"
    "${SRC_DIRECTORY}/itemstudio.h"
    "${SRC_DIRECTORY}/itemstudio.cpp"
)

set(ALGORITHMS_FILES
    "${ALGORITHMS_DIRECTORY}/states.hpp"
)

set(GRAPHICS_FILES

)
    set(GUI_FILES
        "${GUI_DIRECTORY}/gui.h"
        "${GUI_DIRECTORY}/gui.cpp"
    )

        set(GUI_ELEMENTS_FILES
            "${GUI_ELEMENTS_DIRECTORY}/element.hpp"
            "${GUI_ELEMENTS_DIRECTORY}/line.hpp"
            
            "${GUI_ELEMENTS_DIRECTORY}/button.hpp"
            "${GUI_ELEMENTS_DIRECTORY}/checkbox.hpp"
            "${GUI_ELEMENTS_DIRECTORY}/radiobutton.hpp"
            "${GUI_ELEMENTS_DIRECTORY}/text.hpp"
        )

set(IO_FILES
    #"${IO_DIRECTORY}/camera.h"
    #"${IO_DIRECTORY}/camera.cpp"
    "${IO_DIRECTORY}/keyboard.h"
    "${IO_DIRECTORY}/keyboard.cpp"
    "${IO_DIRECTORY}/mouse.h"
    "${IO_DIRECTORY}/mouse.cpp"
)

set(WINDOW_FILES
    "${WINDOW_DIRECTORY}/window.h"
    "${WINDOW_DIRECTORY}/window.cpp"
    "${WINDOW_DIRECTORY}/windowmanager.h"
    "${WINDOW_DIRECTORY}/windowmanager.cpp"
)

include_directories(
    ${SRC_DIRECTORY}
        ${ALGORITHMS_DIRECTORY}
        ${GRAPHICS_DIRECTORY}
            ${GUI_DIRECTORY}
                ${GUI_ELEMENTS_DIRECTORY}
        ${IO_DIRECTORY}
        ${WINDOW_DIRECTORY}
)
     
add_executable(ItemViewer 
    ${SRC_FILES}
        ${ALGORITHMS_FILES}
        ${GRAPHICS_FILES}
            ${GUI_FILES}
                ${GUI_ELEMENTS_FILES}
        ${IO_FILES}
        ${WINDOW_FILES}
)

target_link_libraries(ItemViewer 
    ${OPENGL_LIBRARIES} 
    glfw 
    glad
    glm
    imgui
)
