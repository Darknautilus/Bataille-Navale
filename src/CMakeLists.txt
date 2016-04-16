add_subdirectory (ctrl)
add_subdirectory (model)
add_subdirectory (test)
add_subdirectory (view)

set(CMAKE_EXECUTABLE_SUFFIX ".html")
add_executable(BatailleNavale ${SOURCEFILES})

target_link_libraries(BatailleNavale
    ${SDL_LIBRARY}
    ${SDL_IMAGE_LIBRARY}
    ${SDL_TTF_LIBRARY}
)
