#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "adjacent_graph.h"

#include <map>

class Algorithm {
 public:
  static bool Dijkstra(
                AdjacentGraph* g, int b, int e,
                BackPath& back,
                double& length);
};

#endif  // ALGORITHM_H_