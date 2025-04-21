#include <iostream>
using namespace std;

enum class move1
{
    upMove = 'w',
    downMove = 's',
    leftMove = 'a',
    rightMove = 'd'
};

enum moves
{
    upMove = 8,
    downMove = 5,
    leftMove = 4,
    rightMove = 6
};

#define newline '\n'

// Specifying a Custom Underlying Type for an enum class

enum class Status : unsigned int
{
    ok = 1,
    error = 0,
    undifine_value = 2
};

int main()
{
    move1 gameMoves;

    cout << static_cast<char>(move1::upMove) << newline;

    bool found = false;
    int arr[10] = {34, 54, 23, 4, 23, 43, 4, 34, 23, 43};
    cout << "Enter the value for Sreaching: ";
    int val = 0;
    cin >> val;
    cout << val << newline;

    Status status;

    for (auto value : arr)
    {
        if (value == val)
        {
            found = true;
            status = Status::ok;
            break;
        }
        else
        {
            status = Status::error;
        }
    }

    // const_cast (Remove const or volatile)
    // cpp
    // Copy
    // Edit
    // const int a = 42;
    // int* ptr = const_cast<int*>(&a);  // Removes const
    // ⚠️ Dangerous if you modify the value after casting away const. Use with care!

    if (found)
    {
        cout << "Detect: " << (int)status << newline;
    }
    else
    {
        cout << "Detect: " << (int)status << newline;
    }

    return 0;
}
