cmake_minimum_required(VERSION 2.6)
project(cvx)

find_package(PkgConfig)
pkg_search_module(GTK REQUIRED gtk+-2.0)
include_directories(${GTK_INCLUDE_DIRS})

add_executable(cvx main.c cvxfield.c cvxnode.c cvxnodelist.c)
target_link_libraries(cvx ${GTK_LIBRARIES})
