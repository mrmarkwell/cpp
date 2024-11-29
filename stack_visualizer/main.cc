#define FMT_HEADER_ONLY
#include <fmt/core.h>

#include "stack_visualizer.h"

int main(int argc, char** argv) {
  fmt::print("Hello, World!\n");

  VisualizeStack();
  return 0;
}
