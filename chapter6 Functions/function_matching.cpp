

/*
 * Determining the Candidate and Viable Functions
 * 
 * First: finding the candidate functions
 * 
 * A candidate function is a function with the same name as the called function and for
 * which a declaration is visible at the point of the call. 
 * 
 * Second: selecting the viable functions
 * 
 * Then selects from the set of candidate functions those functions that can be called with
 * the arguments in the given call, which means the number and type of parameters must match.
 * The selected functions are the viable funcitons.
 * 
 * Third: finding the best match, if any
 * 
 * The idea is that the closer the types of the argument and parameter are to each other,
 * the better the match. A exact match is better than a match that requires a conversion.
 * 
 * If there are two or more arguments, then there is an overall best match if there is one
 * and only one function for which "the match for each argument is no worse than the match
 * the match required by any other viable function" and "there is at least one argument for
 * which the match is better than the match provided by any other viable function". If after
 * looking at each argument there is no signle function that is preferable, then the call
 * is in error. The compiler will complain that the call is ambiguous.
 * 
 * Casts should not be needed to call an overloaded function. The need for a cast suggests
 * that the parameter sets are designed poorly.
 * 
 * 
 * Argument Type Conversions
 * 
 * Converisons are ranked as follows:
 * 
 * 1.An exact match which happens when "the argument and parameter types are identical"
 * or "the argument is converted from an array or function type to the corresponding
 * pointer type." or "a top-level const is added to or discarded from the argument".
 * 
 * 2.Match through a (low-level) const conversion.
 * 
 * 3.Match through a promotion.
 * 
 * 4.Match through an arithmetic or pointer conversion.
 * 
 * 5.Match through a class-type conversion.
 * 
 * 
 * Promotion or Arithemetic Conversion
 * 
 * The small integral types always promote to `int` or to larger integral type. All
 * the arithmetic conversions are treated as equivalent to each other. The converison
 * from `int` to `unsigned int`, for example, does not take precedence over the conversion
 * from `int` to `double`.
 */



int f(int, int);
int f(double, double);
void manip(long);
void manip(float);

void manip(long i) {
    i = 3;
}
int main(int argc, char const *argv[])
{
    // the compiler will reject this call because it is ambiguous
    // f(3, 3.1);

    // all arithmetic conversions are treated as equivalent to each other
    // manip(3.14); // error: ambiguous call
    manip((long)5);
    return 0;
}


int f(int i, int j) {
    return i * j;
}

int f(double i, double j) {
    return static_cast<int>(i * j);
}


