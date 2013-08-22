///////////////////////////////////////////////////////////////////////////////
// name: socktail sort
// steps:
//      1. Pick the first element from unsorted list, bubble it to the last
//         position of the list.
//      2. If there is a bigger element, bubble it instead of the last one.
//      3. Mark the last position of unsorted list as sorted.
//      4. Pick the last element from unsorted list, sink it to the first
//         position of the list.
//      5. If there is a smaller element, sink it instead of the last one.
//      6. Mark the first element in unsorted list as sorted.
//      7. Iterate step 1 - 6 until all elements sorted.
///////////////////////////////////////////////////////////////////////////////
#include "sortings.h"

void cocktail_sort(int *ptr, int length)
{
        int l = 0, r = length - 1, i = 0, t = 0;
        
        while (l < r) {
                for (i = l; i < r; ++i) {
                        if (ptr[i] > ptr[i + 1]) {
                                t = ptr[i];
                                ptr[i] = ptr[i + 1];
                                ptr[i + 1] = t;
                        }
                }
                --r;
                if (l >= r) break;
                for (i = r; i > l; --i) {
                        if (ptr[i] < ptr[i - 1]) {
                                t = ptr[i];
                                ptr[i] = ptr[i - 1];
                                ptr[i - 1] = t;
                        }
                }
                ++l;
        }
}
