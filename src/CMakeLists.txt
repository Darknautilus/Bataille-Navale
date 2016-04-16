add_subdirectory (ctrl)
add_subdirectory (model)
add_subdirectory (test)
add_subdirectory (view)

add_executable(BatailleNavale ${SOURCEFILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf)

target_link_libraries(BatailleNavale
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${SDL2TTF_LIBRARIES}
)
