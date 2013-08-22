///////////////////////////////////////////////////////////////////////////////
// name: sorttest
// function: test speed of sorting algorithms
// author: Eric Knox
// usage: sorttest -a algorithms [-l length] [-m mode]
//      algorithms:
//              b - bubble sort;
//              c - cocktail sort;
//              g - gnome sort;
//              h - heap sort;
//              i - insertion sort;
//              m - merge sort;
//              n - in time merge sort;
//              q - quick sort;
//              s - selection sort;
//              t - shell sort;
//      length: length of array, 1000 by default.
//      mode:
//              b - best situration
//              w - worst situation
//              r - all random
//              all random by default.
// example:
//      ~$ sorttest -a bcgimnqst -l 200
//            Bubble sort costs 0.000038 seconds.
//          Cocktail sort costs 0.000085 seconds.
//             Gnome sort costs 0.000058 seconds.
//         Insertion sort costs 0.000018 seconds.
//             Merge sort costs 0.000040 seconds.
//     Inplace merge sort costs 0.000043 seconds.
//             Quick sort costs 0.000018 seconds.
//         Selection sort costs 0.000083 seconds.
//             Shell sort costs 0.000009 seconds.
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#include "sortings.h"


void init_random(void)
{
        FILE *urandom;
        unsigned int seed, i;
        
        urandom = fopen("/dev/urandom", "r");
        if (!urandom) {
                perror("Failure opening random file.");
                exit(EXIT_FAILURE);
        }
        
        i = fread(&seed, sizeof(seed), 1, urandom);
        srand(seed);
}

void generate_random(int *ptr, int length)
{
        int i = 0;
        
        init_random();
        for (; i < length; ++i)
                ptr[i] = rand() % (length * 10);
}

void generate_best(int *ptr, int length)
{
        int i = 0;
        
        for (; i < length; ++i)
                ptr[i] = i;
}

void generate_worst(int *ptr, int length)
{
        int i = 0;
        
        for (; i < length; ++i)
                ptr[i] = length - i;
}

void do_sort(char *ipt, int length, char mode)
{
        int array[length], test[length];
        struct timeval start, end;
        char* name;
        
        generate_random(array, length);
        switch (mode) {
                case 'b': generate_best(array, length); break;
                case 'w': generate_worst(array, length); break;
                default: generate_random(array, length); break;
        }
        
        while (*ipt != '\0')
        {
                memcpy(test, array, length * sizeof(int));
                
                void (*sort)(int *ptr, int length);

                switch (*ipt)
                {
                        case 'b':
                                sort = bubble_sort;
                                name = "Bubble sort";
                                break;
                        case 'c':
                                sort = cocktail_sort;
                                name = "Cocktail sort";
                                break;
                        case 'g':
                                sort = gnome_sort;
                                name = "Gnome sort";
                                break;
                        case 'h':
                                sort = heap_sort;
                                name = "Heap sort";
                                break;
                        case 'i':
                                sort = insertion_sort;
                                name = "Insertion sort";
                                break;
                        case 'm':
                                sort = merge_sort;
                                name = "Merge sort";
                                break;
                        case 'n':
                                sort = in_place_merge_sort;
                                name = "Inplace merge sort";
                                break;
                        case 'q':
                                sort = quick_sort;
                                name = "Quick sort";
                                break;
                        case 's':
                                sort = selection_sort;
                                name = "Selection sort";
                                break;
                        case 't':
                                sort = shell_sort;
                                name = "Shell sort";
                                break;
                        default: break;
                }

                gettimeofday(&start, NULL);
                sort(test, length);
                gettimeofday(&end, NULL);
                
                long duration = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
                printf("%18s costs %ld.%06ld seconds.\n", name, duration / 1000000, duration % 1000000);

                ++ipt;
        }
}

#define FLAG_SORT       0x1
#define FLAG_LENGTH     0x2
#define FLAG_MODE       0x4
int main(int argc, char **argv)
{
        int flags = 0, length = 0, c = 0;
        char *sort, *mode;
        
        while ((c = getopt(argc, argv, "a:l:m:")) != -1)
                switch (c) {
                        case 'a':
                                flags |= FLAG_SORT;
                                sort = optarg;
                                break;
                        case 'l':
                                flags |= FLAG_LENGTH;
                                length = strtol(optarg, NULL, 10);
                                break;
                        case 'm':
                                flags |= FLAG_MODE;
                                mode = optarg;
                                break;
                        default: break;
                }
        
        if (!(flags & FLAG_SORT)) {
                printf("Need password definition.\n");
                return -1;
        }
        
        if (!(flags & FLAG_LENGTH) || !length)
                length = 1000;

        if (!(flags & FLAG_MODE))
                mode = "r";
        
        do_sort(sort, length, mode[0]);
}
