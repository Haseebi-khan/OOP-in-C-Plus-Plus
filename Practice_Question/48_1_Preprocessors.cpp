#include <iostream>
using namespace std;

// Why do we use the Preprocessor?

// The preprocessor allows us to define constants, macros, and include external files
// before the actual compilation starts. For example, using #define, we can assign
// a name to a constant value (like a file path or number) so we don't have to repeat
// the same value multiple times in the code. This makes the code easier to maintain,
// read, and update.

#define newline '\n'
#define codeowner "Haseeb khan"
#define length 10
#define width 10

int main()
{
    cout << codeowner << newline;
    double result = length * width;
    cout << "Result: " << result << newline;

    double userlength = 0;
    double userwidth = 0;

    cout << "Enter the Length: ";
    cin >> userlength;
    cout << "Enter the width: ";
    cin >> userwidth;

    double userResult = userlength * userwidth;

    cout << "User Result: " << userResult << newline;

    return 0;
}
///////////////////////////////////////////////////////////////////////////////
// PS D:\Codes\Python\OOP-in-C-Plus-Plus\Practice_Question> ./run.exe
// Haseeb khan
// Result: 100
// Enter the Length: 34
// Enter the width: 23
// User Result: 782
// PS D:\Codes\Python\OOP-in-C-Plus-Plus\Practice_Question>
///////////////////////////////////////////////////////////////////////////////
