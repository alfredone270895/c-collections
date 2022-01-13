#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct occorrenza{ 
    char* word;
    int n;
};

typedef struct occorrenza *occ;

struct bit_node {
	occ item;
	struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

Bit_node bit_new(occ elem);
void bit_insert(occ elem, Bit_node root);

int bit_find_n(Bit_node p, char *w);
occ bit_find_word(Bit_node root, char *w);

void insert(Bit_node *node, occ elem);
void bit_inorder(Bit_node p);
void bit_invorder(Bit_node p);
void printassummary(Bit_node p, int spaces);

occ occ_new(char *w);
occ find(char *w, occ *p, int length);
void printOcc(occ *p, int length);

int main(void) {

    char *str;
    int sizeStr = 10;
    int countStr = 0;
    
    str = malloc(sizeStr * sizeof(char)); 
    
    Bit_node root = NULL;
        
    char ch;
    do {
        ch = getchar();
        if(isalpha(ch)) {
            ch = tolower(ch);
            str[countStr++] = ch;
        } else {
            str[countStr] = '\0';
            if(countStr > 0) {
                occ temp = bit_find_word(root, str);
                if(temp == NULL) {
                    insert(&root, occ_new(str));
                } else {
                    //printf("PAROLA: %s\n", temp -> word);
                    temp -> n++;
                }

                countStr = 0;
                str = malloc(10 * sizeof(char));
            }
        }
        
    } while(strcmp(str, "stop") != 0);
    //countStr = 0;
    
    /*do {
        ch = getchar();
        if(ch == '\n') {
            str[]
        }
    } while(strcmp(str, "stop") != 0);*/
    printassummary(root, 0);
   /* bit_inorder(root);
    printf("\n");
    bit_invorder(root);*/
    //printOcc(parole, i);
    
    return 0;
}

occ occ_new(char *w) {
    occ p;
    p = malloc(sizeof(struct occorrenza));
    p -> word = w;
    p -> n = 1;
    return p;
}

occ find(char *w, occ *p, int length) {
    int i;
    for(i = 0; i < length; i++) {
        if(strcmp(w, p[i] -> word) == 0) {
            return p[i];
        }
    }
    return NULL;
}

void printOcc(occ *p, int length) {
    int i;
    for(i = 0; i < length; i++) {
        printf("%s %d\n", p[i] -> word, p[i] -> n);
    }
}

Bit_node bit_new(occ elem) {
	Bit_node bn = malloc(sizeof(struct bit_node));
	bn -> item = elem;
	bn -> l = NULL;
	bn -> r = NULL;
	return bn;
}

void insert(Bit_node *node, occ elem)
{
    if (*node == NULL)
      *node = bit_new(elem);
    else if (strcmp((*node)->item->word, elem-> word) > 0) {
        insert(&(*node)->l, elem);
    } else {
        insert(&(*node)->r, elem);        
    }
}

int bit_find_n(Bit_node p, char *w) {

//    if(root == NULL) {
//        return 0;
//    } else {
//        if(strcmp(root -> item -> word, w) == 0) {
//            return root -> item -> n;
//        } else if (strcmp(root -> item -> word, w) > 0) {
//            bit_find_n(root -> l, w);
//        } else {
//            bit_find_n(root -> r, w);
//        }
//    }
}

occ bit_find_word(Bit_node root, char *w) {
    if(root == NULL) {
        return NULL;
    } else {
        //printf("(CONTROLLO)%s-%s\n", root -> item -> word, w);
        if(strcmp(root -> item -> word, w) == 0) {
            printf("ESCO\n");
            return root -> item;
        } else if (strcmp(root -> item -> word, w) > 0) {
            bit_find_word(root -> l, w);
        } else {
            bit_find_word(root -> r, w);
        }
    }
}

void bit_inorder(Bit_node p) {
	if(p) {
		bit_inorder(p->l);
		printf("%s %d\n", p->item->word, p -> item -> n);
		bit_inorder(p->r);
	}
}

void bit_invorder(Bit_node p) {
	if(p) {
		bit_invorder(p->r);
		printf("%s %d\n", p->item->word, p -> item -> n);
		bit_invorder(p->l);
	}
}

void printassummary(Bit_node p, int spaces) {
	if(p != NULL) {
		if(spaces > 0) {
			printf("\n");
			int i;
			for(i = 0; i < spaces; i++) {
				printf(" ");
			}
		}
		
		printf("*%s", p -> item -> word); 
		printassummary(p -> l, ++spaces);
		spaces = 0;
		printassummary(p -> r, ++spaces);
	}
}