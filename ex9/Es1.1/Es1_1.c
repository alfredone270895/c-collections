#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size = 10;
	int *array = malloc(size * sizeof(int));
	
	int i;
	for(i = 0; i < size; i++) {
		array[i] = rand() % 100;
	}
	
	
	
	return 0;
}

Bit_node arr2tree(int a[], int size, int i) {
	
}
