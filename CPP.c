
#include <stdio.h>

int main() {
    int a[3][3], b[3][3], res[3][3];
    int n, i, j, k, choice;
    int det;

    printf("Enter matrix size (2 or 3): ");
    scanf("%d", &n);

    if (n != 2 && n != 3) {
        printf("Invalid matrix size!\n");
        return 0;
    }

    printf("\nEnter elements of first matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("\nEnter elements of second matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&b[i][j]);

    printf("\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Transpose\n5.Determinant\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice) {
        case 1:
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    res[i][j] = a[i][j] + b[i][j];
                }
            }
            printf("\nAddition:\n");
            for(i=0;i<n;i++){
                for(j=0;j<n;j++)
                    printf("%d ", res[i][j]);
                printf("\n");
            }
            break;

        case 2:
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    res[i][j] = a[i][j] - b[i][j];
                }
            }
            printf("\nSubtraction:\n");
            for(i=0;i<n;i++){
                for(j=0;j<n;j++)
                    printf("%d ", res[i][j]);
                printf("\n");
            }
            break;

        case 3:
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    res[i][j]=0;
                    for(k=0;k<n;k++)
                        res[i][j]+=a[i][k]*b[k][j];
                }
            }
            printf("\nMultiplication:\n");
            for(i=0;i<n;i++){
                for(j=0;j<n;j++)
                    printf("%d ", res[i][j]);
                printf("\n");
            }
            break;

        case 4:
            printf("\nTranspose of first matrix:\n");
            for(i=0;i<n;i++){
                for(j=0;j<n;j++)
                    printf("%d ", a[j][i]);
                printf("\n");
            }
            printf("\nTranspose of second matrix:\n");
            for(i=0;i<n;i++){
                for(j=0;j<n;j++)
                    printf("%d ", b[j][i]);
                printf("\n");
            }
            break;

        case 5:
            if(n==2){
                det = a[0][0]*a[1][1] - a[0][1]*a[1][0];
                printf("\nDeterminant of first matrix = %d\n", det);
                det = b[0][0]*b[1][1] - b[0][1]*b[1][0];
                printf("Determinant of second matrix = %d\n", det);
            }
            else {
                det = a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])
                    - a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])
                    + a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
                printf("\nDeterminant of first matrix = %d\n", det);

                det = b[0][0]*(b[1][1]*b[2][2]-b[1][2]*b[2][1])
                    - b[0][1]*(b[1][0]*b[2][2]-b[1][2]*b[2][0])
                    + b[0][2]*(b[1][0]*b[2][1]-b[1][1]*b[2][0]);
                printf("Determinant of second matrix = %d\n", det);
            }
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}
