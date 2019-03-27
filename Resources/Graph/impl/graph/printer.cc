#include "printer.h"

#include <iostream>

void Printer::Print(int v1, int v2, BackPath& back) {
  if (v2 != v1) {
    Print(v1, back[v2], back);
  }
  std::cout << " " << v2;
}