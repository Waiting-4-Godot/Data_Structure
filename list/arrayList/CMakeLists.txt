
project(arrayList)
aux_source_directory(. SRC_LIST)
message(${SRC_LIST})
add_executable(${PROJECT_NAME} ${SRC_LIST})