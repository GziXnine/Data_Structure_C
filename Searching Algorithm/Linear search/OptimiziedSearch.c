#include <stdio.h>

/**
 * Performs optimized search on an array to find the target element.
 *
 * Time Complexity: O(n/2), where n is the number of elements in the array.
 *                  Optimized search checks every other element in the array until the target element is found or the search ends.
 *
 * @param array        : The array to search in.
 * @param size         : The size of the array.
 * @param checkElement : The element to search for within the array.
 * 
 * @return             : The index of the found element if present, otherwise -1.
 */
int optimiziedSearch(int array[], int size, int checkElement);

int main()
{

  return 0;
}

int optimiziedSearch(int array[], int size, int checkElement)
{
  int l_index = 0;

  for (l_index = 0; l_index < size - 1; l_index += 2)
  {
    if ((array[l_index] == checkElement) || (array[l_index + 1] == checkElement))
    {
      return (array[l_index] == checkElement) ? l_index : l_index + 1;
    }
  }

  if ((l_index < size) && array[l_index] == checkElement)
  {
    return l_index;
  }

  return -1;
}