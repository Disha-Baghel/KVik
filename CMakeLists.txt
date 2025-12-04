cmake_minimum_required(VERSION 3.15)

project(kvik VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Core library (key-value in-memory logic)
add_library(kvik_core STATIC
    src/kvik_core.cpp
)

# Server library (networking logic)
add_library(kvik_net STATIC
    src/kvik_server.cpp
)

# Main server executable
add_executable(kvik_server
    src/main.cpp
)

# Link the libraries to the server executable
target_link_libraries(kvik_server
    PRIVATE kvik_core kvik_net
)


# 6️⃣ (Optional) Add kv_server and kv_tests later
# add_executable(kv_server src/main.cpp)
# add_executable(kv_tests tests/test_main.cpp)
