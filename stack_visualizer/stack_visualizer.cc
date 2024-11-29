#include "stack_visualizer.h"

// Function to display the stack layout
void DisplayStackLayout(const std::vector<Variable>& vars) {
  fmt::print("\n{:^60}\n", "Stack Layout (higher -> lower addresses)");
  fmt::print(
      "+------------------------------------------------------------+\n");

  // Sort variables by address in descending order
  auto sorted_vars = vars;
  std::sort(sorted_vars.begin(), sorted_vars.end(),
            [](const Variable& a, const Variable& b) {
              return a.address > b.address;
            });

  for (const auto& var : sorted_vars) {
    fmt::print("| {:<20} | Address: {:<16p} Size: {:<4} |\n", var.name,
               var.address, var.size);
    fmt::print(
        "+------------------------------------------------------------+\n");

    // If the variable has subvariables, display them indented
    for (const auto& subvar : var.subvariables) {
      fmt::print("   | {:<16} | Address: {:<16p} Size: {:<4} Value: {}\n",
                 subvar.name, subvar.address, subvar.size, subvar.value);
    }
  }
}

// Globals are bad.
std::vector<Variable> vars;

// Example usage.
void VisualizeStack() {
  // Define local variables
  int local_int = 42;
  double local_double = 3.14;
  char local_char = 'A';

  struct MyStruct {
    int x;
    char y;
    double z;
  } local_struct = {1, 'a', 2.718};

  // Track individual variables
  TRACK(local_int);
  TRACK(local_double);
  TRACK(local_char);

  // Track struct and its members
  TRACK_STRUCT(local_struct, std::make_pair(std::string("x"), &MyStruct::x),
               std::make_pair(std::string("y"), &MyStruct::y),
               std::make_pair(std::string("z"), &MyStruct::z));

  // Display stack layout
  DisplayStackLayout(vars);
}
