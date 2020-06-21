add_executable (main main.cpp)

target_include_directories (main PRIVATE "${CMAKE_SOURCE_DIR}/src/libcurlcpp/include")

target_link_libraries (main PRIVATE curlcpp spdlog)
