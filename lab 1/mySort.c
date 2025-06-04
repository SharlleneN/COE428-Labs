
#include "mySort.h"

void mySort(int array[], unsigned int num_elements)
{
int i, j, temp;

for(i = 0; i<num_elements-1; ++i){
	for(j = i+1; j<num_elements ; j++)
		if(array[j] < array[i]){
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		}		
}

}
