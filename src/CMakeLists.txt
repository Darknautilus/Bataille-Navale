add_subdirectory (ctrl)
add_subdirectory (model)
add_subdirectory (test)
add_subdirectory (view)

add_executable(BatailleNavale ${SOURCEFILES})

Find_Package(SDL REQUIRED)
Find_Package(SDL_image REQUIRED)
Find_Package(SDL_ttf REQUIRED)

target_link_libraries(BatailleNavale
    ${SDL_LIBRARY}
    ${SDL_IMAGE_LIBRARY}
    ${SDL_TTF_LIBRARY}
    SDLmain
)
