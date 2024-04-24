#include <stdio.h>

/**
 * Sorts an array using the heap sort algorithm.
 *
 * Time Complexity: O(n log(n)), where n is the number of elements in the array.
 *                  Heap sort builds a max heap from the array and repeatedly extracts the maximum element to sort the array.
 *
 * @param array : The array to be sorted.
 * @param size  : The number of elements in the array.
 */
void HeapSort(signed int array[], signed int size);

/**
 * Builds a max heap from the given array.
 *
 * Time Complexity: O(n), where n is the number of elements in the array.
 *
 * @param array : The array from which to build the heap.
 * @param size  : The number of elements in the array.
 */
void buildHeap(signed int array[], signed int size);

/**
 * Heapifies a subtree rooted at the given index.
 *
 * Time Complexity: O(log(n)), where n is the size of the heap.
 *
 * @param array : The array representing the heap.
 * @param begin : The index of the root of the subtree to heapify.
 * @param size  : The size of the heap.
 */
void Heapify(signed int array[], signed int begin, signed int size);

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

void HeapSort(signed int array[], signed int size)
{
  signed int start = 0;
  buildHeap(array, size);

  for (start = size - 1; start > 0; start--)
  {
    swap(&array[0], &array[start]);
    Heapify(array, 0, start);
  }
}

void buildHeap(signed int array[], signed int size)
{
  signed int start = (size - 1) / 2;

  while (start >= 0)
  {
    Heapify(array, start, size);
    start--;
  }
}

void Heapify(signed int array[], signed int begin, signed int size)
{
  signed int left = 2 * begin + 1;
  signed int right = 2 * begin + 2;
  signed int max = begin;

  if (left < size && array[left] > array[max])
  {
    max = left;
  }

  if (right < size && array[right] > array[max])
  {
    max = right;
  }

  if (max != begin)
  {
    swap(&array[begin], &array[max]);
    Heapify(array, max, size);
  }
}

void swap(signed int *numberOne, signed int *numberTwo)
{
  (*numberOne) = (*numberOne) ^ (*numberTwo);
  (*numberTwo) = (*numberOne) ^ (*numberTwo);
  (*numberOne) = (*numberOne) ^ (*numberTwo);
}