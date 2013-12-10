//
//  bubble.c
//  algorithms
//
//  Created by Tim Sawtell on 10/12/2013.
//  Copyright (c) 2013 . All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "bubble.h"
#include "constants.h"

int *sort_bubble()
{
    numberOfIterations = 0;
    static int tmpArray[SIZE_OF_ARRAY];
    memcpy(tmpArray, randomArray, SIZE_OF_ARRAY * sizeof(int));
    int tmp;
    for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        for (int j = 0; j < SIZE_OF_ARRAY - 1; j++) {
            numberOfIterations++;
            if (tmpArray[j] > tmpArray[j + 1]) {
                tmp = tmpArray[j];
                tmpArray[j] = tmpArray[j + 1];
                tmpArray[j + 1] = tmp;
            }
        }
    }
    return tmpArray;
}
