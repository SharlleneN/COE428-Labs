Author: Sharllene Nimalraaj, Section 02

This lab folder contains working code to sort a set of given numbers from least to greatest. Upon entering the command 'testSort2' alone, the default values are organized from least to greatest. After entering testSort2 followed by values with spaces, those will be organized from least to greatest as well. 


The code runs with no errors. 

1) The mySort function has the signature 'mySort(int array[], unsigned int num_elements)' which sorts the entire 'array' of size 'num_elements'. The betterSort function signature: betterSort(int data[], int first, int last) sorts the elements from index 'first' to 'last' in the 'data' array. 

For mySort, the array needs to be sorted from the first element (i = 0) to the last element ('num_elements - 1')

So, betterSort would be called as 'betterSort(data, 0, num_elements - 1)'

Implementing this in a mySort function would be:

// Assume betterSort is defined somewhere else and linked during compilation
void betterSort(int data[], int first, int last);

void mySort(int array[], unsigned int num_elements) {
    // Call the betterSort function to sort the entire array
    betterSort(array, 0, num_elements - 1);
}

