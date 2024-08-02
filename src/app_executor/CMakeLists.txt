cmake_minimum_required(VERSION 3.23)
project(executor)
include(${CMAKE_SOURCE_DIR}/cmake/InitExecutable.cmake)

# Find Python from the virtual environment
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
# Include Python headers
include_directories(${Python3_INCLUDE_DIRS})
link_directories(${Python3_LIBRARY_DIRS})

find_package(pybind11 REQUIRED)
pybind11_add_module(myplugin
  ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/md_writer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/py_md_writer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/py_binding.cpp)
init_executable(executor)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${pybind11_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE pybind11::embed ${Python3_LIBRARIES})
