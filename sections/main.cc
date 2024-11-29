#define FMT_HEADER_ONLY
#include <fmt/core.h>

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>

// Global variables for the Data and BSS segments.
int global_var = 42;    // Initialized global variable (Data Segment)
int uninit_global_var;  // Uninitialized global variable (BSS)

// Struct to represent a memory segment with its metadata.
struct MemorySegment {
  std::string name;
  std::uintptr_t address;
  std::string segment;
};

// Prints the memory layout in ascending order of memory addresses.
void PrintMemoryLayout() {
  // Local variables to test stack and heap segments.
  int local_var = 0;            // Stack variable
  int* heap_var = new int(99);  // Dynamically allocated variable (Heap)

  // Use the address of the text segment as the memory bottom.
  auto program_memory_bottom =
      reinterpret_cast<std::uintptr_t>(&PrintMemoryLayout);

  // Store memory segments in a vector for sorting and display.
  std::vector<MemorySegment> segments = {
      {"Text Segment (Code)",
       reinterpret_cast<std::uintptr_t>(&PrintMemoryLayout), "Text"},
      {"Data Segment", reinterpret_cast<std::uintptr_t>(&global_var), "Data"},
      {"BSS Segment", reinterpret_cast<std::uintptr_t>(&uninit_global_var),
       "BSS"},
      {"Heap", reinterpret_cast<std::uintptr_t>(heap_var), "Heap"},
      {"Stack (local_var)", reinterpret_cast<std::uintptr_t>(&local_var),
       "Stack"},
  };

  // Sort the segments by address in descending order (high to low).
  std::sort(segments.begin(), segments.end(),
            [](const MemorySegment& a, const MemorySegment& b) {
              return a.address > b.address;
            });

  // Print the header.
  fmt::print("Memory Layout (base: {:#x})\n", program_memory_bottom);
  fmt::print(
      "+------------------------+-------------------+------------------+\n");
  fmt::print(
      "| Memory Segment         | Address           | Offset           |\n");
  fmt::print(
      "+------------------------+-------------------+------------------+\n");

  // Print each segment with its offset relative to the program memory bottom.
  for (const auto& segment : segments) {
    fmt::print("| {:<22} | {:#17x} | {:#16d} |\n", segment.name,
               segment.address,
               static_cast<long>(segment.address - program_memory_bottom));
  }

  fmt::print(
      "+------------------------+-------------------+------------------+\n");

  // Clean up dynamically allocated memory.
  delete heap_var;
}

// Entry point of the program.
int main() {
  PrintMemoryLayout();
  return 0;
}
