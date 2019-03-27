#include "adjacent_graph_dam.h"

#include <iostream>
#include <fstream>

AdjacentGraph* AdjacentGraphDAM::LoadGraph(
          const std::string& fname) {
  AdjacentGraph* g = new AdjacentGraph();
  std::ifstream inp{fname};
  int n;
  inp >> n;
  if (n > 0) {
    for (int i = 0; i < n; ++i) {
      int v1, v2;
      double w;
      inp >> v1 >> v2 >> w;
      g->AddEdge(v1, v2, w);
    }
  }
  return g;
}