///////////////////////////////////////////////////////////////////////////////
// name: bubble sort
// steps:
//      1. Pick the first element from unsorted list, bubble it to the last
//         position of the list.
//      2. If there is a bigger element, bubble it instead of the last one.
//      3. Mark the last element of unsorted list as sorted.
//      4. Iterate step 1 - 3 until all elements sorted.
///////////////////////////////////////////////////////////////////////////////
#include "sortings.h"

void bubble_sort(int *ptr, int length)
{
        int i = length, j = 0, t = 0;
        
        for (; i >= 0; --i)
                for (j = 1; j < i; ++j)
                        if (ptr[j - 1] > ptr[j]) {
                                t = ptr[j];
                                ptr[j] = ptr[j - 1];
                                ptr[j - 1] = t;
                        }
}
