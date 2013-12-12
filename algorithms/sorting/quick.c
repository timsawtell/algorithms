//
//  quick.c
//  algorithms
//
//  Created by Tim Sawtell on 10/12/2013.
//  Copyright (c) 2013. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "merge.h"
#include "constants.h"

/*
 Quicksort is a divide and conquer algorithm. Quicksort first divides a large list into two smaller sub-lists: 
 the low elements and the high elements. 
 Quicksort can then recursively sort the sub-lists. The steps are:
 1. Pick an element, called a pivot, from the list.
 
 2. Reorder the list so that all elements with values less than the pivot come before the pivot, while all elements
 with values greater than the pivot come after it (equal values can go either way). After this partitioning, the 
 pivot is in its final position. This is called the partition operation.
 
 3. Recursively apply the above steps to the sub-list of elements with smaller values and separately the sub-list of elements with greater values.
 The base case of the recursion are lists of size zero or one, which never need to be sorted.
 */

void quicksort(int numbers[], int leftIndex, int rightIndex)
{
    numberOfIterations++;
    int pivot, leftSaveIndex, rightSaveIndex;
    
    leftSaveIndex = leftIndex;
    rightSaveIndex = rightIndex;
    pivot = numbers[leftIndex];
    while (leftIndex < rightIndex) {
// logging
//        for (int i=0; i < SIZE_OF_ARRAY; i++) {
//            if (i == pivot) printf("[");
//            printf("%d,", numbers[i]);
//            if (i == pivot) printf("]");
//        }
//        printf(" Pivot: %d, leftIndex: %d, rightIndex: %d\n", pivot, leftIndex, rightIndex);
        while ((numbers[rightIndex] >= pivot) && (leftIndex < rightIndex)) {
            rightIndex--;
        }
        if (leftIndex != rightIndex) {
            numberOfInnerIterations++;
            numbers[leftIndex] = numbers[rightIndex];
            leftIndex++;
        }
        
        while ((numbers[leftIndex] <= pivot) && (leftIndex < rightIndex)) {
            leftIndex++;
        }
        
        if (leftIndex != rightIndex){
            numberOfInnerIterations++;
            numbers[rightIndex] = numbers[leftIndex];
            rightIndex--;
        }
    }
    numbers[leftIndex] = pivot;
    pivot = leftIndex;
    leftIndex = leftSaveIndex;
    rightIndex = rightSaveIndex;
    if (leftIndex < pivot)
        quicksort(numbers, leftIndex, pivot-1);
    if (rightIndex > pivot)
        quicksort(numbers, pivot+1, rightIndex);
}

int *sort_quick()
{
    numberOfIterations = 0;
    numberOfInnerIterations = 0;
    static int tmpArray[SIZE_OF_ARRAY];
    memcpy(tmpArray, randomArray, SIZE_OF_ARRAY * sizeof(int));
    quicksort(tmpArray, 0, SIZE_OF_ARRAY-1);
    return tmpArray;
}