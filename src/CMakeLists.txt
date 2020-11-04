aux_source_directory(. SRC_LIST)
add_library(${PROJ} STATIC ${SRC_LIST})
target_include_directories(${PROJ} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
