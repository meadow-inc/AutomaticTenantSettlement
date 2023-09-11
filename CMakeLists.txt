# Minimum version of CMake which is required
cmake_minimum_required(VERSION 3.10)

# Name of project
project(AutomatedTenantSettlement)

# enable testing
enable_testing()

# Enable Compile Commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Specify the required C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add include folder
add_subdirectory(include)

# Add src folder 
add_subdirectory(src)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/8a6feabf04bec8fb125e0df0ad1195c42350725f.zip
    )
FetchContent_MakeAvailable(googletest)

# add tests folder
add_subdirectory(tests)

# Add an executable
add_executable(app src/main.cpp)

# Link the tenant_settlement library with the executable
target_link_libraries(app tenant_settlement)



