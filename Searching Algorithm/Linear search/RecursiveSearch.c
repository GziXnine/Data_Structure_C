#include <stdio.h>

/**
 * Performs recursive search on an array to find the target element.
 *
 * Time Complexity: O(n), where n is the number of elements in the array.
 *                  Recursive search traverses through the array recursively until the target element is found or the search ends.
 *
 * @param array        : The array to search in.
 * @param begin        : The starting index of the subarray to search within.
 * @param end          : The ending index of the subarray to search within.
 * @param checkElement : The element to search for within the array.
 * 
 * @return             : The index of the found element if present, otherwise -1.
 */
int recursiveSearch(int array[], int begin, int end, int checkElement);

int main()
{

  return 0;
}

int recursiveSearch(int array[], int begin, int end, int checkElement)
{
  if(begin > end)
  {
    return -1;
  }

  if(array[begin] == checkElement)
  {
    return begin;
  }

  return recursiveSearch(array, begin + 1, end, checkElement);
}