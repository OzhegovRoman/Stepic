project(server)
cmake_minimum_required(VERSION 2.8)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

aux_source_directory(. SRC_LIST)

add_executable(final ${SRC_LIST})

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
     set_property(TARGET final PROPERTY COMPILE_OPTIONS "-pthread")
     set_property(TARGET final PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(final "${CMAKE_THREAD_LIBS_INIT}")
endif()


