add_library(utils INTERFACE)
target_sources(utils INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/top.h
    ${CMAKE_CURRENT_SOURCE_DIR}/fmap.h
    ${CMAKE_CURRENT_SOURCE_DIR}/undefined.h
    ${CMAKE_CURRENT_SOURCE_DIR}/string.h
)
