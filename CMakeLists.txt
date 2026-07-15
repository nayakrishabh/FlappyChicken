cmake_minimum_required(VERSION 3.16)
project(FlappyChicken VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Workaround for clang-cl + SDL2 _m_prefetch builtin conflict
add_compile_definitions(__PRFCHWINTRIN_H=1)

# ── SDL2 (core) ──────────────────────────────────────────────
set(SDL2_ROOT "G:/Projects/C++(SDL & OpenGL) Projects/vclib")
set(SDL2_INCLUDE_DIR "${SDL2_ROOT}/include")
set(SDL2_LIBRARY     "${SDL2_ROOT}/lib/x64/SDL2.lib")
set(SDL2MAIN_LIBRARY "${SDL2_ROOT}/lib/x64/SDL2main.lib")

# ── SDL2_image ────────────────────────────────────────────────
set(SDL2_IMAGE_ROOT "G:/Projects/C++(SDL & OpenGL) Projects/ResourceZips/SDL2_image-devel-2.8.8-VC/SDL2_image-2.8.8")
set(SDL2_IMAGE_INCLUDE_DIR "${SDL2_IMAGE_ROOT}/include")
set(SDL2_IMAGE_LIBRARY     "${SDL2_IMAGE_ROOT}/lib/x64/SDL2_image.lib")

# ── Source files ─────────────────────────────────────────────
set(SOURCES
    FlappyChicken.cpp
    PlayerChick.cpp
)

set(HEADERS
    PlayerChicken.h
)

# ── Executable ───────────────────────────────────────────────
add_executable(FlappyChicken ${SOURCES} ${HEADERS})

target_include_directories(FlappyChicken PRIVATE
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
)

target_link_libraries(FlappyChicken PRIVATE
    ${SDL2_LIBRARY}
    ${SDL2MAIN_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
)

# ── Copy runtime DLLs post-build ─────────────────────────────
# SDL2 core DLL
add_custom_command(TARGET FlappyChicken POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_ROOT}/lib/x64/SDL2.dll"
        "$<TARGET_FILE_DIR:FlappyChicken>/SDL2.dll"
    COMMENT "Copying SDL2.dll"
)

# SDL2_image DLL + its transitive dependencies
set(SDL2_IMAGE_DLL_DIR "${SDL2_IMAGE_ROOT}/lib/x64")
foreach(_dll SDL2_image.dll libavif-16.dll libtiff-5.dll libwebp-7.dll libwebpdemux-2.dll)
    add_custom_command(TARGET FlappyChicken POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SDL2_IMAGE_DLL_DIR}/${_dll}"
            "$<TARGET_FILE_DIR:FlappyChicken>/${_dll}"
        COMMENT "Copying ${_dll}"
    )
endforeach()
