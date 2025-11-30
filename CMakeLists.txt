cmake_minimum_required(VERSION 4.0.0)
project(HW2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

include(FetchContent)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(json)

add_executable(HW3
    src/main.cpp
    src/BST.cpp
    src/HT.cpp
)

target_link_libraries(HW3 PRIVATE nlohmann_json::nlohmann_json)