#include <iostream>
using namespace std;

class MyClass {
public:
    int* data;

    MyClass(int val) { 
        data = new int(val); 
        cout << "Normal constructor\n";
    }

    // Move constructor
    MyClass(MyClass&& other) {
        cout << "Move constructor\n";
        data = other.data;     
        other.data = nullptr;  
    }

    // Copy constructor
    MyClass(const MyClass& other) {
        cout << "Copy constructor\n";
        data = new int(*other.data);
    }

    ~MyClass() {
        delete data;
    }
};

int main()
{
    MyClass A(10);            
    MyClass B(std::move(A));  

    if (A.data)
        cout << "A: " << *(A.data) << endl;
    else
        cout << "A has no data" << endl;

    cout << "B: " << *(B.data) << endl;

    return 0;
}
