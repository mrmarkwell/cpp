# cpp

Examples of C++ things from scratch.

Each folder has some lesson.

## Build and run

```

# Build the contents of the current folder.
clang++ -std=c++20 -g -c *.cc && clang++ -std=c++20 -g *.o

# Run the resulting executable.
./a.out
```

## Folders

### preprocess

Run the preprocess.sh script to generate .i files. This illustrates how the
preprocessor just substitutes headers and macros.

### stack_visualizer

Runs a little visualizer of the values on a stack.

### objdump

Useful for inspecting the C++ with objdump and readelf.

### sections

Prints the sections in program memory.
