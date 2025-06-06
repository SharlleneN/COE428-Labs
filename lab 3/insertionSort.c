#include "mySort.h"
#include "metrics.h"

void mySort(int array[], unsigned int first, unsigned int last)
    {
		int i,j,temp;
        if(first>=last){
            return;
        }
        for(i =1; i<= last; i++){
            temp = array[i];
            j =i-1;
           
            while(j>=0 && (myCompare(array[j],temp)>0)){
                mySwap(&array[j+1], &array[j]);
                j = j-1;
            }
            myCopy(&temp, &array[j+1]);
        }
    }
