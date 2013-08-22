///////////////////////////////////////////////////////////////////////////////
// name: shell sort
// steps:
//      1. Make a gap, compare every two elements with gap, exchange them if
//         the former is bigger than the latter.
//      2. Smaller the gap.
//      3. Iterate step 1 - 2 until gap reaches 0.
///////////////////////////////////////////////////////////////////////////////
#include "sortings.h"

void shell_sort(int *ptr, int length)
{
        int i = 0, t = 0, g = length / 2;

        while (g > 0) {
                for (i = g; i < length; ++i)
                        if (ptr[i] < ptr[i - g]) {
                                t = ptr[i];
                                ptr[i] = ptr[i - g];
                                ptr[i - g] = t;
                        }
                g /= 2;
        }
}
