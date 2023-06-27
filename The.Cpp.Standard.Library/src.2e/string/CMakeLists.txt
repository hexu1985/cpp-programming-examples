aux_source_directory(. SRC_FILE_LIST)

get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME_WE)

foreach(SRC_FILE ${SRC_FILE_LIST})
    get_filename_component(EXE_FILE ${SRC_FILE} NAME_WE)
    add_executable(${DIR_NAME}_${EXE_FILE} ${SRC_FILE})
    target_link_libraries(${DIR_NAME}_${EXE_FILE} ${LIBS_SYSTEM})
endforeach()
