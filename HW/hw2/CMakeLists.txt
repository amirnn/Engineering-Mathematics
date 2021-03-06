cmake_minimum_required(VERSION 3.10)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXE_LINKER_FLAGS "-v")

# Find Eigen
include_directories(/usr/local/include/eigen3)

#  Find Armadillo
# include_directories(/usr/local/include/armadillo)
find_package(Armadillo REQUIRED)
set(Armadillo_LIBRARY_DIR /Users/amirnourinia/Developer/Libs/Armadillo-build/)
# link_directories(${Armadillo_LIBRARY_DIR})
# Find include folder for gnuplot
include_directories(../../include/)

# set the project name
project(homework2)

#Find Boost
# set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.72.0_1/include)
# set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.72.0_1/lib)
# link_directories(${Boost_LIBRARY_DIR})
find_package(Boost COMPONENTS iostreams system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

include_directories(./include)
# set the target s
add_executable(exercise2_2_a src/exercise2_2_a.cpp)
target_link_libraries(exercise2_2_a ${Boost_LIBRARIES} ${Armadillo_LIBRARIES})

add_executable(exercise2_2_b src/exercise2_2_b.cpp)
target_link_libraries(exercise2_2_b ${Boost_LIBRARIES} ${Armadillo_LIBRARIES})

add_executable(exercise2_3 src/exercise2_3.cpp)
target_link_libraries(exercise2_3 ${Boost_LIBRARIES} lapack blas)