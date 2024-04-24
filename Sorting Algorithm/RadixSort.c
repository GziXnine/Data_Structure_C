#include <stdio.h>
#include <stdlib.h>

/**
 * Sorts an array using the Radix Sort algorithm.
 *
 * Time Complexity: O(d * (n + k)), where d is the number of digits in the maximum number,
 *                   n is the number of elements in the array, and k is the base of the numbering system (typically 10 for decimal).
 *                   Radix Sort processes the digits of the numbers from least significant to most significant digit.
 *
 * @param array : The array to be sorted.
 * @param size  : The size of the array.
 */
void RadixSort(signed int array[], signed int size);

/**
 * Performs counting sort on the given array based on the specified digit (exp).
 *
 * Time Complexity: O(n + k), where n is the number of elements in the array
 *                   and k is the range of the input values.
 *                   Counting Sort counts the occurrences of each digit and then rearranges the elements in sorted order.
 *
 * @param array      : The array to be sorted.
 * @param exp        : The digit position (1, 10, 100, ...) to sort the array based on.
 * @param size       : The size of the array.
 */
void CountSort(signed int array[], signed int exp, signed int size);

/**
 * Finds the maximum element in the array.
 *
 * Time Complexity: O(n), where n is the size of the array.
 *                   It iterates over each element in the array once to find the maximum element.
 *
 * @param array : The array to be searched.
 * @param size  : The size of the array.
 * @return      : The maximum element in the array.
 */
signed int checkMax(signed int array[], signed int size);

int main()
{
  
  return 0;
}

void RadixSort(signed int array[], signed int size)
{
  signed int max = checkMax(array, size);
  signed int exp = 0;

  for (exp = 1; (max / exp) > 0; exp *= 10)
  {
    CountSort(array, exp, size);
  }
}

signed int checkMax(signed int array[], signed int size)
{
  signed int max = array[0];
  signed int index = 0;

  // Find the maximum element in the array
  for (index = 1; index < size; ++index)
  {
    if (array[index] > max)
    {
      max = array[index];
    }
  }

  return max;
}

void CountSort(signed int array[], signed int exp, signed int size)
{
  signed int *count = (signed int *)calloc((size_t)(10), sizeof(signed int));
  signed int *copyArray = (signed int *)calloc((size_t)size, sizeof(signed int));

  if (!count || !copyArray)
  {
    // Memory allocation failed
    return;
  }

  signed int index = 0;
  for (index = 0; index < size; ++index)
  {
    copyArray[index] = array[index];
    count[(array[index] / exp) % 10]++;
  }

  for (index = 1; index < 10; ++index)
  {
    count[index] += count[index - 1];
  }

  for (index = size - 1; index >= 0; --index)
  {
    array[--count[(copyArray[index] / exp) % 10]] = copyArray[index];
  }

  // Free dynamically allocated memory
  free(count);
  free(copyArray);
}