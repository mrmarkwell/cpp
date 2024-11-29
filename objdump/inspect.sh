#!/bin/bash

# Check if an input file is provided
if [ $# -ne 1 ]; then
  echo "Usage: $0 <file-to-inspect>"
  exit 1
fi

# Get the input file from the argument
input_file=$1

# Ensure the specified file exists
if [ ! -f "$input_file" ]; then
  echo "Error: File '$input_file' not found."
  exit 1
fi

# Determine the log file name
log_file="${input_file}.log"

# Start writing to the log file
{
  # Section 1: Disassembly with debug symbols
  echo "============================"
  echo "1. Disassembly of $input_file (with debug symbols)"
  echo "objdump -d -S --disassembler-options=intel $input_file"
  echo "============================"
  objdump -d -S --disassembler-options=intel "$input_file"
  echo

  # Section 2: Symbol Table
  echo "============================"
  echo "2. Symbol Table (Symbols in $input_file)"
  echo "objdump -t $input_file"
  echo "============================"
  objdump -t "$input_file"
  echo

  # Section 3: Relocations
  echo "============================"
  echo "3. Relocation Entries"
  echo " objdump -r $input_file"
  echo "============================"
  objdump -r "$input_file"
  echo

  # Section 4: Section Headers
  echo "============================"
  echo "4. Section Headers"
  echo " readelf -S $input_file"
  echo "============================"
  readelf -S "$input_file"
  echo

  # Section 5: Symbols from readelf
  echo "============================"
  echo "5. Symbol Table (readelf output)"
  echo " readelf -s $input_file"
  echo "============================"
  readelf -s "$input_file"
  echo

  # Section 6: Relocation Information
  echo "============================"
  echo "6. Relocation Information (readelf output)"
  echo " readelf -r $input_file"
  echo "============================"
  readelf -r "$input_file"
  echo

  # Section 7: ELF Header
  echo "============================"
  echo "7. ELF Header of $input_file"
  echo " readelf -h $input_file"
  echo "============================"
  readelf -h "$input_file"
  echo

  # Section 8: Debug Information
  echo "============================"
  echo "8. Debug Information"
  echo " readelf --debug-dump=info $input_file"
  echo "============================"
  readelf --debug-dump=info "$input_file"
  echo

  # Section 9: Debug Line Information
  echo "============================"
  echo "9. Debug Line Information"
  echo " readelf --debug-dump=line $input_file"
  echo "============================"
  readelf --debug-dump=line "$input_file"
  echo

  # Completion Message
  echo "Inspection of $input_file is complete."
} >"$log_file" 2>&1

# Notify the user of the log file
echo "Output has been written to $log_file"
