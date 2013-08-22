///////////////////////////////////////////////////////////////////////////////
// name: heap sort
// steps:
//      1. Treat the list a binary tree, then index of any children's parent
//         node is (index - 1) / 2.
//      2. Exchange children node and parent node, make sure all parent node
//         (including root) is smaller than their subtrees' elements.
//      3. remove root as sorted element of the list and treat the rest a new
//         binary tree.
//      4. Iterate step 2 - 3 until all elements sorted.
///////////////////////////////////////////////////////////////////////////////


#include "sortings.h"

void heap_sort(int *ptr, int length)
{
        int i = length - 1, j = 0, t = 0;
        
        for (; i > 0; --i) {
                j = (i - 1) / 2;
                if (ptr[i] < ptr[j]) {
                        t = ptr[j];
                        ptr[j] = ptr[i];
                        ptr[i] = t;
                }
        }

        if (length > 1)
                heap_sort(&ptr[1], --length);
}
