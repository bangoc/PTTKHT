#include "adjacent_graph.h"

#include <iostream>

AdjacentVertices* AdjacentGraph::GetAdjacentVertices(int id) {
  if (model_.find(id) != model_.end()) {
    return &model_[id];
  }
  return nullptr;
}

void AdjacentGraph::AddEdge(int b, int e, double weight) {
  model_[b][e] = weight;
}