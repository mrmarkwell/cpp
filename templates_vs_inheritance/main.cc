// Inheritance:
// ++ Flexible at runtime. Dynamic. Runtime polymorphism.
// ++ Allows for good encapsulation && separation of interface from impl.
// + OOP is a common and typically well understood pattern. Code organization.
// + Abstract base classes can very clearly define API requirements.
// + Dependency injection to customize common code.
// - Virtual dispatch is expensive. - Performance.
// - Lots of necessary indirection (reference semantics).
// - Usually requires allocations on the heap.
// - Tighter coupling of types in an inheritance hierarchy.

// Templates:
// ++ Value semantics - highly performant.
// ++ Extremely flexible for targeting new types. E.g. STL.
// + Loose coupling between types (only necessary functionality required).
// - All types must be known at compile time. Static. Compile-time polymorphism.
// - Compile time increase (usually minor)
// - Code bloat (usually minor)
// - Definitions in header files.
// - Less encapsulation since impls are in headers.
// - Usually terrible error messages.
// - Templates can be "contagious" and propagate up the stack.

// Alternatives:
//
// Visitor pattern - std::variant && std::visit
//
//
// Guidelines for when to use what?
// Inheritance vs. Templates
//
// Prefer inheritance for large, infrequently constructed business logic types.
// Prefer simple value types and templates for smaller, frequently constructed
// types.
int main() { return 0; }
