cmake_minimum_required(VERSION 3.10)

# set the project name
project(TaylorApproximations)
# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Eigen
find_package(Eigen3)
include_directories(/usr/local/include/eigen3)
include_directories(../../matplotlib-cpp)
find_package(Python3 COMPONENTS Development NumPy)



# set the target
add_executable(taylorApprox main.cpp)
# target_link_libraries(lec1 ${Eigen3_LIBS})
target_include_directories(taylorApprox PRIVATE ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(taylorApprox Python3::Python Python3::NumPy)
