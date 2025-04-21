#include <iostream>
using namespace std;

enum Day
{
    mon = 1,
    tues = 2,
    wednes = 3,
    thur = 4,
    fri = 5,
    sat = 6,
    sun
};

#define newline "\n"

enum RGB
{
    red,
    green,
    blue // 0, 1, 2
};

void check_colors(RGB colors)
{
    switch (colors)
    {
    case red:
        cout << "Color is Red: " << RGB::red << newline;
        break;
    case green:
        cout << "Color is Red: " << RGB::green << newline;
        break;
    case blue:
        cout << "Color is Red: " << RGB::blue << newline;
        break;
    default:
        cout << "Invaild Formate." << newline;
        break;
    }
}

int main()
{

    cout << Day::mon << newline;
    cout << Day::sun << newline;

    RGB mycolor = RGB::red;
    int colorValue = mycolor; // Implicit conversion to int

    cout << mycolor << newline;

    check_colors(mycolor);
    RGB mycolor2 = RGB::blue;

    check_colors(mycolor2);

    return 0;
}
