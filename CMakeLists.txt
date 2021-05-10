aux_source_directory(src TIME_SRCS)
add_library(time_counter SHARED ${TIME_SRCS})

include(GenerateExportHeader)
GENERATE_EXPORT_HEADER(time_counter)

aux_source_directory(. SRCS)

target_link_libraries(time_counter)
target_include_directories(time_counter
    PUBLIC include ${CMAKE_CURRENT_BINARY_DIR}
    PRIVATE src)
add_executable(main ${SRCS})