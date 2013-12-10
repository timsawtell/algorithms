//
//  merge.c
//  algorithms
//
//  Created by Tim Sawtell on 10/12/2013.
//  Copyright (c) 2013 . All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "merge.h"
#include "constants.h"

/*
 Merge sort takes advantage of the ease of merging already sorted lists into a new sorted list. 
 It starts by comparing every two elements (i.e., 1 with 2, then 3 with 4...) and swapping them 
 if the first should come after the second. It then merges each of the resulting lists of two 
 into lists of four, then merges those lists of four, and so on; until at last two lists are 
 merged into the final sorted list. Of the algorithms described here, this is the first that 
 scales well to very large lists, because its worst-case running time is O(n log n). It is also
 easily applied to lists, not only arrays, as it only requires sequential access, not random 
 access. However, it has additional O(n) space complexity, and involves a large number of copies
 in simple implementations.
 */

void merge(int a[], int low, int mid, int high)
{
    numberOfIterations++;
    int b[SIZE_OF_ARRAY+1];
    int i = low, j = mid + 1, k = 0;
    
    while (i <= mid && j <= high) {
        numberOfInnerIterations++;
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid) {
        numberOfInnerIterations++;
        b[k++] = a[i++];
    }
    
    while (j <= high) {
        numberOfInnerIterations++;
        b[k++] = a[j++];
    }
    
    k--;
    while (k >= 0) {
        numberOfInnerIterations++;
        a[low + k] = b[k];
        k--;
    }
}

void mergesort2(int a[], int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergesort2(a, low, m);
        //printf("mergesort2(a, %d, %d)", low, m);
        mergesort2(a, m + 1, high);
        //printf("mergesort2(a, %d, %d)", m + 1, high);
        merge(a, low, m, high);
        //printf("merge(a, %d, %dm %d)", low, m, high);
    }
}

int *sort_merge()
{
    numberOfIterations = 0;
    numberOfInnerIterations = 0;
    static int tmpArray[SIZE_OF_ARRAY];
    memcpy(tmpArray, randomArray, SIZE_OF_ARRAY * sizeof(int));
    mergesort2(tmpArray, 0, SIZE_OF_ARRAY-1);
    return tmpArray;
}