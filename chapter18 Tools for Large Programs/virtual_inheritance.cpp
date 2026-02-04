/**
 * Virtual Inheritance
 *
 * Although the derivation list of a class may not include the same base class
 * more than once, a class can inherit from the same base class more than once.
 *
 * It might inherit the same base indirectly from two of its own direct base
 * classes, or it might inherit a particular class directly and indirectly
 * through another of its base classes.
 *
 * By default, a derived object contains a separate subpart corresponding to
 * each class in its derivation chain. If the same base class appears more than
 * once in the derivation, then the derived object will have more than one
 * subobject of that type.
 *
 * Virtual inheritance lets a class specify that it is willing to share its base
 * class. The shared base-class subobject is called a virtual base class.
 * Regardless of how often the same virtual base appears in an inheritance
 * hierarchy, the derived object contains only one, shared subobject for that
 * virtual base class.
 *
 *
 * A Different Panda Class
 *
 * The virtual derivation has to be made before the need for it appears. For
 * example, in our classes, the need for virtual inheritance arises only when we
 * define Panda. However, if Bear and Raccoon had not specified virtual on their
 * derivation from ZooAnimal, the designer of the Panda class would be out of
 * luck.
 *
 * In practice, the requirement that an intermediate base class specify its
 * inheritance as virtual rarely causes any problems.
 *
 * Note
 * Virtual derivation affects the classes that subsequently derive from a class
 * with a virtual base; it doesn’t affect the derived class itself.
 *
 *
 * Using a Virtual Base Class
 *
 * We specify that a base class is virtual by including the keyword virtual in
 * the derivation list.
 *
 * The virtual specifier states a willingness to share a single instance of the
 * named base class within a subsequently derived class. There are no special

 * constraints on a class used as a virtual base class.
 *
 *
 * Normal Conversions to Base Are Supported
 *
 * An object of a derived class can be manipulated (as usual) through a pointer
 * or a reference to an accessible base-class type regardless of whether the
 * base class is virtual.
 *
 *
 * Visibility of Virtual Base-Class Members
 *
 * Because there is only one shared subobject corresponding to each shared
 * virtual base, members in that base can be accessed directly and
 * unambiguously. Moreover, if a member from the virtual base is overridden
 * along only one derivation path, then that overridden member can still be
 * accessed directly. If the member is overridden by more than one base, then
 * the derived class generally must define its own version as well.
 *
 *
 *
 * Constructors and Virtual Inheritance
 *
 * In a virtual derivation, the virtual base is initialized by the most derived
 * constructor.
 *
 *
 * How a Virtually Inherited Object Is Constructed
 *
 * The construction order for an object with a virtual base is slightly modified
 * from the normal order: The virtual base subparts of the object are
 * initialized first, using initializers provided in the constructor for the
 * most derived class.
 *
 * If the Panda constructor does not explicitly initialize the ZooAnimal base
 * class, then the ZooAnimal default constructor is used. If ZooAnimal doesn’t
 * have a default constructor, then the code is in error.
 *
 * Note
 * Virtual base classes are always constructed prior to nonvirtual base classes
 * regardless of where they appear in the inheritance hierarchy.
 *
 *
 *
 * Constructor and Destructor Order
 *
 * A class can have more than one virtual base class. In that case, the virtual
 * subobjects are constructed in left-to-right order as they appear in the
 * derivation list.
 *
 * The direct base classes are examined in declaration order to determine
 * whether there are any virtual base classes. If so, the virtual bases are
 * constructed first, followed by the nonvirtual base-class constructors in
 * declaration order.
 *
 * The same order is used in the synthesized copy and move constructors, and
 * members are assigned in this order in the synthesized assignment operators.
 * As usual, an object is destroyed in reverse order from which it was
 * constructed. The TeddyBear part will be destroyed first and the ZooAnimal
 * part last.
 *
 *
 * 
 * Runtime Implementation of Pointer Conversions
 *
 * In nonvirtual inheritance, upcasting is a compile-time fixed offset. In virtual
 * inheritance, the virtual base's location depends on the most-derived class,
 * meaning the offset is not constant and must be resolved at runtime.
 *
 *
 * VBase Offset in the VTable (Linux/Itanium ABI)
 *
 * On Linux (Itanium ABI), the compiler stores a "VBase Offset" at a negative 
 * index relative to the virtual pointer (vptr) in the vtable. To perform 
 * an upcast to a virtual base:
 * 1. The vptr is fetched from the object.
 * 2. The VBase Offset is read from the negative offset area of the vtable.
 * 3. This dynamic offset is added to the pointer to reach the shared base.
 *
 *
 * Performance and Downcasting Constraints
 *
 * This "double dereference" (vptr -> vtable -> offset) adds a small runtime 
 * overhead compared to normal inheritance. Additionally, because the offset 
 * is dynamic, static_cast cannot be used for downcasting from a virtual base 
 * to a derived type; dynamic_cast must be used instead.
 * 
 * 
 *
 * The Mechanics of dynamic_cast in Virtual Inheritance
 *
 * Unlike static_cast, which relies on fixed compile-time offsets, dynamic_cast 
 * for downcasting from a virtual base must perform a runtime search. Because 
 * the virtual base is shared and its position is only known by the most-derived 
 * class, the runtime must "backtrack" to resolve the pointer.
 *
 *
 * The Two-Step Runtime Resolution (Itanium ABI)
 *
 * 1. Locating the "Complete Object":
 * The runtime uses the current pointer's vtable to find the "offset-to-top" 
 * value (stored at a negative offset relative to the vptr). It adds this 
 * value to the current pointer to reach the starting address of the 
 * most-derived (complete) object instance.
 *
 * 2. Inheritance Graph Traversal:
 * Once at the start of the complete object, the runtime accesses its RTTI 
 * (Runtime Type Information). It then traverses the inheritance DAG 
 * (Directed Acyclic Graph) to find the target derived type. It verifies 
 * that the conversion is unambiguous and that access rights are valid.
 *
 *
 * Safety, Ambiguity, and Performance
 *
 * If the target type is not found or if multiple paths to the target exist 
 * (causing ambiguity), dynamic_cast returns nullptr (for pointers) or throws 
 * std::bad_cast (for references). 
 *
 * Note
 * This process involves multiple memory dereferences (vptr -> vtable -> 
 * offset-to-top -> RTTI) and a tree search, making it significantly more 
 * expensive than static_cast. In performance-critical systems, such as 
 * advertising engines, this overhead should be carefully monitored.* The Mechanics of dynamic_cast in Virtual Inheritance
 *
 * Unlike static_cast, which relies on fixed compile-time offsets, dynamic_cast 
 * for downcasting from a virtual base must perform a runtime search. Because 
 * the virtual base is shared and its position is only known by the most-derived 
 * class, the runtime must "backtrack" to resolve the pointer.
 *
 *
 * The Two-Step Runtime Resolution (Itanium ABI)
 *
 * 1. Locating the "Complete Object":
 * The runtime uses the current pointer's vtable to find the "offset-to-top" 
 * value (stored at a negative offset relative to the vptr). It adds this 
 * value to the current pointer to reach the starting address of the 
 * most-derived (complete) object instance.
 *
 * 2. Inheritance Graph Traversal:
 * Once at the start of the complete object, the runtime accesses its RTTI 
 * (Runtime Type Information). It then traverses the inheritance DAG 
 * (Directed Acyclic Graph) to find the target derived type. It verifies 
 * that the conversion is unambiguous and that access rights are valid.
 *
 *
 * Safety, Ambiguity, and Performance
 *
 * If the target type is not found or if multiple paths to the target exist 
 * (causing ambiguity), dynamic_cast returns nullptr (for pointers) or throws 
 * std::bad_cast (for references). 
 *
 * Note
 * This process involves multiple memory dereferences (vptr -> vtable -> 
 * offset-to-top -> RTTI) and a tree search, making it significantly more 
 * expensive than static_cast. In performance-critical systems, such as 
 * advertising engines, this overhead should be carefully monitored.
 */

#include <iostream>

// Base class
class ZooAnimal {
public:
  // This constructor takes an integer argument to demonstrate that the
  // most-derived class's constructor is responsible for initializing it.
  ZooAnimal(int i) {
    std::cout << "ZooAnimal(" << i << ") constructor" << std::endl;
  }
  // Default constructor is needed if a derived class doesn't explicitly call a
  // parameterized one.
  ZooAnimal() { std::cout << "ZooAnimal default constructor" << std::endl; }
};

// This two classes are aimed to verify that the virtual base class will be
// contructed first in derivation chain, rather than the plain classes which may
// be closer to the head fo the chain.
class Endangered {
public:
  Endangered() { std::cout << "Endangered constructor" << std::endl; }
};

class ToyAnimal {
public:
  ToyAnimal() { std::cout << "ToyAnimal constructor" << std::endl; }
};

// Intermediate class 1: virtually inherits from ZooAnimal
class Bear : public Endangered, public virtual ZooAnimal {
public:
  // This constructor calls the ZooAnimal constructor, but it will be ignored
  // when creating a Panda object.
  Bear() : ZooAnimal(1) { std::cout << "Bear constructor" << std::endl; }
};

// Intermediate class 2: virtually inherits from ZooAnimal
class Raccoon : public virtual ZooAnimal {
public:
  // This constructor also calls the ZooAnimal constructor, which will also be
  // ignored.
  Raccoon() : ZooAnimal(2) { std::cout << "Raccoon constructor" << std::endl; }
};

// Most-derived class: inherits from Bear and Raccoon
class Panda : public ToyAnimal, public Bear, public Raccoon {
public:
  // The Panda constructor is responsible for initializing the virtual base
  // ZooAnimal. The initializers for Bear and Raccoon are executed, but their
  // calls to the ZooAnimal constructor are ignored.
  Panda() { std::cout << "Panda constructor" << std::endl; }
};

int main() {
  std::cout << "Creating a Panda object:" << std::endl;
  Panda p;
  std::cout << "\n--- Execution Analysis ---" << std::endl;
  std::cout << "1. 'ZooAnimal(3) constructor': The most-derived class 'Panda' "
               "directly initializes the virtual base 'ZooAnimal'. The value "
               "'3' from Panda's initializer list is used."
            << std::endl;
  std::cout << "2. 'Bear constructor': The 'Bear' non-virtual base class "
               "constructor is called."
            << std::endl;
  std::cout << "3. 'Raccoon constructor': The 'Raccoon' non-virtual base class "
               "constructor is called."
            << std::endl;
  std::cout << "4. 'Panda constructor': Finally, the constructor of the "
               "most-derived class 'Panda' itself is executed."
            << std::endl;
  std::cout << "This demonstrates that even though both Bear and Raccoon have "
               "initializers for ZooAnimal, only the one in the most-derived "
               "class (Panda) is used, and it is called only once."
            << std::endl;

  return 0;
}