#ifndef PRINTER_H_
#define PRINTER_H_

#include "base.h"

class Printer {
 public:
  static void Print(int v1, int v2, BackPath& back);
};

#endif  // PRINTER_H_