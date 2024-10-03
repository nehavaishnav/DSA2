#include <stdio.h>

int main() {
    int arr[3][4] = {{1, 2, 3, 4}, 
                     {5, 6, 7, 8}, 
                     {9, 10, 11, 12}};
    int rows = 3, cols = 4;
    
    // Size of a word (in this case, size of an integer)
    int word_size = sizeof(int);
    
    printf("Array elements and their addresses in memory:\n");
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Theoretical address calculation (row-major order)
            int theoretical_address = (int)(arr) + ((i * cols) + j) * word_size;
            
            // Actual address using pointer arithmetic
            printf("arr[%d][%d] = %d, Address = %p, Theoretical Address = %p\n", 
                    i, j, arr[i][j], (void*)&arr[i][j], (void*)theoretical_address);
        }
    }
    
    return 0;
}
