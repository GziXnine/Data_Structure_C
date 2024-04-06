#include <stdio.h>

/**
 * Sorts an array using the quicksort algorithm.
 *
 * Time Complexity: O(n log n) on average, O(n^2) worst-case, where n is the number of elements in the array.
 *                  Quicksort recursively divides the array into smaller subarrays around a chosen pivot element.
 *
 * @param array : The array to be sorted.
 * @param begin : The starting index of the array/subarray.
 * @param end   : The ending index of the array/subarray.
 */
void quickSort(int array[], int begin, int end);

/**
 * Partitions the array into two subarrays around a pivot element.
 *
 * @param array : The array to be partitioned.
 * @param begin : The starting index of the array/subarray.
 * @param end   : The ending index of the array/subarray.
 * @return      : The index of the pivot element after partitioning.
 */
int partition(int array[], int begin, int end);

/**
 * Swaps two integers using bitwise XOR operation.
 *
 * @param numberOne : Pointer to the first integer.
 * @param numberTwo : Pointer to the second integer.
 */
void swap(signed int *numberOne, signed int *numberTwo);

int main()
{

  return 0;
}

void quickSort(int array[], int begin, int end)
{
  int pivot = 0;

  if (begin < end)
  {
    pivot = partition(array, begin, end);

    quickSort(array, begin, pivot - 1);
    quickSort(array, pivot + 1, end);
  }
}

int partition(int array[], int begin, int end)
{
  int pivot = array[end]; // Choose the last element as pivot
  int i = begin - 1;      // Index of smaller element points to an invalid index

  for (int j = begin; j < end; j++)
  {
    if (array[j] < pivot)
    {
      i++;

      // Swap if the elements are different
      if (array[i] != array[j])
      {
        swap(&array[i], &array[j]);
      }
    }
  }

  // By this way of swapping I can't swap two variables have a same memory location.
  // In array if two variables have a same memory location then it will be the same variable then i will not swap.
  if (array[i + 1] != array[end])
  {
    swap(&array[i + 1], &array[end]);
  }

  return (i + 1);
}

void swap(signed int *numberOne, signed int *numberTwo)
{
  (*numberOne) = (*numberOne) ^ (*numberTwo);
  (*numberTwo) = (*numberOne) ^ (*numberTwo);
  (*numberOne) = (*numberOne) ^ (*numberTwo);
}