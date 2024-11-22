#include <iostream>
using namespace std;

// Class definition for managing student height data
class Student {
    int numStudents;         // Number of students
    float* heights;          // Pointer for dynamic array of heights

public:
    // Constructor to initialize number of students and allocate memory for heights array
    Student(int num) : numStudents(num) {
        heights = new float[numStudents];  // Allocate memory dynamically
    }

    // Destructor to release allocated memory
    ~Student() {
        delete[] heights;
    }

    // Function to input heights of all students
    void inputHeights() {
        for (int i = 0; i < numStudents; i++) {
            cout << "Enter the height of student " << i + 1 << " (in cm): ";
            cin >> heights[i];
        }
    }

    // Function to calculate and return average height
    float calculateAverageHeight() {
        float totalHeight = 0.0;
        for (int i = 0; i < numStudents; i++) {
            totalHeight += heights[i];
        }
        return totalHeight / numStudents;
    }
};

int main() {
    int numStudents;

    // Prompt user for number of students
    cout << "Enter the number of students in the class: ";
    cin >> numStudents;

    // Check for invalid input
    if (numStudents <= 0) {
        cout << "Invalid number of students." << endl;
        return 1;
    }

    // Create a Student object
    Student student(numStudents);

    // Input heights for students
    student.inputHeights();

    // Calculate and display average height
    float averageHeight = student.calculateAverageHeight();
    cout << "The average height of the students in the class is: " << averageHeight << " cm" << endl;

    return 0;
}
