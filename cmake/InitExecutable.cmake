function(init_executable source_dir)
  file(
    GLOB_RECURSE ${PROJECT_NAME}_Sources
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${source_dir}/*.cpp)
  add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_Sources})
  target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
endfunction(init_executable)
