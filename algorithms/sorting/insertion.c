//
//  insertion.c
//  algorithms
//
//  Created by Tim Sawtell on 10/12/2013.
//  Copyright (c) 2013 . All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "insertion.h"
#include "constants.h"

int *sort_insertion()
{
    numberOfIterations = 0;
    numberOfInnerIterations = 0;
    static int tmpArray[SIZE_OF_ARRAY];
    memcpy(tmpArray, randomArray, SIZE_OF_ARRAY * sizeof(int));
    int tmp;
    for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        int compare = i;
        
        while (compare > 0 && tmpArray[compare] < tmpArray[compare - 1]) {
            numberOfIterations++;
            tmp = tmpArray[compare];
            tmpArray[compare] = tmpArray[compare - 1];
            tmpArray[compare - 1] = tmp;
            compare--;
        }
    }
    return tmpArray;
}
