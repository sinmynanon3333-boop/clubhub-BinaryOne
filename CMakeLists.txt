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
    src/event.cpp                   # Lab-02
    src/event_csv.cpp               # Lab-02
    src/Student.cpp                 # Lab-03
    src/ConsoleOutput.cpp           # Lab-03
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
# Testing & Dependencies (FetchContent): GoogleTest & rapidcsv
# ==============================================================================
include(FetchContent)

# 1. GoogleTest
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
# For Windows/MSVC: prevent runtime mismatch errors
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# 2. rapidcsv (Added for Lab-04 Task5)
FetchContent_Declare(
    rapidcsv
    GIT_REPOSITORY https://github.com/d99kris/rapidcsv.git
    GIT_TAG v8.84
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(googletest rapidcsv)

enable_testing()
include(GoogleTest)

# Existing Lab-03 tests
add_executable(clubhub_tests 
    tests/StudentPrivacyTest.cpp
    tests/ConsoleOutputTest.cpp
)
target_link_libraries(clubhub_tests PRIVATE clubhub_core GTest::gtest_main)
gtest_discover_tests(clubhub_tests)

# ==============================================================================
# Lab-04 Task 5: Smoke Test for rapidcsv
# ==============================================================================
add_executable(csv_smoke_test 
    tests/csv_smoke_test.cpp
)
target_link_libraries(csv_smoke_test PRIVATE rapidcsv GTest::gtest_main)
gtest_discover_tests(csv_smoke_test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# ==============================================================================
# Lab-04 Challenge: Cancellation Policy Unit Test (REQ-12)
# ==============================================================================
add_executable(cancellation_rule_test 
    tests/cancellation_rule_test.cpp
)
target_include_directories(cancellation_rule_test PRIVATE include)
target_link_libraries(cancellation_rule_test PRIVATE GTest::gtest_main)
gtest_discover_tests(cancellation_rule_test)