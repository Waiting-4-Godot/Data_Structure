CMAKE_MINIMUM_REQUIRED( VERSION 3.23)

project( doublyLinkedListWithHeader )

set( CMAKE_CXX_STANDARD 14 )

aux_source_directory( . SRC_LIST )

add_executable( ${PROJECT_NAME} ${SRC_LIST} )