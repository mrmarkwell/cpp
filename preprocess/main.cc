// .cc .h
// "main"
// Declarations vs. Definitions

// Translation Units
// single .cc file and all the .h files it includes.
//    -> .o "Object file"
//
// How does this end up happening?
// Step 1: Preprocessor: handles all # commands.
// Step 2: Compiler: take the resulting .i file and convert it to assembly (.o)
// Step 3: Linker: Take the resulting .o files and link them together.

#include "square.h"  // Copy paste whole file.

#define COOL_MACRO Square(argc);  // Copy paste single expression.

#define FOOBAR 3

int main(int argc, char** argv) {
  int x = FOOBAR;

  return COOL_MACRO
}
