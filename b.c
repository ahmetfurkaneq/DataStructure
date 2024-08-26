#include <stdio.h>

int main()
{

    int i, j;
    int rowson, rowbas, gecis;
    int colson, colbas;
    printf("Satir sayisi ne olucak:");
    scanf("%d", &i);
    printf("Sutun sayisi ne olucak:");
    scanf("%d", &j);

    int myNumber[i][j];

    for (int row = 0; row < i; row++)
    {
        for (int col = 0; col < j; col++)
        {
            printf("myNumber[%d][%d]: ", row, col);
            scanf("%d", &myNumber[row][col]);
        }
    }
    rowson = i - 1;
    colson = j - 1;
    for (rowbas = 0; rowbas < (i / 2)+1 ; rowbas++)
    {
        for (colbas = 0; colbas < (j / 2)+1 ; colbas++)
        {
            gecis = myNumber[rowson][colson];
            myNumber[rowson][colson] = myNumber[rowbas][colbas];
            myNumber[rowbas][colbas] = gecis;

           
            colson -= 1;
        }
        colson = j - 1;
        rowson -= 1;
    }

    for (int row = 0; row < i; row++)
    {
        printf("Row[%d]", row);
        for (int col = 0; col < j; col++)
        {
            printf(" %d ", myNumber[row][col]);
        }
    }
}