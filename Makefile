sorttest: main.o bubble_sort.o cocktail_sort.o gnome_sort.o heap_sort.o insertion_sort.o merge_sort.o quick_sort.o selection_sort.o shell_sort.o
	gcc $^ -o $@
	
release: main.c bubble_sort.c cocktail_sort.c gnome_sort.c heap_sort.c insertion_sort.c merge_sort.c quick_sort.c selection_sort.c shell_sort.c sortings.h
	gcc -O2 -o sorttest $^
	
%.o: %.c sortings.h
	gcc -g -c $^

clean:
	-rm sorttest sortings.h.gch *.o

.PHONY: clean
