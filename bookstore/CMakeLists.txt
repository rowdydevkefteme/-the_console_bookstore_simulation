cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Bookstore VERSION 1.0.0 LANGUAGES CXX)

file(GLOB bookstore_sources
	sources/*.cpp
	include/bookstore/*.h
)

add_executable(${PROJECT_NAME} ${bookstore_sources})

target_include_directories(${PROJECT_NAME} PRIVATE include)