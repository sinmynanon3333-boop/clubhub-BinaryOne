cmake_minimum_required(VERSION 3.28)
project(clubhub LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Core: domain model and rules. No console, no file names.
add_library(clubhub_core src/event.cpp src/event_csv.cpp)
target_include_directories(clubhub_core PUBLIC include)

# Interface: the command-line front end. A web or mobile front end
# would be another target that links the same core.
add_executable(clubhub src/cli/main.cpp)
target_link_libraries(clubhub PRIVATE clubhub_core)
# Add ConsoleOutput.cpp to your core library
add_library(clubhub_core src/ConsoleOutput.cpp)
    # ... existing src/event.cpp files ...
target_include_directories(clubhub_core PUBLIC include)

# Register the test executable with CTest
add_executable(ConsoleOutputTest tests/ConsoleOutputTest.cpp)
target_link_libraries(ConsoleOutputTest PRIVATE clubhub_core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ConsoleOutputTest)