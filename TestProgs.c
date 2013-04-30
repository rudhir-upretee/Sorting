/*
 ============================================================================
 Name        : TestProgs.c
 Author      : 
 Version     :
 Copyright   :
 Description : Main for testing sorting algorithms
 ============================================================================
 */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void quickSort(int a[], int lowi, int highi);
extern void mergeSort(int inArr[], int inSize, int tempArr[]);
extern void insertionSort(int a[], int len);
extern void selectionSort(int a[], int len);
extern void insertionSort2D(int** a, int nCols, int len);
extern void printArray(int a[], int len);
extern void printArray2D(int** a, int nRows, int nCols);
extern void createRandom2DArray(int** a, int nCols, int len);
extern void createRandomArray(int a[], int len);


void printArray(int a[], int len);

int main(void)
    {
    int size = 25;
    int* a = malloc(sizeof(int) * size);
    int* temp = malloc(sizeof(int) * size);

    printf("----> 1D Array Sorting <----\n\n");
    printf("insertionSort\n");
    createRandomArray(a, size);
    printArray(a, size);
    insertionSort(a, size);
    printArray(a, size);
    printf("\n");

    printf("selectionSort\n");
    createRandomArray(a, size);
    printArray(a, size);
    selectionSort(a, size);
    printArray(a, size);
    printf("\n");

    printf("mergeSort\n");
    createRandomArray(a, size);
    printArray(a, size);
    mergeSort(a, size, temp);
    printArray(a, size);
    printf("\n");

    printf("quickSort\n");
    createRandomArray(a, size);
    printArray(a, size);
    quickSort(a, 0, size-1);
    printArray(a, size);
    printf("\n");

    printf("----> 2D Array Sorting <----\n\n");
    int rows = 5, cols = 5;
    int** a2D = malloc(sizeof(int*) * rows);
    int i;
    for(i = 0; i < rows; i++)
        {
        a2D[i] = malloc(sizeof(int) * cols);
        }

    printf("insertionSort\n");
    createRandom2DArray(a2D, cols, size);
    printArray2D(a2D, rows, cols);
    insertionSort2D(a2D, cols, size);
    printArray2D(a2D, rows, cols);
    printf("\n");

    return EXIT_SUCCESS;
    }

