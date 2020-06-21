cmake_minimum_required (VERSION 3.15)

project (google-drive-synch-project)

if (NOT BOOST_ROOT)
    set (ENV{BOOST_ROOT} "/home/alex/alex/code/other/boost_1_73_0/builddir")
endif ()

find_package (Boost 1.73 REQUIRED)
message (STATUS "Boost found: ${Boost_FOUND}")

set (DEPS_DIR "${CMAKE_CURRENT_BINARY_DIR}/dependencies")

# ExternalProject_Add (curl-ep
#     PREFIX ${DEPS_DIR}/curl
#     URL https://curl.haxx.se/download/curl-7.70.0.tar.gz
#     URL_HASH MD5=f8959fd025cfbbf0a67bbcf7a9e77bf7
#     CMAKE_ARGS -DBUILD_TESTING=OFF -DBUILD_SHARED_LIBS=OFF
#         -DBUILD_CURL_EXE=ON
#         -DCMAKE_USE_OPENSSL=ON ${CMAKE_PARAMETERS}
# )

include_directories (
    "${CMAKE_SOURCE_DIR}/include"
    ${Boost_INCLUDE_DIRS}
)

link_directories (
    "${CMAKE_SOURCE_DIR}/lib"
)

set (CMAKE_VERBOSE_MAKEFILE ON)

add_compile_options (-Wall -Wextra -pthread)

set (CMAKE_CXX_FLAGS_DEBUG "-g -ggdb -O0")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")



add_subdirectory (src)