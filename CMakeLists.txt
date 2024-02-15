cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(algorithms_in_cpp)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

file(GLOB SUBDIRS ${PROJECT_SOURCE_DIR}/algorithms/*)
foreach(dir ${SUBDIRS})
    add_subdirectory(${dir})
endforeach()

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})