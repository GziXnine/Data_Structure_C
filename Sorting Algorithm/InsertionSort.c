#include <stdio.h>

/**
 * Sorts an array using the insertion sort algorithm.
 *
 * Time Complexity: O(n^2), where n is the number of elements in the array.
 *                  Insertion sort builds the final sorted array one element at a time by repeatedly inserting the next unsorted element 
 *                  into its correct position within the sorted part of the array.
 *
 * @param array : The array to be sorted.
 * @param size  : The size of the array.
 */
void insertionSort(signed int array[], unsigned int size);

int main()
{

  return 0;
}

void insertionSort(signed int array[], unsigned int size)
{
  signed int compareIndex = 0;
  unsigned int iteratorIndex = 0;
  signed int insertVal = 0;

  for(iteratorIndex = 1; iteratorIndex < size; ++iteratorIndex)
  {
    insertVal = array[iteratorIndex];
    compareIndex = (signed int)iteratorIndex - 1;
    
    while((array[compareIndex] > insertVal) && (compareIndex >= 0))
    {
      array[compareIndex + 1] = array[compareIndex];
      compareIndex--;
    }
    array[compareIndex + 1] = insertVal;
  }
}