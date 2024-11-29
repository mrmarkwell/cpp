#pragma once
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ostream.h>

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

// Structure to represent a stack variable's layout
struct Variable {
  std::string name;
  void* address;
  std::string value;
  size_t size;
  std::vector<Variable> subvariables;  // For structs, members are nested here
};

// Helper to format a variable's address, value, and size
template <typename T>
void TrackVariable(std::vector<Variable>& vars, const std::string& name,
                   T& var) {
  std::ostringstream value_stream;
  value_stream << var;
  vars.push_back(
      {name, static_cast<void*>(&var), value_stream.str(), sizeof(var), {}});
}

template <typename T, typename MemberPtr>
void TrackMember(std::vector<Variable>& subvars, const std::string& parent_name,
                 T& var, const std::pair<std::string, MemberPtr>& member) {
  const auto& [member_name, member_ptr] = member;  // Structured binding
  std::ostringstream value_stream;
  value_stream << var.*member_ptr;

  subvars.push_back({
      parent_name + "." + member_name,         // Full name with parent struct
      static_cast<void*>(&(var.*member_ptr)),  // Address of the member
      value_stream.str(),                      // String value of the member
      sizeof(var.*member_ptr),                 // Size of the member
      {}                                       // No nested subvariables
  });
}

template <typename T, typename... Members>
void TrackStruct(std::vector<Variable>& vars, const std::string& name, T& var,
                 Members... members) {
  std::vector<Variable> subvars;

  // Process each member in the variadic list
  (TrackMember(subvars, name, var, members), ...);

  // Add the parent struct to the list with its subvariables
  vars.push_back(
      {name, static_cast<void*>(&var), "struct", sizeof(var), subvars});
}

#define TRACK(var) TrackVariable(vars, #var, var)
#define TRACK_STRUCT(var, ...) TrackStruct(vars, #var, var, __VA_ARGS__)

// Function to display the stack layout
void DisplayStackLayout(const std::vector<Variable>& vars);

// Example Usage.
void VisualizeStack();
