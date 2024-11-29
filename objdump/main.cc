#include "square.h"

int example_global_int = 0xDEADBEEF;
int example_uninitialized_long;

int main(int argc, char** argv) {
  // Return the square of the number of arguments.
  return Square(argc - 1);
}
