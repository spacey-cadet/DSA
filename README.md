# Data Structres and Algorithms

## Max subarray problem
Given an array, find the contiguous sub-array(a sub-array where elements are adjacent in the array) that has the larest sum of elements. 
### Method 1: Kadene's Algorithm

Kadane's Algorithm is dynamic-programming based. It iterates throught the array once keeping track of the maximum subarray ending at each position. 
### Steps
Use a 'max_sum' and 'current sum' varibale to keep trackof the maximum sub-array.
1. Initilaize the 'max_sum' and 'current_sum' to the value of value at index 0
2. Iterate the array from the second element onwards
3. At each step update 'current_sum' by adding the current element in the iteration.
4. Perform a check : If 'current_sum 'becomes negative, reset it to 0.
5. Update max_sum if 'current_sum' exceeds it.
6. Iterate until the end of the array. 

At the end of the iteration, the max_sum will have the maximum sub array and the problem will have been solved.

### Divide and Conquer

This approach solves this problem by diving the array into sub-arrays and solving recursively. It then combines the solution to find the maximum sub-array 

### Steps
1. Divide the array into two halves.
2. Find the maximum sub array for the left hand side. Use recursion.
3. Find the maximum sub array for the right hand side . Use recursion again.
4. Find the maximim subarray that crosses the midpoint : Start from the midpoint and expand towards both ends, keeping track of the sum. The maximum sum subarray will include elements from both the left and right halves of the array.
5. Combine results form all the steps to find the overall maximum subarray

## Time Complexity Analysis
- Kadane Algo : has a 0(n) since it iterates throught the array once.
- Divide and Conquer: has a 0(n log n) ie log n because the array is divided into subarrays and n because   for each sub-array the maximum sum is found in linear time.

### Example



