/*
 * Sorting.c
 *
 *  Created on: Mar 18, 2013
 *      Author: rudhir
 */

/*
 * All the algorithms are same as 1D Array sorting. Only the indexing is
 * changed. getRow() and getCol() is used to convert 1D indexing to 2D
 * indexing.
 */
#include <string.h>
#include <stdlib.h>

extern int getRow(int colsPerRow, int n);
extern int getCol(int colsPerRow, int n);

void insertionSort2D(int** a, int nCols, int len)
    {
    int i;
    for (i = 0; i < len; i++)
        {
        int temp = a[getRow(nCols, i)][getCol(nCols, i)];
        int j;

        for (j = i - 1; j >= 0; j--)
            {
            if (a[getRow(nCols, j)][getCol(nCols, j)] <= temp)
                break;
            a[getRow(nCols, j+1)][getCol(nCols, j+1)] = a[getRow(nCols, j)][getCol(nCols, j)];
            }
        a[getRow(nCols, j+1)][getCol(nCols, j+1)] = temp;
        }
    }
