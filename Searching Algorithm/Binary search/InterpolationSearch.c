#include <stdio.h>

/**
 * Performs interpolation search on a sorted array.
 * Interpolation search is an improved variant of binary search for uniformly distributed arrays.
 *
 * Time Complexity: O(log(log(n))) on average, where n is the number of elements in the array.
 *                  Worst-case time complexity is O(n) when the elements are not uniformly distributed.
 *                  However, it typically performs better than binary search for uniformly distributed data.
 *
 * @param array        : The sorted array to search in.
 * @param begin        : The starting index of the subarray to search within.
 * @param end          : The ending index of the subarray to search within.
 * @param checkElement : The element to search for within the array.
 * 
 * @return             : The index of the found element if present, otherwise -1.
 */
int interpolationSearch(int array[], int begin, int end, int checkElement);

int main()
{

  return 0;
}

int interpolationSearch(int array[], int begin, int end, int checkElement)
{
  int position = 0;

  while ((begin <= end) && (checkElement >= array[begin]) && (checkElement <= array[end]))
  {
    if (begin == end)
    {
      if (array[begin] == checkElement)
      {
        return begin;
      }

      return -1;
    }
    position = begin + (checkElement - array[begin]) * ((end - begin) / (array[end] - array[begin]));

    if (array[position] == checkElement)
    {
      return position;
    }
    else if (array[position] < checkElement)
    {
      begin = position + 1;
    }
    else if (array[position] > checkElement)
    {
      end = position - 1;
    }
  }

  return -1;
}