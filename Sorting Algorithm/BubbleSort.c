#include <stdio.h>

/**
 * Sorts an array using the bubble sort algorithm.
 *
 * Time Complexity: O(n^2), where n is the number of elements in the array.
 *                  Bubble sort iteratively compares adjacent elements and swaps them if they are in the wrong order until the entire array is sorted.
 *
 * @param array : The array to be sorted.
 * @param size  : The size of the array.
 */
void bubbleSort(signed int array[], unsigned int size);

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

void bubbleSort(signed int array[], unsigned int size)
{
  unsigned int l_counter = 0;
  unsigned int l_iterator = 0;
  unsigned int flag = 1;

  for(l_counter = 0; l_counter < size - 1; ++l_counter)
  {
    for(l_iterator = 0; l_iterator < size - l_counter -1; ++l_iterator)
    {
      if(array[l_iterator] > array[l_iterator + 1])
      {
        flag = 0;

        swap(&array[l_iterator], &array[l_iterator + 1]);
      }
      
      if(flag)
      {
        return;
      }
    }
  }
}

void swap(signed int *numberOne, signed int *numberTwo)
{
  (*numberOne) = (*numberOne) ^ (*numberTwo);
  (*numberTwo) = (*numberOne) ^ (*numberTwo);
  (*numberOne) = (*numberOne) ^ (*numberTwo);
}