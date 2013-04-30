/*
 * Utils.c
 *
 *  Created on: Mar 18, 2013
 *      Author: rudhir
 */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getRow(int nCols, int n)
    {
    return (n/nCols);
    }

int getCol(int nCols, int n)
    {
    return (n%nCols);
    }

void createRandomArray(int a[], int len)
    {
    int i;
    srand(time(NULL));
    for (i = 0; i < len; i++)
        {
        a[i] = rand() % len;
        }
    }

void createRandom2DArray(int** a, int nCols, int len)
    {
    int i;
    srand(time(NULL));

    for (i = 0; i < len; i++)
        {
        a[getRow(nCols, i)][getCol(nCols, i)] = rand() % len;
        }

    }

int chooseRandomIndex(int a[], int lowi, int highi)
    {
    int len = highi - lowi + 1;
    srand(time(NULL));
    int rIndex = lowi + (rand() % len);
    return rIndex;
    }

void swap(int a[], int si, int mi)
    {
    int temp = a[si];
    a[si] = a[mi];
    a[mi] = temp;
    }

void printArray(int a[], int len)
    {
    int i;
    for (i = 0; i < len; i++)
        {
        printf("%d ", a[i]);
        }
    printf("\n");
    }

void printArray2D(int** a, int nRows, int nCols)
    {
    int i,j;
    for (i = 0; i < nRows; i++)
        {
        for (j = 0; j < nCols; j++)
            {
            printf("%2d ", a[i][j]);
            }
        printf("\n");
        }
    printf("\n");
    }

