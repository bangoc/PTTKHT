#ifndef ADJACENT_GRAPH_DAM_H_
#define ADJACENT_GRAPH_DAM_H_

#include "adjacent_graph.h"

#include <string>

class AdjacentGraphDAM {
 public:
  static AdjacentGraph* LoadGraph(
            const std::string& fname);
};

#endif  // ADJACENT_GRAPH_DAM_H_