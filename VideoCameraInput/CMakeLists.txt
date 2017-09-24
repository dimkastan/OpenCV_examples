cmake_minimum_required(VERSION 3.5)
 # cmake .. -DCUDA_USE_STATIC_CUDA_RUNTIME=OFF ## run this command

project( VideoCamera )


find_package( OpenCV REQUIRED )
# find_package(CUDA)
SET(CUDA_USE_STATIC_CUDA_RUNTIME  OFF   )


 
include_directories( ${OpenCV_INCLUDE_DIRS} )

SET (CMAKE_CXX_COMPILER   "g++-5") 
SET(CMAKE_BUILD_TYPE CMAKE_CXX_FLAGS_RELEASE)


 
add_executable( VideoCamera main.cpp )
target_link_libraries( VideoCamera ${OpenCV_LIBS} )