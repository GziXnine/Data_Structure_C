#include <stdio.h>

/**
 * Performs traditional binary search on a sorted array for the target element.
 *
 * Time Complexity: O(log(n)), where n is the number of elements in the array.
 *                  Binary search divides the array in half in each iteration, resulting in a logarithmic time complexity.
 *
 * @param array        : The sorted array to search in.
 * @param begin        : The starting index of the subarray to search within.
 * @param end          : The ending index of the subarray to search within.
 * @param checkElement : The element to search for within the array.
 * 
 * @return             : The index of the found element if present, otherwise -1.
 */
int traditionalBinarySearch(int array[], int begin, int end, int checkElement);

int main()
{

  return 0;
}

int traditionalBinarySearch(int array[], int begin, int end, int checkElement)
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
      begin = middle + 1;
    }
    else if (array[middle] > checkElement)
    {
      end = middle - 1;
    }
  }

  return -1;
}
