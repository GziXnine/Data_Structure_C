#include <stdio.h>

/**
 * Finds the lower bound index of the target element in a sorted array.
 * Lower bound is the leftmost index where the target element is present.
 * If the target element is not found, returns the index where it could be inserted maintaining the sorted order.
 *
 * Time Complexity: O(log(n)), where n is the number of elements in the array.
 *                  Binary search is applied iteratively to find the lower bound, which has a time complexity of O(log(n)).
 *
 * @param array        : The sorted array to search in.
 * @param begin        : The starting index of the subarray to search within.
 * @param end          : The ending index of the subarray to search within.
 * @param checkElement : The element to search for within the array.
 * 
 * @return             : The index of the found element if present, otherwise the index where it could be inserted.
 */
int lowerBoundBinarySearch(int array[], int begin, int end, int checkElement);

int main()
{

  return 0;
}

int lowerBoundBinarySearch(int array[], int begin, int end, int checkElement)
{
  int result = -1, middle = 0;

  while (begin <= end)
  {
    middle = begin + ((end - begin) / 2); // ((end + begin) / 2)

    if (array[middle] == checkElement)
    {
      result = middle;
      end = middle - 1; // Keep searching for leftmost occurrence
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

  return result;
}
