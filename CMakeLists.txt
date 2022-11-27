cmake_minimum_required(VERSION 3.16.1)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.14")

project(browser)

include_directories(include)
add_subdirectory(source) 
