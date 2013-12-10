//
//  quick.c
//  algorithms
//
//  Created by Tim Sawtell on 10/12/2013.
//  Copyright (c) 2013 GJI. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "merge.h"
#include "constants.h"

void quicksort(int numbers[], int left, int right)
{
    numberOfIterations++;
    int pivot, l_hold, r_hold;
    
    l_hold = left;
    r_hold = right;
    pivot = numbers[left];
    while (left < right) {
        while ((numbers[right] >= pivot) && (left < right)) {
            right--;
        }
        if (left != right) {
            numberOfInnerIterations++;
            numbers[left] = numbers[right];
            left++;
        }
        
        while ((numbers[left] <= pivot) && (left < right)) {
            left++;
        }
        
        if (left != right){
            numberOfInnerIterations++;
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        quicksort(numbers, left, pivot-1);
    if (right > pivot)
        quicksort(numbers, pivot+1, right);
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