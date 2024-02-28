#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void readMatrix(int* n, int matrix[50][50])
{

    printf("Enter the 'n' size of the matrix: ");
    scanf("%d", n);

    if (*n <= 0 || *n > 50)
    {
        printf("Invalid size\n");
        exit(EXIT_FAILURE);
    }

    printf("Matrix elements:\n");
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void readMatrix2(int* n, int* m, int matrix[50][50])
{

    printf("Enter the number of rows: ");
    scanf("%d", n);
    printf("Enter the number of columns: ");
    scanf("%d", m);

    if (*n <= 0 || *n > 50)
    {
        printf("Invalid line size\n");
        exit(EXIT_FAILURE);
    }

    if (*m <= 0 || *m > 50)
    {
        printf("Invalid column size\n");
        exit(EXIT_FAILURE);
    }



    printf("Matrix elements:\n");
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void readVector(int* n, int vector[])
{
    printf("Enter the number of elements: ");
    scanf("%d", n);

    if (*n <= 0 || *n > 50)
    {
        printf("Invalid size\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the elements of the vector:\n");
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", &vector[i]);
    }
}

bool checkPalindrome(int number)
{
    int originalNumber = number;
    int mirrored = 0, lastFigure;

    while (number != 0)
    {
        lastFigure = number % 10;
        mirrored = mirrored * 10 + lastFigure;
        number = number / 10;
    }

    return originalNumber == mirrored;
}

void palindromeElements(int n, int vector[])
{

    int vectorPalindrome[50], poz = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkPalindrome(vector[i]) == true)
        {
            vectorPalindrome[poz] = vector[i];
            poz++;

        }
    }

    if (poz <= 0)
        printf("There are no palindrome elements");
    else
    {
        printf("The palindrome elements of the vector are:\n");

        for (int i = 0; i < poz; i++)
        {

            printf("%d\n", vectorPalindrome[i]);
        }
    }

}


int matrixDiagonalsSum(int n, int matrix[][50])
{
    int mainDiagonalSum = 0, secondDiagonalSum = 0, diagonalsSum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                mainDiagonalSum += matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1)
                secondDiagonalSum += matrix[i][j];
        }
    }

    diagonalsSum = mainDiagonalSum + secondDiagonalSum;

    return diagonalsSum;

}

int elementsUnderMainDiagonalSum(int n, int matrix[][50])
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                sum = sum + matrix[i][j];
            }
        }
    }

    return sum;
}

int partOfBorder(int n, int m, int matrix[50][50])
{
    int number;
    printf("Number to search: ");
    scanf("%d", &number);

    for (int j = 0; j < m; j++)
    {
        if (matrix[0][j] == number)
        {
            return 1;
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (matrix[n - 1][j] == number)
        {
            return 1;
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (matrix[i][0] == number)
        {
            return 1;
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (matrix[i][m - 1] == number)
        {
            return 1;
        }
    }

    return 0;
}

int ascendingOrder(int n, int vector[])
{
    for (int i = 0; i < n - 1; i++)
    {
        if (vector[i] > vector[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int highestDoubleValue(int n, int m, int matrix[50][50])
{
    int maxValue = 0;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int currentElement = matrix[i][j];
            int cnt = 0;

            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < m; y++)
                {
                    if (currentElement == matrix[x][y])
                    {
                        cnt++;
                    }
                }
            }


            if (cnt >= 2 && currentElement > maxValue)
            {
                maxValue = currentElement;
            }

        }
    }

    return maxValue;
}

void determineAparitions(int n, int vector[])
{
    int i, x, positions[50];

    printf("Searched element x = ");
    scanf("%d", &x);

    int exists = 0;
    int index = 0;
    for (i = 0; i < n; i++)
    {
        if (vector[i] == x)
        {
            positions[index] = i + 1;
            index++;
            exists = 1;
        }
    }

    if (!exists)
    {
        printf("%d does not exist in the vector. \n", x);
    }
    else
    {
        printf("%d appears on pozition/pozitions: ", x);
        for (i = 0; i < index; i++)
            printf("%d ", positions[i]);
        printf("\n");
    }
}

void insertValue(int n, int vector[])
{

    int i, position, value;

    printf("New value position: ", n + 1);
    scanf("%d", &position);

    if (position < 1 || position > n + 1)
    {
        printf("Invalid position\n");
        exit(EXIT_FAILURE);
    }

    printf("Value to insert: ");
    scanf("%d", &value);

    for (i = n; i >= position; i--)
    {
        vector[i] = vector[i - 1];
    }
    vector[position - 1] = value;

    printf("The new form of the vector: \n");
    for (i = 0; i < n + 1; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int equalElements(int line[], int m)
{
    for (int i = 1; i < m; i++)
    {
        if (line[i] != line[0])
        {
            return 0;
        }
    }
    return 1;
}

void equalLines(int n, int m, int matrix[50][50])
{
    for (int i = 0; i < n; i++)
    {
        if (equalElements(matrix[i], m))
        {
            printf("The line with equal elements is line %d\n", i + 1);
        }
    }
}

void buildMatrix(int n, int matrix[50][50])
{
    printf("Enter the 'n' size of the matrix: ");
    scanf("%d", &n);

    if (n <= 0 || n > 50)
    {
        printf("Invalid size\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = i + j;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

}

int orderLinesSum(int n, int m, int matrix[50][50])
{
    int sum[50];

    for (int i = 0; i < n; i++)
    {
        sum[i] = 0;
        for (int j = 0; j < m; j++)
        {
            sum[i] += matrix[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (sum[j] > sum[j + 1])
            {
                int x = sum[j];
                sum[j] = sum[j + 1];
                sum[j + 1] = x;

                for (int k = 0; k < m; k++)
                {
                    int y = matrix[j][k];
                    matrix[j][k] = matrix[j + 1][k];
                    matrix[j + 1][k] = y;
                }
            }
        }
    }

    printf("\nThe matrix ordered by the sums of the lines:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int maxAparitionsElement(int n, int m, int matrix[50][50])
{
    int vectorElementMax[50];
    int elementMax = 0;
    int aparitionsMax = 0;
    int vectorAparitionsMax[50];
    int poz = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int currentElement = matrix[i][j];
            int currentAparitions = 0;

            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < m; y++)
                {
                    if (matrix[x][y] == currentElement)
                    {
                        currentAparitions++;

                    }
                }
            }


            if (currentAparitions >= aparitionsMax && currentAparitions != 1 && elementMax != currentElement) {
                elementMax = currentElement;
                aparitionsMax = currentAparitions;

                vectorAparitionsMax[poz] = aparitionsMax;
                vectorElementMax[poz] = elementMax;
                poz++;

            }

        }

    }

    if (aparitionsMax == 0) {
        printf("The elements are unique \n");
    }
    else
    {
        int maximum = 0;

        for (int i = poz; i >= 0; i--)
            if (vectorAparitionsMax[i] >= maximum)
            {
                maximum = vectorAparitionsMax[i];
                printf("The element/s with maximum number of aparitions: %d\n", vectorElementMax[i]);
                printf("Number of aparitions: %d\n", vectorAparitionsMax[i]);
            }

        printf("\n");
    }

    return 0;
}

int orderLinesColumns(int n, int matrix[50][50])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = 0; k < n - j - 1; k++)
            {
                if (matrix[i][k] > matrix[i][k + 1])
                {
                    int x = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = x;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = x;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = 0; k < n - j - 1; k++)
            {
                if (matrix[i][k] > matrix[i][k + 1])
                {
                    int x = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = x;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = x;
        }
    }

    printf("\nThe matrix in ascending order:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int zonesSum(int n, int matrix[50][50])
{
    int upSum = 0, rightSum = 0, leftSum = 0, downSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j && i + j < n - 1)
                upSum += matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j && i + j > n - 1)
                rightSum += matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j && i + j < n - 1)
                leftSum += matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j && i + j > n - 1)
                downSum += matrix[i][j];
        }
    }

    printf("\n The sum in the upper zone is: %d\n", upSum);
    printf("The sum in the right zone is: %d\n", rightSum);
    printf("The sum in the left zone is: %d\n", leftSum);
    printf("The sum in the bottom zone is: %d\n", downSum);

    return 0;
}

int matrixMultiplication(int m, int n, int p, int q, int matrixA[50][50], int matrixB[50][50])
{
    int result[50][50];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    printf("The result of the matrix multiplication is:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int matrixNumberMultiplication(int m, int n, int number, int matrix[50][50])
{
    

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] *= number;
        }
    }

    printf("The result of multiplying the matrix with %d is:\n", number);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int main()
{
    int opt, n, m, p, q, number, v[50], matrix[50][50], matrixA[50][50], matrixB[50][50], result;

    do
    {
        printf("\n ------Matrix and vector algorithms------\n");
        printf("\n The options are:");
        printf("\n 1. The sum of the elements on the two diagonals of a matrix");
        printf("\n 2. Finding the palindrome elements of a vector");
        printf("\n 3. The sum of the elements under the main diagonal of a matrix");
        printf("\n 4. Checking if a number is part of a matrix's border");
        printf("\n 5. Checking if the elements of a vector are in ascending order");
        printf("\n 6. Determining the highest value that appears in a matrix at least twice");
        printf("\n 7. Determining the positions of all occurances of a given value in a vector");
        printf("\n 8. Inserting a value in a vector on a given position");
        printf("\n 9. Determining how many lines in a matrix have all equal elements");
        printf("\n 10. Building a matrix of n size in which each element is equal to the sum of the indexes");
        printf("\n 11. Ordering the lines of a matrix by the sum of their elements");
        printf("\n 12. Determining the element with the max number of occurances in a matrix");
        printf("\n 13. Ordering a matrix ascendingly by lines and columns");
        printf("\n 14. Finding the sums of the elements in the 4 zones delimited by the diagonals of a matrix");
        printf("\n 15. The multiplication of two matrices");
        printf("\n 16. Multiplying a matrix with a number");
        printf("\n 0. EXIT");
        printf("\n Your option is: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            readMatrix(&n, matrix);
            printf("\nThe sum of the elements on the two diagonals: %d\n", matrixDiagonalsSum(n, matrix));
            break;

        case 2:
            readVector(&n, v);
            palindromeElements(n, v);
            break;

        case 3:
            readMatrix(&n, matrix);
            printf("\nThe sum of the elements under the main diagonal: %d\n", elementsUnderMainDiagonalSum(n, matrix));
            break;

        case 4:
            readMatrix2(&n, &m, matrix);
            result = partOfBorder(n, m, matrix);
            if (result == 1)
                printf("The number is part of the matrix's border.\n");
            else
                printf("The number is not part of the matrix's border.\n");
            break;

        case 5:
            readVector(&n, v);
            result = ascendingOrder(n, v);
            if (result == 1)
                printf("The vector is in ascending order. \n");
            else
                printf("The vector is not in ascending order. \n");
            break;

        case 6:
            readMatrix2(&n, &m, matrix);
            result = highestDoubleValue(n, m, matrix);
            if (result != 0)
                printf("The highest value that appears in thea matrix at least twice: %d\n", result);
            else
                printf("All values are unique.\n");
            break;

        case 7:
            readVector(&n, v);
            determineAparitions(n, v);
            break;

        case 8:
            readVector(&n, v);
            insertValue(n, v);
            break;

        case 9:
            readMatrix2(&n, &m, matrix);
            equalLines(n, m, matrix);
            break;

        case 10:
            buildMatrix(n, matrix);
            break;

        case 11:
            readMatrix2(&n, &m, matrix);
            orderLinesSum(n, m, matrix);
            break;

        case 12:
            readMatrix2(&n, &m, matrix);
            maxAparitionsElement(n, m, matrix);
            break;

        case 13:
            readMatrix(&n, matrix);
            orderLinesColumns(n, matrix);
            break;

        case 14:
            readMatrix(&n, matrix);
            zonesSum(n, matrix);
            break;

        case 15:
            readMatrix2(&m, &n, matrixA);
            readMatrix2(&p, &q, matrixB);
            matrixMultiplication(m, n, p, q, matrixA, matrixB);
            break;

        case 16:
            printf("Insert the number for the multiplication: ");
            scanf("%d", &number);
            readMatrix2(&m, &n, matrix);
            matrixNumberMultiplication(m, n, number, matrix);
            break;

        case 0:
            printf("\n You have chosen to leave the app!\n");
            break;

        default:
            printf("\n Invalid option!");
            break;
        }
    } while (opt != 0);

    return 0;
}