#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct bit_node {
	occ item;
	struct bit_node *l, *r;
};

struct occorrenze {
    char *word;
    int n;
};
 
typedef struct occorrenze *occ;
typedef struct bit_node *Bit_node;
 
occ word_new(int sizeW, char *s);
 
int main(void) {
	
    
    return 0;
}
 
occ word_new(int sizeW, char *s) {
    occ w = malloc(sizeof(struct occorrenze));
    w -> n = 1;
    w -> word = malloc((sizeW * sizeof(char)) + 1);
    w -> word = s;   
    return w;            
}


