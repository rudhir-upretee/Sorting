/*
 * Sorting.c
 *
 *  Created on: Mar 18, 2013
 *      Author: rudhir
 */
#include <string.h>
#include <stdlib.h>

extern void swap(int a[], int firsti, int secondi);
extern int chooseRandomIndex(int a[], int lowi, int highi);

#if 0
void insertionSort(int a[], int len)
    {
    int newIndex, i;
    for (newIndex = 0; newIndex < len; newIndex++)
        {
        int temp = a[newIndex];
        for (i = newIndex - 1; i >= 0; i--)
            {
            if(temp < a[i])
                {
                a[i+1] = a[i];
                }
            else
                break;
            }

        // if i < 0 or temp >= a[i]
        a[i+1] = temp;
        }
    }
#endif

void insertionSort(int a[], int len)
    {
    int newIndex, i;
    for (newIndex = 0; newIndex < len; newIndex++)
        {
        int temp = a[newIndex];
        i = newIndex -1;
        while(i >= 0 && temp < a[i])
            {
            a[i+1] = a[i];
            i--;
            }
        a[i+1] = temp;
        }
    }

void selectionSort(int a[], int len)
    {
    int sortedIndex;
    for (sortedIndex = 0; sortedIndex < len; sortedIndex++)
        {
        int minIndex = sortedIndex;
        int i;
        for (i = sortedIndex + 1; i < len; i++)
            {
            if(a[i] < a[minIndex])
                {
                minIndex = i;
                }
            }
        swap(a, sortedIndex, minIndex);
        }
    }

void mergeSort(int inArr[], int inLen, int tempArr[])
    {
    int mid = inLen/2;
    int i1 = 0, i2 = mid, tempi = 0;

    if(inLen <= 1)
        {
        return;
        }

    // Sort Recursively
    mergeSort(inArr, mid, tempArr);
    mergeSort(inArr + mid, inLen - mid, tempArr);

    // Merge the two sorted lists
    while((i1 < mid) && (i2 < inLen))
        {
        if(inArr[i1] < inArr[i2])
            {
            tempArr[tempi++] = inArr[i1++];
            }
        else
            {
            tempArr[tempi++] = inArr[i2++];
            }
        }
    while(i1 < mid)
        {
        tempArr[tempi++] = inArr[i1++];
        }
    while(i2 < inLen)
        {
        tempArr[tempi++] = inArr[i2++];
        }

    // Copy sorted array back to input array
    memcpy(inArr, tempArr, inLen*sizeof(int));
    }

int partition(int a[], int lowi, int highi, int pivoti);
void quickSort(int a[], int lowi, int highi)
    {
    int len = (highi - lowi) + 1;

    // Check termination condition
    if(len <= 1)
        {
        return;
        }

    // Choose a pivot index
    int pivoti = chooseRandomIndex(a, lowi, highi);

    // Partition using the pivot index
    int finalPivoti = partition(a, lowi, highi, pivoti);

    // Rerusively sort the sublists
    quickSort(a, lowi, finalPivoti-1);
    quickSort(a, finalPivoti+1, highi);
    }

int partition(int a[], int lowi, int highi, int pivoti)
    {
    // Save pivot to the end of the list
    swap(a, highi, pivoti);
    pivoti = highi;

    // Divide list into two parts - less than pivot and greater than pivot
    int i = lowi, j = highi-1;
    while(1)
        {
        while((i <= highi) && (a[i] < a[pivoti]))
            {
            i++;
            }
        while((j >= lowi) && (a[j] >= a[pivoti]))
            {
            j--;
            }
        if(i>=j)
            {
            break;
            }
        swap(a, i, j);
        }

    // Save pivot to its final position
    swap(a, i, pivoti);

    // Return final position
    return i;
    }
