#include <stdio.h>

/**
 * Performs linear search on an array to find the target element.
 *
 * Time Complexity: O(n), where n is the number of elements in the array.
 *                  Linear search checks each element in the array sequentially until the target element is found or the end of the array is reached.
 *
 * @param array        : The array to search in.
 * @param size         : The size of the array.
 * @param checkElement : The element to search for within the array.
 * 
 * @return             : The index of the found element if present, otherwise -1.
 */
int linearSearch(int array[], int size, int checkElement);

int main()
{

  return 0;
}

int linearSearch(int array[], int size, int checkElement)
{
  int l_index = 0;

  for (l_index = 0; l_index < size; l_index++)
  {
    if (array[l_index] == checkElement)
    {
      return l_index; // return the index of the element in the array
    }
  }

  return -1;
}