/*
 * Best Practices
 * Classes that define increment or decremnet operators should
 * define both the prefix and postfix versions. These operators 
 * usually should be defined as members.
 * 
 * To be consistent with the built-in operators, the postfix operators
 * should return the old value. That value is returned as a value, not a
 * reference.
 * 
 * 
 * 
 * Calling the Postfix Operators Explicitly
 * 
 * The postfix versions take an extra parameter of type int.
 * We can explicitly call an overloaded operator as an alternative
 * to using it as an operator in an expression. We can pass
 * a value the integer argument.
 */