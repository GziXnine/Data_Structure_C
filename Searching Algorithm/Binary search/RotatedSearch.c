#include <stdio.h>

/**
 * Performs search on a rotated sorted array to find the target element.
 *
 * Time Complexity: O(log(n)), where n is the number of elements in the array.
 *                  Rotated search is a modified binary search algorithm that works efficiently even on rotated sorted arrays.
 *                   such as => {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 1, 2, 3, 4, 5, 6, 7};
 *
 * @param array        : The rotated sorted array to search in.
 * @param begin        : The starting index of the subarray to search within.
 * @param end          : The ending index of the subarray to search within.
 * @param checkElement : The element to search for within the array.
 *
 * @return             : The index of the found element if present, otherwise -1.
 */
int rotatedSearch(int array[], int begin, int end, int checkElement);

int main()
{

  return 0;
}

int rotatedSearch(int array[], int begin, int end, int checkElement)
{
  int middle = 0;

  while (begin <= end)
  {
    middle = begin + ((end - begin) / 2); // ((begin + end ) / 2);

    if (array[middle] == checkElement)
    {
      return middle;
    }

    if (array[begin] <= array[middle])
    {
      if ((array[middle] >= checkElement) && (array[begin] <= checkElement))
      {
        end = middle - 1;
      }
      else
      {
        begin = middle + 1;
      }
    }
    else
    {
      if ((array[middle] <= checkElement) && (array[begin] >= checkElement))
      {
        begin = middle + 1;
      }
      else
      {
        end = middle - 1;
      }
    }
  }

  return -1;
}