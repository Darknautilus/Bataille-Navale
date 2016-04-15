add_subdirectory (model)
add_subdirectory (view)

set(SOURCEFILES
    ${SOURCEFILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Test.c
    PARENT_SCOPE
)
