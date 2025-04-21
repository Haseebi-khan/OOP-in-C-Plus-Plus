// GOTO STATEMENT IN C++
// At the core, the logic and working of goto is very similar to how assembly handles control flow with jumps.

#include <iostream>
#include <list>
#include <vector>
#include <ctime>
using namespace std;
#define newline '\n'

class Iterable
{
private:
    vector<int> values;

public:
    // Constructor with initialization list
    Iterable(const vector<int> &v) : values(v) {}

    // Provide begin() and end() methods
    auto begin() const -> vector<int>::const_iterator
    {
        return values.begin();
    }
    auto end() const -> vector<int>::const_iterator
    {
        return values.end();
    }
};

// Behavior	        |              Without static	                | With static
// Lifetime         |              Created each time function runs.	| Created once — stays alive till program ends.
// Memory           |              Location	Stack	                | Data Segment (global area)
// Value	        |              Lost after the function exits.	| Preserved between function calls.

// function to generate and retrun random numbers.
int *getRandom()
{

    static int r[10];

    // set the seed

    for (int i = 0; i < 10; ++i)
    {
        r[i] = i + 10;
        cout << r[i] << endl;
    }

    return r;
}

int main()
{

    // a pointer to an int.
    int *p;

    p = getRandom();

    for (int i = 0; i < 10; i++)
    {
        cout << "*(p + " << i << ") : ";
        cout << *(p + i) << endl;
    }

    list<int> number = {34, 55, 234, 45, 56, 34, 65};

    for (auto value : number)
    {
        cout << value << " ";
    }

    Iterable myIterable({1, 2, 3, 4, 5});

    for (int num : myIterable)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "begin: " << *myIterable.begin() << newline;
    cout << "end: " << *(myIterable.end() - 1) << newline;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == 1 && j == 1)
            {
                goto exitLoops;
            }
            cout << "i: " << i << ", j: " << j << endl;
        }
    }

exitLoops:
    cout << "Exited the nested loops!" << endl;

    return 0;
}
