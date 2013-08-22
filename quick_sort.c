///////////////////////////////////////////////////////////////////////////////
// name: quick sort
// steps:
//      1. Pick an element as pivot, move all elements smaller than it before
//         and all biggers after.
//      2. Quick sort two sublists.
//      3. Recurse step 1 - 2 until all elements sorted.
///////////////////////////////////////////////////////////////////////////////
#include "sortings.h"

void quick_sort(int *ptr, int length)
{
        int i = 0, j = length - 1, m = ptr[length / 2], t = 0;
        
        while (i < j) {
                while (i < j && ptr[j] > m) --j;
                if (i < j) ptr[i++] = ptr[j];
                while (i < j && ptr[i] < m) ++i;
                if (i < j) ptr[j--] = ptr[i];
        }
        ptr[i] = m;

        if (i > 1)
                quick_sort(ptr, i);
        if (i < length - 1)
                quick_sort(&ptr[i + 1], length - i - 1);
}
