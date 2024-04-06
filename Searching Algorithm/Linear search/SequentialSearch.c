#include <stdio.h>

/**
 * Performs sequential search on an array to find the target element.
 *
 * Time Complexity: O(n/2), where n is the number of elements in the array.
 *                  linear search checks each element in the array sequentially until the target element is found or the end of the array is reached.
 *
 * @param array        : The array to search in.
 * @param size         : The size of the array.
 * @param checkElement : The element to search for within the array.
 * 
 * @return             : The index of the found element if present, otherwise -1.
 */
int sequentialSearch(int array[], int size, int checkElement);

int main()
{

  return 0;
}

int sequentialSearch(int array[], int size, int checkElement)
{
  int l_leftIndex = 0;
  int l_rightIndex = size - l_leftIndex - 1;

  while(l_leftIndex <= l_rightIndex)
  {
    if (array[l_leftIndex] == checkElement)
    {
      return  l_leftIndex; 
    }
    else if (array[l_rightIndex] == checkElement)
    {
      return l_rightIndex;
    }
    l_leftIndex++;
    l_rightIndex--;
  }

  return -1;
}