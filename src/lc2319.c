#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

/**
 * x矩阵问题
 * https://leetcode.cn/problems/check-if-matrix-is-x-matrix/
 */

bool isDiagram(int x, int y, int width)
{
    return x == y || (x + y) == (width - 1);
}

bool checkXMatrix(int **grid, int gridSize, int *gridColSize)
{
    int row = gridSize;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            bool beDiagram = isDiagram(i, j, row);
            if (beDiagram && grid[i][j] == 0)
            {
                return false;
            }

            if (!beDiagram && grid[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int row = 0;
    scanf("%d", &row);
    int **array = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        array[i] = (int *)malloc(row * sizeof(int));
        for (int j = 0; j < row; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    printf("isDiagram: %d", checkXMatrix(array, row, 0));
    return 0;
}
