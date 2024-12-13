#include <iostream>
using namespace std;

class Demo {
private:
    const int constantMember;          // Constant data member
    static int staticMember;           // Static data member

public:
    Demo(int value) : constantMember(value) { // Initialize constant member using initializer list
        cout << "Constructor called. Constant member initialized to " << constantMember << endl;
    }

    void display() const {             // Constant member function
        cout << "Constant member: " << constantMember << endl;
        cout << "Static member: " << staticMember << endl;
    }

    static void setStaticMember(int value) { // Static member function
        staticMember = value;
        cout << "Static member updated to " << staticMember << endl;
    }

    static int getStaticMember() {     // Static member function
        return staticMember;
    }
};

// Definition and initialization of static data member
int Demo::staticMember = 0;

int main() {
    Demo obj1(10);                     // Object creation with constant member initialization
    obj1.display();

    Demo::setStaticMember(100);        // Call static member function to modify static data member

    Demo obj2(20);                     // Another object creation
    obj2.display();                    // Display values for the second object

    cout << "Static member (accessed without object): " << Demo::getStaticMember() << endl;

    return 0;
}
