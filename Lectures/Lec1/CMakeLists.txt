cmake_minimum_required(VERSION 3.10)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Eigen
include_directories(/usr/local/include/eigen3)
find_package(Eigen3)

# set the project name
project(ModelConvergence)

# set the target
add_executable(modelConvergence main.cpp)
# target_link_libraries(lec1 ${Eigen3_LIBS})