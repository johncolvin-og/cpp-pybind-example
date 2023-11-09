# include(ExternalProject)

# if(NOT TARGET websocketpp_project)
# ExternalProject_Add(websocketpp_project 
#     URL https://github.com/zaphoyd/websocketpp/archive/0.8.2.zip
#     CONFIGURE_COMMAND
#       cmake 
#         -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/websocketpp/install
#         -DCMAKE_BUILD_TYPE=Release
#         -B ${CMAKE_BINARY_DIR}/websocketpp/build
#         -S ${CMAKE_BINARY_DIR}/websocketpp
#     INSTALL_COMMAND cmake --build ${CMAKE_BINARY_DIR}/websocketpp/build --target install
# )
# endif()

# ExternalProject_Get_Property(websocketpp_project SOURCE_DIR)
# message("WEBSOCKETPP_INCLUDE_DIR: ${WEBSOCKETPP_INCLUDE_DIR}")
# message("INCLUDE_DIR: ${INCLUDE_DIR}")
# set(websocketpp_INCLUDE_DIR ${CMAKE_BINARY_DIR}/websocketpp/install/include) 
# message("websocketpp_INCLUDE_DIR: ${websocketpp_INCLUDE_DIR}")
