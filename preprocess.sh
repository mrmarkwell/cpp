#!/bin/bash

# Ensure clang++ is installed
if ! command -v clang++ &>/dev/null; then
  echo "Error: clang++ is not installed."
  exit 1
fi

# Process each .cc file in the current directory
for file in *.cc; do
  # Skip if no .cc files are found
  if [ ! -e "$file" ]; then
    echo "No .cc files found in the current directory."
    exit 1
  fi

  # Generate the corresponding .i filename
  output_file="${file%.cc}.i"

  # Run the preprocessor. Use -P to suppress preprocessor directives.
  echo "Processing $file -> $output_file"
  clang++ -E -P "$file" -o "$output_file"

  # Check for errors
  if [ $? -ne 0 ]; then
    echo "Error preprocessing $file"
    exit 1
  fi
done

echo "Preprocessing complete for all .cc files."
