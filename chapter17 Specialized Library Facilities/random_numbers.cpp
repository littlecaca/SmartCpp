#include <ctime>
#include <random>
#include <iostream>

using namespace std;

/*
 * Random Number Library Components
 * 
 * Engine   : Types that generate a sequence of random unsigned integers
 * Distribution : Types that use an engine to return numbers according to a particular probability
 *                distribution.
 * 
 * Random Number Engine Operations
 * 
 * Engine e;
 * Engine e(s);
 * e.seed(s);
 * e.min();
 * e.max();
 * Engine::result_type;
 * e.discard(u);
 * 
 * Note
 * When we refer to a random-number generator, we mean the combination
 * of a distribution object with an engine.
 * 
 * Warning
 * A given random-number generator always produces the same sequence of
 * numbers. A function with a local random-number generator should make that
 * generator (both the engine and distribution objects) static. Otherwise, the
 * function will generate the identical sequence on each call.
 * 
 * 
 * Warning
 * Using time as a seed usually doesn’t work if the program is run repeatedly
 * as part of an automated process; it might wind up with the same seed
 * several times.
 * 
 * 
 * Distribution Opearations
 * 
 * Dist d;  // explicit constructors
 * d(e)
 * d.min()
 * d.max()
 * d.reset()
 * 
 * 
 * Generating Random Real Numbers
 * 
 * With the new library facilities, we can easily obtain a floating-point random number.
 * We define an object of type uniform_real_distribution and let the library
 * handle mapping random integers to random floating-point numbers.
 * 
 * 
 * Using the Distribution’s Default Result Type
 * 
 * // empty <> signify we want to use the default result type
 * uniform_real_distribution<> u(0,1); // generates double by default
 * 
 * 
 * Warning
 * Because engines return the same sequence of numbers (§ 17.4.1, p. 747), it
 * is essential that we declare engines outside of loops. Otherwise, we’d create
 * a new engine on each iteration and generate the same values on each
 * iteration. Similarly, distributions may retain state and should also be defined
 * outside loops.
 * 
 * 
 */

bool play(bool first)
{
    return first;
}

int main(int argc, char const *argv[])
{
    /* code */
    default_random_engine e;
    // for (size_t i = 0; i < 10; ++i)
    //     cout << e() << endl;
    e.seed(clock());

    // uniformly distributed from 0 to 9 inclusive
    uniform_int_distribution<unsigned> u(0,9);
    for (size_t i = 0; i < 10; ++i)
    // u uses e as a source of numbers
    // each call returns a uniformly distributed value in the specified range
        cout << u(e) << " ";
    
    // uniformly distributed from 0 to 1 inclusive
    // uniform_real_distribution<double> u_real(0,1);
    uniform_real_distribution<> u_real(0,1);
    for (size_t i = 0; i < 10; ++i)
        cout << u_real(e) << " ";

    /*
     * Normal Distribution
     */
    normal_distribution<> n(4,1.5);         // mean 4, standard deviation 1.5
    vector<unsigned> vals(9);               // nine elements each 0
    for (size_t i = 0; i != 200; ++i) {
        unsigned v = lround(n(e));          // round to the nearest integer
        if (v < vals.size())                // if this result is in range
        ++vals[v];                          // count how often each number appears
    }
    for (size_t j = 0; j != vals.size(); ++j)
        cout << j << ": " << string(vals[j], '*') << endl;
    
    /*
     * Bernoulli Distribution
     * which is an ordinary class, not a template.
     * This distribution always returns a bool value. It returns true with a given
     * probability. By default that probability is .5.
     */
    string resp;
    bernoulli_distribution b; // 50/50 odds by default
    do {
        bool first = b(e); // if true, the program will go first
        cout << (first ? "We go first" : "You get to go first") << endl;
        // play the game passing the indicator of who goes first
        cout << ((play(first)) ? "sorry, you lost" : "congrats, you won") << endl; 
        cout << "play again? Enter 'yes' or 'no'" << endl;
    } while (cin >> resp && resp[0] == 'y');

    return 0;
}
