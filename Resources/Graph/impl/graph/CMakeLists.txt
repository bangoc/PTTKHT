cmake_minimum_required(VERSION 2.8)
project(dijkstra)
add_executable(dijkstra
               dijkstra_main.cc
               algorithm.cc
               adjacent_graph.cc
               adjacent_graph_dam.cc
               printer.cc)