add_library (curlcpp STATIC curl_cpp_wrapper.cpp)

target_include_directories (curlcpp
    PUBLIC "include"
)

target_link_options (curlcpp PUBLIC -pthread)

target_link_libraries (curlcpp PRIVATE curl PUBLIC ssl crypto ssl crypto z)
