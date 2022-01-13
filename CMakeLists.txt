cmake_minimum_required(VERSION 3.16)
project(opengl_solar_system)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

#########################################################
# FIND GLEW
#########################################################
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_directories(${GLEW_LIBRARY_DIRS})
add_definitions(${GLEW_DEFINITIONS})
if(NOT GLEW_FOUND)
    message(ERROR " GLEW not found!")
endif(NOT GLEW_FOUND)

#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

#########################################################
# FIND SOIL
#########################################################
find_package(SOIL REQUIRED)
include_directories(${SOIL_INCLUDE_DIRS})
link_directories(${SOIL_LIBRARY_DIRS})
add_definitions(${SOIL_DEFINITIONS})
if(NOT SOIL_FOUND)
    message(ERROR " SOIL not found!")
endif(NOT SOIL_FOUND)

#########################################################
# Include Files
#########################################################
add_executable(opengl_solar_system main.cpp Star.cpp TextureManager.cpp TextureManager.h SolarSystem.cpp SolarSystem.h Camera.cpp Camera.h)

########################################################
# Linking & stuff
#########################################################

# create the program "test"
target_link_libraries(opengl_solar_system ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY} ${SOIL_LIBRARY})


