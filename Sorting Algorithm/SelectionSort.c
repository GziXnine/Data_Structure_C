#include <stdio.h>

/**
 * Sorts an array using the selection sort algorithm.
 *
 * Time Complexity: O(n^2), where n is the number of elements in the array.
 *                  Selection sort repeatedly selects the minimum element from the unsorted part and moves it to the beginning.
 *
 * @param array : The array to be sorted.
 * @param size  : The size of the array.
 */
void selectionSort(signed int array[], unsigned int size);

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

void selectionSort(signed int array[], unsigned int size)
{
  unsigned int counterIndex = 0;
  unsigned int compareIndex = 0;
  unsigned int minimumIndex = 0;

  for (counterIndex = 0; counterIndex < size - 1; ++counterIndex)
  {
    minimumIndex = counterIndex;
    for (compareIndex = counterIndex + 1; compareIndex < size; ++compareIndex)
    {
      if (array[minimumIndex] > array[compareIndex])
      {
        minimumIndex = compareIndex;
      }
    }

    // By this way of swapping I can't swap two variables have a same memory location.
    // In array if two variables have a same memory location then it will be the same variable then i will not swap.
    if (array[minimumIndex] != array[counterIndex]) 
    {
      swap(&array[minimumIndex], &array[counterIndex]);
    }
  }
}

void swap(signed int *numberOne, signed int *numberTwo)
{
  (*numberOne) = (*numberOne) ^ (*numberTwo);
  (*numberTwo) = (*numberOne) ^ (*numberTwo);
  (*numberOne) = (*numberOne) ^ (*numberTwo);
}