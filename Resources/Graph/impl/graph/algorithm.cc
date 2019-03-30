#include "algorithm.h"

#include <iostream>
#include <queue>
#include <set>

bool Algorithm::Dijkstra(
              AdjacentGraph* g,
              const int b, const int e,
              BackPath& back,
              double& length) {
  std::map<int, double> dist;
  dist[b] = 0;
  std::set<int> visited;
  visited.insert(b);
  while (!dist.empty()) {
    auto min_iter = dist.begin();
    for (auto iter = dist.begin(); iter != dist.end(); ++iter) {
      if (iter->second < min_iter->second) {
        min_iter = iter;
      }
    }
    const int v = min_iter->first;
    const double d = min_iter->second;
    dist.erase(min_iter);
    if (v == e) {
      length = d;
      return true;
    }
    AdjacentVertices* adjacents = g->GetAdjacentVertices(v);
    if (!adjacents) {
      return false;
    }
    for (auto iter: *adjacents) {
      const int v2 = iter.first;
      const double weight = iter.second;
      if (dist.find(v2) != dist.end()) {
        if (dist[v2] < d + weight) {
          dist[v2] = d + weight;
          back[v2] = v;
        }
      } else if (visited.find(v2) == visited.end()) {
        dist[v2] = d + weight;
        back[v2] = v;
        visited.insert(v2);
      }
    }
  }
  return false;
}