cmake_minimum_required(VERSION 3.28)
project(clubhub VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Library: Contains all application logic except main()
# add_library(clubhub_core src/banner.cpp)
# add_library(clubhub_core src/event.cpp src/event_csv.cpp)
# Added src/Student.cpp for Lab-03
add_library(clubhub_core 
    src/event.cpp 
    src/event_csv.cpp
    src/Student.cpp
    src/ConsoleOutput.cpp
)

target_include_directories(clubhub_core PUBLIC include)
# target_compile_definitions(clubhub_core PRIVATE CLUBHUB_VERSION="${PROJECT_VERSION}")

# Strict compiler warnings (treat warnings as quality gates)
if(MSVC)
    target_compile_options(clubhub_core PRIVATE /W4)
else()
    target_compile_options(clubhub_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Executable: Command-line interface frontend
# add_executable(clubhub src/main.cpp)
add_executable(clubhub src/cli/main.cpp)
target_link_libraries(clubhub PRIVATE clubhub_core)

# ==============================================================================
# Testing: GoogleTest Setup for Lab-03
# ==============================================================================
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
# For Windows/MSVC: prevent runtime mismatch errors
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_executable(clubhub_tests 
    tests/StudentPrivacyTest.cpp
    tests/ConsoleOutputTest.cpp
)
target_link_libraries(clubhub_tests PRIVATE clubhub_core GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(clubhub_tests)