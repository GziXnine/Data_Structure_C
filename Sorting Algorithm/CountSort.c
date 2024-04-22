#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Finds the maximum element in the array and calls CountSort to perform counting sort.
 *
 * This function finds the maximum element in the array and then calls CountSort to perform
 * counting sort on the array.
 *
 * Time Complexity: O(n), where n is the size of the array. 
 *                  It iterates over each element in the array once to find the maximum element.
 *
 * @param array : The array to be sorted.
 * @param size  : The size of the array.
 */
void checkMax(signed int array[], signed int size);

/**
 * @brief Performs counting sort on the given array.
 *
 * This function performs counting sort on the given array using dynamic memory allocation
 * for the count and copyArray arrays.
 *
 * Time Complexity: O(n + k), where n is the size of the array and k is the range of the input values.
 *                  It iterates over the array once to count the occurrences of each element,
 *                  and then iterates over the count array to rearrange the elements in sorted order.
 *
 * @param array      : The array to be sorted.
 * @param maxElement : The maximum element in the array.
 * @param size       : The size of the array.
 */
void CountSort(signed int array[], signed int maxElement, signed int size);

int main ()
{
 
  return 0;
}

void checkMax(signed int array[], signed int size)
{
  signed int max = array[0];
  signed int index = 0;

  // Find the maximum element in the array
  for (index = 0; index < size; ++index)
  {
    if (array[index] > max)
    {
      max = array[index];
    }
  }
  // Call CountSort function with the maximum element and the size of the array
  CountSort(array, max, size);
}

void CountSort(signed int array[], signed int maxElement, signed int size)
{
  signed int index = 0;

  // This is not allowed in C standard to declare an array with sizes determined at runtime like an 'maxElement' or 'size'...
  // I should using dynamic memory allocate.
  signed int *count = (signed int *)calloc((size_t)(maxElement + 1), sizeof(signed int));
  signed int *copyArray = (signed int *)calloc((size_t)size, sizeof(signed int));

  if(!count || !copyArray)
  {
    // Memory allocation failed
    return;
  }

  for (index = 0; index < size; ++index)
  {
    copyArray[index] = array[index];
    count[array[index]]++;
  }

  for (index = 1; index <= maxElement; ++index)
  {
    count[index] += count[index - 1];
  }

  for (index = size - 1; index >= 0; --index)
  {
    array[--count[copyArray[index]]] = copyArray[index];
  }

  // Free dynamically allocated memory
  free(count);
  free(copyArray);
}