cmake_minimum_required(VERSION 3.10)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Eigen
find_package(Eigen3)
include_directories(/usr/local/include/eigen3)
# Find include folder for gnuplot
include_directories(../../include/)

# set the project name
project(homework1)

#Find Boost
# set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.72.0_1/include)
# set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.72.0_1/lib)
# link_directories(${Boost_LIBRARY_DIR})
find_package(Boost COMPONENTS iostreams system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

include_directories(./include)
# set the target
add_executable(hw1 src/main.cpp)
target_link_libraries(hw1 ${Boost_LIBRARIES})