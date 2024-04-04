#include <stdio.h>

/**
 * Performs exponential search on a sorted array followed by binary search for the target element.
 * Exponential search is a search algorithm designed to find the position of a target value within a sorted array.
 *
 * Time Complexity: O(log(n)), where n is the number of elements in the array.
 *                  Exponential search divides the array into segments of size 2^i, where i starts from 1 and doubles with each iteration.
 *                  After finding a segment where the target value might be present, binary search is applied, which has a time complexity of O(log(n)).
 *
 * @param array        : The sorted array to search in.
 * @param size         : The size of the array.
 * @param checkElement : The element to search for within the array.
 * 
 * @return             : The index of the found element if present, otherwise -1.
 */
int exponentialSearch(int array[], int size, int checkElement);

/**
 * Performs binary search on a sorted array for the target element.
 *
 * @param array        : The sorted array to search in.
 * @param begin        : The starting index of the subarray to search within.
 * @param end          : The ending index of the subarray to search within.
 * @param checkElement : The element to search for within the array.
 * 
 * @return             : The index of the found element if present, otherwise -1.
 */
int BinarySearch(int array[], int begin, int end, int checkElement);

int main()
{

  return 0;
}

int exponentialSearch(int array[], int size, int checkElement)
{
  int i = 1;

  if (array[0] == checkElement)
  {
    return 0;
  }

  while ((i < size) && (array[i] <= checkElement))
  {
    i *= 2;
  }

  return BinarySearch(array, i / 2, (i < size) ? i : size - 1, checkElement);
}

int BinarySearch(int array[], int begin, int end, int checkElement)
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
