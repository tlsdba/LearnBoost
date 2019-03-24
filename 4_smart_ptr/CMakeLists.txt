cmake_minimum_required(VERSION 2.8)

project(4_smart_ptr)

SET(Boost_USE_MULTITHREADED ON)
FIND_PACKAGE(Boost QUIET REQUIRED regex filesystem system iostreams timer chrono random date_time)
IF(Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  MESSAGE(STATUS "Found BOOST @ ${Boost_INCLUDE_DIR}")
  LIST(APPEND ALL_LIBRARIES ${Boost_LIBRARIES})
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ELSE(Boost_FOUND)
  MESSAGE(SEND_ERROR "Cannot find BOOST!")
ENDIF(Boost_FOUND)

add_compile_options(-std=c++11)

add_executable(${PROJECT_NAME} "4_smart_ptr.cpp")
target_link_libraries (${PROJECT_NAME} ${Boost_LIBRARIES})
