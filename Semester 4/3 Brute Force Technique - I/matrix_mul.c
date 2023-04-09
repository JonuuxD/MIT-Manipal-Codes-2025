#include <stdio.h>

int main()

{

    int m, n, p, q, i, j, k;
    int opcount = 0;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &m, &n);
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &p, &q);

    if(n != p) // Check if the matrices can be multiplied

    {

        printf("The matrices cannot be multiplied.\n");

        return 0;

    }

    

    // Initialize the matrices with user input

    int matrix1[m][n], matrix2[p][q], result[m][q];
    printf("Enter the elements of the first matrix:\n");
    for(i = 0; i < m; i++)  {

        for(j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");

    for(i = 0; i < p; i++) {
        for(j = 0; j < q; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    // Perform matrix multiplication
    for(i = 0; i < m; i++)  {
        for(j = 0; j < q; j++) {
            result[i][j] = 0;
            for(k = 0; k < n; k++) {

                result[i][j] += matrix1[i][k] * matrix2[k][j];
                opcount++;
            }
        }
    }
    // Print the result
    printf("Resultant matrix:\n");

    for(i = 0; i < m; i++) {
        for(j = 0; j < q; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
   }
    printf("\n Opcount = %d", opcount);
    return 0;
}
