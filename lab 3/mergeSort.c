#include "mySort.h"
#include <stdlib.h>
#include <stdio.h>
#include "metrics.h"

void merge(int array[], unsigned int first, unsigned int mid, unsigned int last) {
    int temp[1000];
    unsigned int i = first, j = mid + 1, k = 0;

    // Merge the two halves into temp[]
    while (i <= mid && j <= last) {
		if (myCompare(array[i], array[j]) <= 0){
			myCopy(&array[i], &temp[k]);
            i++;
        } else {
			myCopy(&array[j], &temp[k]);
            j++;
        }
        k++;
    }

    // Copy the remaining elements of the first half, if any
    while (i <= mid) {
		myCopy(&array[i], &temp[k]);
        i++;
        k++;
    }

    // Copy the remaining elements of the second half, if any
    while (j <= last) {
        myCopy(&array[j], &temp[k]);
        j++;
        k++;
    }

    // Copy the sorted elements back into the original array
    for (i = first, k = 0; i <= last; i++, k++) {
		mySwap(&array[i], &temp[k]);
    }
}

void mySort(int array[], unsigned int first, unsigned int last) {
    if (first < last) {
        unsigned int mid = first + (last - first) / 2;
        mySort(array, first, mid);
        mySort(array, mid + 1, last);
        merge(array, first, mid, last);
    }
}

