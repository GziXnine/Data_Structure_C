#include <stdio.h>
#include <stdlib.h>

/**
 * Merges two sorted subarrays into one sorted array.
 *
 * Time Complexity: O(n), where n is the total number of elements in the two subarrays.
 *
 * @param array : The array containing the two sorted subarrays to be merged.
 * @param begin : The starting index of the first subarray.
 * @param mid   : The ending index of the first subarray.
 * @param end   : The ending index of the second subarray.
 */
void merge(signed int array[], unsigned int begin, unsigned int mid, unsigned int end);

/**
 * Sorts an array using the merge sort algorithm.
 *
 * Time Complexity: O(n log(n)), where n is the number of elements in the array.
 *                  Merge sort divides the array into two halves, sorts each half separately, and then merges them.
 *
 * @param array : The array to be sorted.
 * @param begin : The starting index of the subarray to be sorted.
 * @param end   : The ending index of the subarray to be sorted.
 */
void mergeSort(signed int array[], unsigned int begin, unsigned int end);

int main()
{

  return 0;
}

void mergeSort(signed int array[], unsigned int begin, unsigned int end)
{
  if (begin < end)
  {
    unsigned int mid = begin + ((end - begin) / 2); // ((end + begin) / 2);

    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
  }
}

void merge(signed int array[], unsigned int begin, unsigned int mid, unsigned int end)
{
  unsigned int arrayIndex = begin;
  unsigned int leftCounter = 0, rightCounter = 0;
  unsigned int elementCountLeft = mid - begin + 1;
  unsigned int elementCountRight = end - mid;

  // This is not allowed in C standard to declare an array with sizes determined at runtime like an 'elementCountLeft' or 'elementCountRight'...
  // I should using dynamic memory allocate.
  signed int *leftArray = (signed int *)calloc(elementCountLeft, sizeof(signed int));
  signed int *rightArray = (signed int *)calloc(elementCountRight, sizeof(signed int));

  if(!leftArray || !rightArray)
  {
    // Memory allocation failed
    return;
  }

  for (leftCounter = 0; leftCounter < elementCountLeft; ++leftCounter)
  {
    leftArray[leftCounter] = array[begin + leftCounter];
  }

  for (rightCounter = 0; rightCounter < elementCountRight; ++rightCounter)
  {
    rightArray[rightCounter] = array[mid + 1 + rightCounter];
  }
  rightCounter = leftCounter = 0;

  // Merge left and right subarrays
  while ((leftCounter < elementCountLeft) && (rightCounter < elementCountRight))
  {
    if (leftArray[leftCounter] <= rightArray[rightCounter])
    {
      array[arrayIndex++] = leftArray[leftCounter++];
    }
    else
    {
      array[arrayIndex++] = rightArray[rightCounter++];
    }
  }

  // Copy remaining elements of left subarray
  while (leftCounter < elementCountLeft)
  {
    array[arrayIndex++] = leftArray[leftCounter++];
  }

  while (rightCounter < elementCountRight)
  {
    array[arrayIndex++] = rightArray[rightCounter++];
  }

  // Free dynamically allocated memory
  free(leftArray);
  free(rightArray);
}