#ifndef ADJACENT_GRAPH_H_
#define ADJACENT_GRAPH_H_

#include "base.h"

#include <map>
#include <vector>

class AdjacentGraph {
 public:
  AdjacentVertices* GetAdjacentVertices(int id);
  void AddEdge(int b, int e, double weight);
 private:
  std::map<int, AdjacentVertices> model_;
};

#endif  // ADJACENT_GRAPH_H_