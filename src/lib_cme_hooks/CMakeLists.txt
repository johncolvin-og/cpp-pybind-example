cmake_minimum_required(VERSION 3.23)
project(cme_hooks)

find_package(pybind11 REQUIRED)

file(
  GLOB_RECURSE ${PROJECT_NAME}_Sources
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  ${PROJECT_NAME}/*.cpp)
# add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_Sources})
pybind11_add_module(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/cme_hooks.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${pybind11_INCLUDE_DIR})
