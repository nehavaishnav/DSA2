#include <iostream>
using namespace std;

void insert_at_beg(int arr[], int size, int newElement) {
    // Shift elements to the right
    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the 0th index
    arr[0] = newElement;
}
void display(){}

int main() {
    int size = 5;
    int arr[size] = {1, 2, 3, 4, 5}; // Example array
    int newElement = 0; // Element to be inserted at the 0th index

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    shiftAndInsert(arr, size, newElement);

    cout << "Array after shifting and inserting " << newElement << ": ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
