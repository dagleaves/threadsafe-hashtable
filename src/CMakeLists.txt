set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SOURCES mapper.cpp LinkedList.cpp Bucket.cpp HashTable.cpp)

add_library(libtest STATIC
    ${SOURCES}
)

target_include_directories(libtest PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(mapper ${SOURCES} ${HEADERS})

target_link_libraries(mapper Threads::Threads)

install(TARGETS mapper DESTINATION bin)

