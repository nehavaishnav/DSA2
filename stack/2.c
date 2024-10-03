#include <stdio.h>

// Function to move disks
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case: if there's only one disk, move it from source to destination
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary, using destination as auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move the n-1 disks from auxiliary to destination, using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n; // Number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Call the towerOfHanoi function with n disks, source 'A', destination 'C', and auxiliary 'B'
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}
