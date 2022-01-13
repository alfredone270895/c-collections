#include <stdio.h>
#include <stdlib.h>

struct bit_node {
	int item;
	struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

Bit_node bit_new(int elem);
void bit_preorder (Bit_node p);
void bit_inorder (Bit_node p);
void bit_postorder (Bit_node p);
void printassummary(Bit_node p, int spaces);
Bit_node arr2tree(int a[], int size, int i);

int main(void) {
	int arraySize = 5;
	Bit_node *array = malloc(arraySize * sizeof(Bit_node));
	int *values = malloc(arraySize * sizeof(int));
	
	int i;
	for(i = 0; i < arraySize; i++) {
		array[i] = bit_new(rand()%100);
		values[i] = array[i] -> item;
		printf("%d\n", array[i] -> item);
		
	}
	printf("\n");
	Bit_node arrayRoot;
	nn = arr2tree(values, arraySize, 0);
		
	Bit_node root = bit_new(10);
	root -> l = bit_new(3);
	root -> r = bit_new(4);
	root -> l -> l = bit_new(8);
	
	return 0;
}

Bit_node bit_new(int elem) {
	Bit_node bn = malloc(sizeof(struct bit_node));
	bn -> item = elem;
	bn -> l = NULL;
	bn -> r = NULL;
	return bn;
}

void bit_preorder(Bit_node p) {
	if(p) {
		printf("%d ", p->item);
		bit_preorder(p->l);
		bit_preorder(p->r);
	}
}

void bit_inorder(Bit_node p) {
	if(p) {
		bit_inorder(p->l);
		printf("%d ", p->item);
		bit_inorder(p->r);
	}
}

void bit_postorder(Bit_node p) {
	if(p) {
		bit_inorder(p->l);
		bit_inorder(p->r);
		printf("%d ", p->item);
	}
}

void printassummary(Bit_node p, int spaces) {
	if(p != NULL) {
		if(spaces > 0) {
			printf("\n");
			int i;
			for(i = 0; i <= spaces; i++) {
				printf(" ");
			}
		}
		
		printf("*%d", p -> item); 
		printassummary(p -> l, ++spaces);
		spaces = 0;
		printassummary(p -> r, ++spaces);
	}
}

Bit_node arr2tree(int *a, int size, int i) {
	
	if(i < size) {
		Bit_node bn = malloc(sizeof(struct bit_node));
		
		bn = bit_new(a[i]);
		bn -> l = arr2tree(a, size, 2*i + 1);
		bn -> r = arr2tree(a, size, 2*i + 2);
		i++;

		return bn;
	}
	
	return NULL;
}
