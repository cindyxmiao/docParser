cmake_minimum_required(VERSION 3.10)

project (template_project2020 LANGUAGES CXX)

#if (EXISTS "${CMAKE_CURRENT_BINARY_DIR}/.conan/conanbuildinfo.cmake")
set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR}/.conan)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR}/.conan)	
#message ("foo")
	#endif()

find_package(GTest REQUIRED)

add_executable(parser parser.cpp)

target_link_libraries(parser PRIVATE GTest::GTest)

