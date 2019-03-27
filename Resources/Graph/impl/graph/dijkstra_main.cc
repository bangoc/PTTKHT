#include "adjacent_graph.h"
#include "adjacent_graph_dam.h"
#include "algorithm.h"
#include "printer.h"

#include <iostream>
#include <map>
#include <sstream>

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cout << "Usage: ./dijkstra graph.txt 1 5" << std::endl;
    return 1;
  }
  AdjacentGraph* g = AdjacentGraphDAM::LoadGraph(argv[1]);
  BackPath back;
  double length;
  int v1 = 0, v2 = 0;
  {
    std::stringstream ss1{argv[2]};
    ss1 >> v1;
    std::stringstream ss2{argv[3]};
    ss2 >> v2;
  }
  if (Algorithm::Dijkstra(g, v1, v2, back, length)) {
    std::cout << "Min distance from " << v1 << " to " << v2
              << " is " << length << std::endl;
    std::cout << "The shortest path is: ";
    Printer::Print(v1, v2, back);
    std::cout << std::endl;
  } else {
    std::cout << "Doesn't exist path from " << v1
              << " to " << v2 << std::endl;
  }
  delete g;
}