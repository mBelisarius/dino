# =========================================================
# dino

cmake_minimum_required(VERSION 3.26)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(ProjectName "dino")

project("${ProjectName}")

set(CMAKE_C_STANDARD 23)

add_compile_options(-Wall -Werror -Wno-error=uninitialized
        $<$<CONFIG:RELEASE>:-O3>
        $<$<CONFIG:RELEASE>:-DNDEBUG>
        $<$<CONFIG:RELWITHDEBINFO>:-O2>
        $<$<CONFIG:RELWITHDEBINFO>:-DNDEBUG>
        $<$<CONFIG:RELWITHDEBINFO>:-g>
        $<$<CONFIG:MINSIZEREL>:-Oz>
        $<$<CONFIG:MINSIZEREL>:-DNDEBUG>
        $<$<CONFIG:DEBUG>:-Og>
        $<$<CONFIG:DEBUG>:-g>
)

# =========================================================
# Targets

add_library("${ProjectName}" src/info.h)

file(GLOB EVENTS_SOURCES src/events/*.c)
file(GLOB EVENTS_HEADERS src/events/*.h)
add_library(events ${EVENTS_SOURCES} ${EVENTS_HEADERS})

file(GLOB GRAPHICS_SOURCES src/graphics/*.c)
file(GLOB GRAPHICS_HEADERS src/graphics/*.h)
add_library(graphics ${GRAPHICS_SOURCES} ${GRAPHICS_HEADERS})

file(GLOB SCORE_SOURCES src/score/*.c)
file(GLOB SCORE_HEADERS src/score/*.h)
add_library(score ${SCORE_SOURCES} ${SCORE_HEADERS})

file(GLOB UTILS_SOURCES src/utils/*.c)
file(GLOB UTILS_HEADERS src/utils/*.h)
add_library(utils ${UTILS_SOURCES} ${UTILS_HEADERS})

file(GLOB WORLDGEN_SOURCES src/worldgen/*.c)
file(GLOB WORLDGEN_HEADERS src/worldgen/*.h)
add_library(worldgen ${WORLDGEN_SOURCES} ${WORLDGEN_HEADERS})

target_link_libraries("${ProjectName}" PUBLIC
        events
        graphics
        score
        utils
        worldgen
)

target_include_directories("${ProjectName}" PUBLIC "${CMAKE_SOURCE_DIR}")

set_target_properties("${ProjectName}" PROPERTIES LINKER_LANGUAGE C)

# --- main

add_executable("${ProjectName}-main" src/main.c)
target_link_libraries("${ProjectName}-main" PUBLIC "${ProjectName}")

# =========================================================
