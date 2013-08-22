///////////////////////////////////////////////////////////////////////////////
// name: merge sort
// steps:
//      1. Devide the list into two parts from the middle, recursing until two
//         or less elements left for every list.
//      2. Merge every two close lists, with the smallest elements into sorted
//         list.
//      3. Recurse step 2 to merge every list into one sorted list.
///////////////////////////////////////////////////////////////////////////////


#include <string.h>

#include "sortings.h"

static void merge(int *ptr1, int length1, int *ptr2, int length2, int *result)
{
        int i1 = 0, i2 = 0, n = 0;
        int res[length1 + length2];
        
        while (i1 < length1 || i2 < length2)
                if (i1 >= length1)
                        res[n++] = ptr2[i2++];
                else if (i2 >= length2)
                        res[n++] = ptr1[i1++];
                else
                        res[n++] = ptr1[i1] <= ptr2[i2] ? ptr1[i1++] : ptr2[i2++];
        
        memcpy(result, res, (length1 + length2) * sizeof(int));
}

static void reverse(int *beg, int *end)
{
        int t = 0;

        for (; beg < end; ++beg, --end) {
                t = *beg;
                *beg = *end;
                *end = t;
        }
}

static void reverse_array(int *beg, int *mid, int *end)
{
        reverse(beg, mid - 1);
        reverse(mid, end);
        reverse(beg, end);
}

static void in_place_merge(int *beg, int *mid, int *end)
{
        int i1 = 0, i2 = 0;
        
        if (*end - *beg == 0)
                return;

        while (beg < mid && mid < end) {
                i1 = i2 = 0;
                while (&beg[i1] < mid && beg[i1] <= mid[i2]) ++i1;
                while (&mid[i2] < end && mid[i2] < beg[i1]) ++i2;
                reverse_array(&beg[i1], mid, &mid[i2 - 1]);
                beg += i1 + i2;
                mid += i2;
        }
}

void merge_sort(int *ptr, int length)
{
        int i = 0;
        if (length > 2) {
                merge_sort(ptr, length / 2);
                merge_sort(&ptr[length / 2], length / 2 + (length & 0x1));
        }
        merge(ptr, length / 2, &ptr[length / 2], length / 2 + (length & 0x1), ptr);
}

void in_place_merge_sort(int *ptr, int length)
{
        int i = 0;
 
        if (length == 1) {
                return;
        } else if (length > 2) {
                in_place_merge_sort(ptr, length / 2);
                in_place_merge_sort(&ptr[length / 2], length / 2 + (length & 0x1));
        }
        in_place_merge(ptr, &ptr[length / 2], &ptr[length]);
}
