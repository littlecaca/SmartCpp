#include <vector>
#include <memory>
#include <iostream>

using namespace std;
/*
 * Exception handling allows independently developed parts of a program to
 * communicate about and handle problems that arise at run time. Exceptions let
 * us separate problem detection from problem resolution.
 *
 * One part of the program can detect a problem and can pass the job of
 * resolving that problem to another part of the program. The detecting part
 * need not know anything about the handling part, and vice versa.
 *
 *
 * Throwing an Exception
 *
 * The type of the thrown
 * expression, together with the current call chain, determines which handler
 * will deal with the exception.
 *
 * When a throw is executed, the statement(s) following the throw are not
 * executed. Instead, control is transferred from the throw to the matching
 * catch.
 *
 * The fact that control passes from one location to another has two important
 * implications: • Functions along the call chain may be prematurely exited. •
 * When a handler is entered, objects created along the call chain will have
 * been destroyed.
 *
 * Stack Unwinding (堆栈解退)
 *
 * continues up the chain of nested
 * function calls until a catch clause for the exception is found, or the main
 * function itself is exited without having found a matching catch.
 *
 * If no matching catch is found, the
 * program calls the library terminate function. As its name implies, terminate
 * stops execution of the program.
 *
 *
 * Objects Are Automatically Destroyed during Stack Unwinding
 *
 *
 *
 * Destructors and Exceptions
 *
 * The fact that destructors are run—--but code inside a function that frees a
 * resource may be bypassed—--affects how we structure our programs.
 *
 * The fact that destructors are run during stack unwinding affects how we write
 * destructors. During stack unwinding, an exception has been raised but is not
 * yet handled. If a new exception is thrown during stack unwinding and not
 * caught in the function that threw it, terminate is called. Because
 * destructors may be invoked during stack unwinding, they should never throw
 * exceptions that the destructor itself does not handle. That is, if a
 * destructor does an operation that might throw, it should wrap that operation
 * in a try block and handle it locally to the destructor.
 *
 * In practice, because destructors free resources, it is unlikely that they
 * will throw exceptions. All of the standard library types guarantee that their
 * destructors will not raise an exception.
 *
 *
 *
 * The Exception Object
 *
 * if the expression has class type,
 * that class must have an accessible destructor and an accessible copy or move
 * constructor. If the expression has an array or function type, the expression
 * is converted to its corresponding pointer type.
 *
 * The exception object resides in space, managed by the compiler, that is
 * guaranteed to be accessible to whatever catch is invoked. The exception
 * object is destroyed after the exception is completely handled.
 *
 * When we throw an expression, the static, compile-time type (§ 15.2.3, p. 601)
 * of that expression determines the type of the exception object. If a throw
 * expression dereferences a pointer to a base-class type, and that pointer
 * points to a derived-type object, then the thrown object is sliced down
 * (§ 15.2.3, p. 603); only the base-class part is thrown.
 *
 *
 *
 * Catching an Exception
 *
 * The type of the declaration determines what kinds of exceptions the handler can
 * catch. The type must be a complete type (§ 7.3.3, p. 278). The type can be an lvalue
 * reference but may not be an rvalue reference (§ 13.6.1, p. 532).
 *
 *
 * Best Practices
 * Ordinarily, a catch that takes an exception of a type related by inheritance
 * ought to define its parameter as a reference.
 *
 *
 * Finding a Matching Handler
 *
 * Because catch clauses are matched in the order in which they appear, programs
 * that use exceptions from an inheritance hierarchy must order their catch clauses so
 * that handlers for a derived type occur before a catch for its base type.
 *
 * The types of the exception and the catch
 * declaration must match exactly with only a few possible differences:
 * • Conversions from nonconst to const are allowed. That is, a throw of a
 *   nonconst object can match a catch specified to take a reference to const.
 * • Conversions from derived type to base type are allowed.
 * • An array is converted to a pointer to the type of the array; a function is
 *   converted to the appropriate pointer to function type.
 *
 * No other conversions are allowed to match a catch. In particular, neither the
 * standard arithmetic conversions nor conversions defined for class types are permitted.
 *
 * Note
 * Multiple catch clauses with types related by inheritance must be ordered
 * from most derived type to least derived.
 *
 *
 * Rethrow
 *
 * A rethrow is a throw that is not followed by an expression:
 *      throw;
 * An empty throw can appear only in a catch or in a function called (directly or
 * indirectly) from a catch. If an empty throw is encountered when a handler is not
 * active, terminate is called.
 *
 * A rethrow does not specify an expression; the (current) exception object is passed
 * up the chain.
 *
 * In general, a catch might change the contents of its parameter. If, after changing
 * its parameter, the catch rethrows the exception, then those changes will be
 * propagated only if the catch’s exception declaration is a reference.
 *
 *
 * The Catch-All Handler
 *
 * To catch all exceptions,
 * we use an ellipsis for the exception declaration. Such handlers, sometimes known as
 * catch-all handlers, have the form catch(...). A catch-all clause matches any type
 * of exception.
 *
 * Note
 * If a catch(...) is used in combination with other catch clauses, it must
 * be last. Any catch that follows a catch-all can never be matched.
 *
 *
 * Function try Blocks and Constructors
 *
 * In general, exceptions can occur at any point in the program’s execution. In
 * particular, an exception might occur while processing a constructor initializer.
 * Constructor initializers execute before the constructor body is entered.
 *
 * To handle an exception from a constructor initializer, we must write the constructor
 * as a `function try block`(函数尝试块). A function try block lets us associate a group of catch
 * clauses with the initialization phase of a constructor (or the destruction phase of a
 * destructor) as well as with the constructor’s (or destructor’s) function body.
 * 
 * It is worth noting that an exception can happen while initializing the constructor’s
 * parameters. Such exceptions are not part of the function try block. The function try
 * block handles only exceptions that occur once the constructor begins executing. As
 * with any other function call, if an exception occurs during parameter initialization, that
 * exception is part of the calling expression and is handled in the caller’s context.
 * 
 * 
 * Note
 * The only way for a constructor to handle an exception from a constructor
 * initializer is to write the constructor as a function try block.
 * 
 * 
 * 
 */

template <typename T>
class Blob
{
public:
    Blob(std::initializer_list<T>);

    std::shared_ptr<vector<T>> data;
};

void handle_out_of_memory(const std::exception &e)
{
    throw;
}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il)
try : data(std::make_shared<std::vector<T>>(il))
{
    /* empty body */
}
catch (const std::bad_alloc &e)
{
    handle_out_of_memory(e);
}

class my_error : public exception
{
public:
    int status;
};

class other_error : public exception
{
public:
    int status;
};

enum errCodes
{
    severeErr,
    badErr,
};

void subcall(bool throw_error = false)
{
    if (throw_error)
        throw my_error();
}

// A catch(...) is often used in combination with a rethrow expression. The catch
// does whatever local work can be done and then rethrows the exception:
void manip()
{
    try
    {
        subcall(true);
        // actions that cause an exception to be thrown
    }
    catch (my_error &e)
    {
        cout << e.what() << endl;
        throw;
    }
    catch (...)
    {
        cout << "..." << endl;
        throw;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int len = 12;
    int *p = new int[len];
    delete[] p;

    try
    {
        subcall();
    }
    catch (my_error &eObj)
    {                                      // specifier is a reference type
        eObj.status = errCodes::severeErr; // modifies the exception object
        throw;                             // the status member of the exception object is severeErr
    }
    catch (other_error &eObj)
    {                                   // specifier is a nonreference type
        eObj.status = errCodes::badErr; // modifies the local copy only
        throw;                          // the status member of the exception object is unchanged
    }

    manip();

    return 0;
}
