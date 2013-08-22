///////////////////////////////////////////////////////////////////////////////
// name: gnome sort
// steps:
//      1. Compare the starting two elements.
//      2. Exchange them if the former's bigger than the latter and move one
//         place to the smallers.
//      3. Or move one place to the biggers.
//      4. Iterate 1 - 3 until the pointer is in the last element of the list.
///////////////////////////////////////////////////////////////////////////////
#include "sortings.h"

void gnome_sort(int *ptr, int length)
{
        int i = 1, t = 0;
        
        while (i < length)
                if (ptr[i] >= ptr[i - 1])
                        ++i;
                else {
                        t = ptr[i];
                        ptr[i] = ptr[i - 1];
                        ptr[i - 1] = t;
                        if (i > 1)
                                --i;
                }
}
