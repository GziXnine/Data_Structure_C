#include <stdio.h>

/**
 * Performs recursive binary search on a sorted array for the target element.
 *
 * Time Complexity: O(log(n)), where n is the number of elements in the array.
 *                  The array is divided in half in each recursive call, resulting in a logarithmic time complexity.
 *
 * @param array        : The sorted array to search in.
 * @param begin        : The starting index of the subarray to search within.
 * @param end          : The ending index of the subarray to search within.
 * @param checkElement : The element to search for within the array.
 *
 * @return             : The index of the found element if present, otherwise -1.
 */
int recursiveBinarySearch(int array[], int begin, int end, int checkElement);

int main()
{

  return 0;
}

int recursiveBinarySearch(int array[], int begin, int end, int checkElement)
{
  int middle = 0;

  while (begin <= end)
  {
    middle = begin + ((end - begin) / 2); // ((end + begin) / 2)

    if (array[middle] == checkElement)
    {
      return middle;
    }
    else if (array[middle] < checkElement)
    {
      return recursiveBinarySearch(array, middle + 1, end, checkElement);
    }
    else if (array[middle] > checkElement)
    {
      return recursiveBinarySearch(array, begin, middle - 1, checkElement);
    }
  }

  return -1;
}
