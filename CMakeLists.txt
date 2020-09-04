project( p_demo_04_template_buffer )
cmake_minimum_required( VERSION 3.4 )

set( CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH})
set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON )

include_directories(include) 
add_executable( ${PROJECT_NAME}
                src/main.cpp)

