// // A union is used when you want to store different types of data in the same memory location,
// // but only one value at a time.

// // struct	                                        union
// // All members have their own memory.	            All members share the same memory.
// // Size = sum of all members.	                    Size = size of the largest member.
// // All members can hold values at the same time.	Only one member holds a valid value at a time.

// #include <iostream>
// #include <cstring>

// using namespace std;

// union Data
// {
//     int intValue;      // Member for integer value
//     float floatValue;  // Member for float value
//     char strValue[50]; // Member for string value
// };

// int main()
// {
//     // Defining a union variable
//     Data data;

//     data.intValue = 2006;
//     cout << "TutorialsPoint: Founded in " << data.intValue << endl;

//     // overwrites the previous integer value
//     data.floatValue = 5.75f;
//     cout << "My Float value is: " << data.floatValue << endl;

//     // overwrites the previous float value
//     strcpy(data.strValue, "Hello TutorialsPoint Learner");
//     cout << data.strValue << endl;

//     // ========================================== Important ====================================================
//     // you're telling cout to treat the same memory bytes as an integer, even though a string was written there.
//     // So it prints an unexpected / garbage value (which is technically the first 4 bytes of your string, interpreted as an int).
//     // =========================================================================================================

//     // Undefined behavior
//     cout << "Integer after string assignment: " << data.intValue << endl;
//     cout << "data.float value: " << data.floatValue << endl;
//     cout << "data.str value: " << data.strValue << endl;

//     // =========================================================================================================

//     data.intValue = 2006;
//     cout << "Integer after string assignment: " << data.intValue << endl;
//     cout << "data.str value: " << data.strValue << endl;

//     return 0;
// }

// // Context	          Why union works here
// // Date Storage	      You might store day, month, or year — but only one active at a time (e.g., for flexible parsing or display).
// // Time Structure	  You might use hour, minute, second — but if your program stores different time formats (12h vs 24h) —
// //                    a union can save memory.
// // Network Packets	  Different protocols use the same memory for TCP, UDP, ICMP headers.

// #include <iostream>
// using namespace std;

// union Time
// {
//     int hour;
//     int minute;
//     int second;
// };

// int main()
// {
//     Time t;

//     t.hour = 12; // Only this is valid now
//     cout << "Hour: " << t.hour << endl;

//     t.minute = 45; // Now this overwrites hour
//     cout << "Minute: " << t.minute << endl;

//     t.second = 30; // Overwrites previous
//     cout << "Second: " << t.second << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

// Define a union to hold one type of time unit at a time
union DateOrTime
{
    struct
    {
        int day;
        int month;
        int year;
    } date;

    struct
    {
        int hour;
        int minute;
        int second;
    } time;
};

// Wrap the union in a struct to manage its type
struct Event
{
    bool isDate;      // true = date, false = time
    DateOrTime value; // union instance
};

int main()
{
    Event e1, e2;

    cout << sizeof(e1) << endl;

    // Store a date
    e1.isDate = true;
    e1.value.date.day = 21;
    e1.value.date.month = 4;
    e1.value.date.year = 2025;

    // Store a time
    e2.isDate = true;
    e2.value.time.hour = 14;
    e2.value.time.minute = 33;
    e2.value.time.second = 52;

    // Print date
    if (e1.isDate)
    {
        cout << "Event 1 Date: "
             << e1.value.date.day << "-"
             << e1.value.date.month << "-"
             << e1.value.date.year << endl;
    }

    // Print time
    if (e2.isDate)
    {
        cout << "Event 2 Time: "
             << e2.value.time.hour << ":"
             << e2.value.time.minute << ":"
             << e2.value.time.second << endl;
    }

    return 0;
}
