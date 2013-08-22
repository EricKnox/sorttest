///////////////////////////////////////////////////////////////////////////////
// name: selection sort
// steps:
//      1. Pick the smallest element in unsorted list.
//      2. Move it to the last place of sorted list.
//      3. Iterate step 1 - 2 until all elements sorted.
///////////////////////////////////////////////////////////////////////////////
#include "sortings.h"

void selection_sort(int *ptr, int length)
{
        int i = 0, t = 0, m = ptr[0], n = 0;
        
        for (; i < length; ++i) {
                for (m = n = i; n < length; ++n) {
                        if (ptr[n] < ptr[m])
                                m = n;
                }
                if (m != i) {
                        t = ptr[i];
                        ptr[i] = ptr[m];
                        ptr[m] = t;
                }
        }
}
