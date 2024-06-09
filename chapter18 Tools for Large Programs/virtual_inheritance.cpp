/**
 * Virtual Inheritance
 *
 * Although the derivation list of a class may not include the same base class more than
 * once, a class can inherit from the same base class more than once.
 *
 * It might inherit the same base indirectly from two of its own direct base classes,
 * or it might inherit a particular class directly and indirectly through another of its base classes.
 *
 * By default, a derived object contains a separate subpart corresponding to each class
 * in its derivation chain. If the same base class appears more than once in the
 * derivation, then the derived object will have more than one subobject of that type.
 *
 * Virtual inheritance lets a class specify that it is willing to share its base class. The shared
 * base-class subobject is called a virtual base class. Regardless of how often the
 * same virtual base appears in an inheritance hierarchy, the derived object contains only
 * one, shared subobject for that virtual base class.
 *
 *
 * A Different Panda Class
 *
 * The virtual derivation has to be made before the need for it appears. For
 * example, in our classes, the need for virtual inheritance arises only when we define
 * Panda. However, if Bear and Raccoon had not specified virtual on their
 * derivation from ZooAnimal, the designer of the Panda class would be out of luck.
 *
 * In practice, the requirement that an intermediate base class specify its inheritance
 * as virtual rarely causes any problems.
 *
 * Note
 * Virtual derivation affects the classes that subsequently derive from a class
 * with a virtual base; it doesn’t affect the derived class itself.
 *
 *
 * Using a Virtual Base Class
 *
 * We specify that a base class is virtual by including the keyword virtual in the
 * derivation list.
 * 
 * The virtual specifier states a willingness to share a single instance of the named
 * base class within a subsequently derived class. There are no special constraints on a
 * class used as a virtual base class.
 * 
 * 
 * Normal Conversions to Base Are Supported
 * 
 * An object of a derived class can be manipulated (as usual) through a pointer or a
 * reference to an accessible base-class type regardless of whether the base class is
 * virtual.
 * 
 * 
 * Visibility of Virtual Base-Class Members
 * 
 * Because there is only one shared subobject corresponding to each shared virtual base,
 * members in that base can be accessed directly and unambiguously. Moreover, if a
 * member from the virtual base is overridden along only one derivation path, then that
 * overridden member can still be accessed directly. If the member is overridden by more
 * than one base, then the derived class generally must define its own version as well.
 * 
 * 
 * 
 * Constructors and Virtual Inheritance
 * 
 * In a virtual derivation, the virtual base is initialized by the most derived constructor.
 * 
 * 
 * How a Virtually Inherited Object Is Constructed
 * 
 * The construction order for an object with a virtual base is slightly modified from the
 * normal order: The virtual base subparts of the object are initialized first, using
 * initializers provided in the constructor for the most derived class.
 * 
 * If the Panda constructor does not explicitly initialize the ZooAnimal base class,
 * then the ZooAnimal default constructor is used. If ZooAnimal doesn’t have a
 * default constructor, then the code is in error.
 * 
 * Note
 * Virtual base classes are always constructed prior to nonvirtual base classes
 * regardless of where they appear in the inheritance hierarchy.
 * 
 * 
 * 
 * Constructor and Destructor Order
 * 
 * A class can have more than one virtual base class. In that case, the virtual subobjects
 * are constructed in left-to-right order as they appear in the derivation list.
 * 
 * The direct base classes are examined in declaration order to determine whether
 * there are any virtual base classes. If so, the virtual bases are constructed first,
 * followed by the nonvirtual base-class constructors in declaration order.
 * 
 * The same order is used in the synthesized copy and move constructors, and
 * members are assigned in this order in the synthesized assignment operators. As usual,
 * an object is destroyed in reverse order from which it was constructed. The
 * TeddyBear part will be destroyed first and the ZooAnimal part last.
 */

class ZooAnimal
{
};

// the order of the keywords public and virtual is not significant
class Raccoon : public virtual ZooAnimal
{ /* ... */
};

class Bear : virtual public ZooAnimal
{ /* ... */
};


