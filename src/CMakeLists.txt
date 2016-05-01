add_subdirectory (ctrl)
add_subdirectory (model)
add_subdirectory (test)
add_subdirectory (view)

add_executable(BatailleNavale ${SOURCEFILES})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})

target_link_libraries(BatailleNavale
    ${SDL2MAIN_LIBRARY}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
)
