///////////////////////////////////////////////////////////////////////////////
// name: instertion sort
// steps:
//      1. Treat the first element as sorted, pick the second element.
//      2. Move the picked element forward in sorted list until there is a
//         smaller one at front of the element, mark the element as sorted.
//      3. Pick the first element in unsorted list.
//      4. Recurse step 2 - 3 until all elements sorted.
///////////////////////////////////////////////////////////////////////////////

#include "sortings.h"

void insertion_sort(int *ptr, int length)
{
        int t = 0, i = 1, m = 0;
        
        for (; i < length; ++i) {
                t = ptr[i];
                m = i;
                while (m > 0 && ptr[m - 1] > t) {
                        ptr[m] = ptr[m - 1];
                        --m;
                }
                ptr[m] = t;
        }
}
