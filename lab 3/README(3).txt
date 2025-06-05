This lab works correctly for both insertionSort and mergeSort functions. I initially had trouble analyzing the codes to find the time complexities, but upon reviewing the department slides, I was able to understand how to calculate them.

To test the values of the comparisons, swaps, and copies, I created 3 different text files (each with 6 elements), one representing the worst case (completely unsorted), one representing the best case (already sorted), and one representing the average case which was also the file I used to test whether or not the functions were working.

Analysis of Sorting Algorithms:

1. InsertionSort:
- For the best case, I got 5 comparisons[comparison for each element 1 - n], 0 swaps [O(0)], and 5 copies[1 copy for each var from temp variable to back]. The comparisons and copies resulted in O(n) time complexities, which are linear relations.

- The worst case had 15 comparisons, 15 swaps, and 5 copies[again one copy for each variable from temp variable to back]. For the comparisons and swaps, I tested to see how many swaps and comparisons would be needed for each element to be moved. The first element requires 0 comparisons, the second requires 1, the third requires 2, etc. Notice a pattern 0+1+2+...+(n-1). Also note the sum of the first n positive integers is [n(n+1)]/2, which can be modified to [(n-1)n]/2= (n^2-n)/2, which is approximately equal to n^2/2 since for big-O the highest growth rate should be focused on.

Therefore, the average time complexity falls between the best and worst values, which is O(n^2).

2. MergeSort:
- For mergeSort, the time complexity was consistent throughout the best and worst cases. To explain this it can be noticed that there is recursion within the mergesort function. At each level of recursion, the array is split into two halves. This continues until there are n subarrays of size 1. 

Note that the number of levels of recursion to have n subarrays of 1 is log2(n). ALSO note that at each level of recursion, the subarrays are merges back together. This requires O(n) comparisons and copies. 

To find the time complexity of mergeSort, combine both as found above! (There are log2(n) levels of recursion and each level has O(n) total work done.) SO therefore, 					T(n)= O(n)*O(log2(n))=	O(nlogn)
