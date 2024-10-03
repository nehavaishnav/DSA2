#include <stdio.h>

int arr1[3][3];
int arr2[3][3];
int result[3][3];
int main() {
    
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter the element at index [%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);  // Corrected the scanf usage
        }
    }
        printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter the element at index [%d][%d]: ", i, j);
            scanf("%d", &arr2[i][j]);  // Corrected the scanf usage
        }
    } 
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
           result[i][j] = arr1[i][j]+arr2[i][j];
        }
    }
    printf("result is: %d",result);
    // Optional: Display the entered matrix
    printf("\nThe first matrix is:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
