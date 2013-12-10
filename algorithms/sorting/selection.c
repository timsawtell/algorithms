//
//  insertion.c
//  algorithms
//
//  Created by Tim Sawtell on 10/12/2013.
//  Copyright (c) 2013 . All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "constants.h"

// find the smallest, put it in outer loop index.

int *sort_selection()
{
    numberOfIterations = 0;
    numberOfInnerIterations = 0;
    static int tmpArray[SIZE_OF_ARRAY];
    memcpy(tmpArray, randomArray, SIZE_OF_ARRAY * sizeof(int));
    int tmp;
    for(int x = 0; x < SIZE_OF_ARRAY; x++) {
		int index_of_min = x;
		for (int y = x; y < SIZE_OF_ARRAY; y++) {
            numberOfIterations++;
            if(tmpArray[index_of_min]>tmpArray[y]) {
                index_of_min = y;
			}
		}
        if (x == index_of_min) continue;
		tmp = tmpArray[x];
		tmpArray[x] = tmpArray[index_of_min];
		tmpArray[index_of_min] = tmp;
	}
    
    return tmpArray;
}