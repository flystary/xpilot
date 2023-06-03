

####
cmake_minimum_required(VERSION 2.8)

PROJECT(xpilot)


message("PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
message("PROJECT_BINARY_DIR " ${PROJECT_BINARY_DIR})
message("PROJECT_NAME: " ${PROJECT_NAME})

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)
message("VERSION: " ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

string(TIMESTAMP INDENTED_BUILD_TIMESTAMP "%Y-%m-%d %H:%M:%S")
message("INDENTED_BUILD_TIMESTAMP: " ${INDENTED_BUILD_TIMESTAMP})

string(TIMESTAMP COMPACT_BUILD_TIMESTAMP "%Y%m%d")
message("COMPACT_BUILD_TIMESTAMP: " ${COMPACT_BUILD_TIMESTAMP})

configure_file(
    ${PROJECT_SOURCE_DIR}/include/config.h.in
    ${PROJECT_SOURCE_DIR}/include/config.h
)


INCLUDE_DIRECTORIES(include)

link_directories(/usr/lib)
link_directories(/usr/lib64)
link_directories(/usr/local/lib)
link_directories(/usr/local/lib64)

AUX_SOURCE_DIRECTORY(src DIR_SRCS)
AUX_SOURCE_DIRECTORY(src/config DIR_SRCS)

set(CMAKE_CXX_FLAGS -g)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ${DIR_SRCS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
        )
