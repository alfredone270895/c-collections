#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *cerca(struct node *list, int n);
struct node *aggiungi(struct node *list, int n);
struct node *cancella(struct node *list, int n);
void stampaElementi(struct node *list);
void stampaElementi_contrario(struct node *list);
struct node *my_malloc(int size);

int main(void) {
    
    char sel;
    int n;
    int nElementi = 0;
    
    struct node *first = NULL;    
    
    do {
        
        printf("Seleziona un'opzione: ");
        scanf(" %c", &sel);
        
        switch(sel) {
            case '+':
                scanf("%d", &n);

                if(first == NULL) {
                    first = aggiungi(first, n);
                    nElementi++;
                } else {
                    if(cerca(first, n) == NULL) {
                        first = aggiungi(first, n);
                        nElementi++;
                    }
                }
                
                break;
            case '-':
                scanf("%d", &n);
                
                if(first != NULL) {
                    if(cancella(first, n) != NULL) {
                        printf("Cancellato elemento %d.\n", n);
                        nElementi--;
                    } else {
                        printf("Non è stato trovato l'elemento %d.\n", n);
                    }
                } else {
                    printf("Lista vuota.\n");
                }
                
                break;
            case '?':
                scanf("%d", &n);
                if(cerca(first, n) != NULL) {
                    printf("Esiste.\n");
                } else {
                    printf("Non esiste.\n");
                }
                break;
            case 'c':
                printf("Ci sono %d elementi.\n", nElementi);
                break;
            case 'p':
                stampaElementi(first);
                break;
            case 'o':
                stampaElementi_contrario(first);
                break;
            case 'd':
                first = NULL;
                nElementi = 0;
                break;
            default:
                if(sel != 'f') {
                    printf("Nessuna operazione selezionata.\n");
                }
                break;
        }
        
    } while(sel != 'f');
    
    return 0;
}

struct node *cerca(struct node *list, int n) {
    struct node *p;
    for(p = list; p != NULL; p = p->next) {
        if(p -> value == n) {
            return p;
        }
    }
    
    return NULL;
}

struct node *aggiungi(struct node *list, int n) {
    struct node *nNodo;
    
    nNodo = malloc(sizeof(struct node));
    nNodo -> value = n;
    nNodo -> next = list;
    return nNodo;
}

struct node *cancella(struct node *list, int n) {
    struct node *current, *previous;
    
    for(current = list, previous = NULL; current != NULL; previous = current, current = current -> next) {
        
        if(current -> value == n) {
            if(current == NULL) {
                return NULL;
            } 
            
            if(previous == NULL) {
                printf("UUUIIIOOO");
                list = NULL;
            } else {
                previous -> next = current -> next;
                free(current);
            }
            return current;
        }
    }
    
    return NULL;
}

void stampaElementi(struct node *list) {
    struct node *nNodo;
    int i;
    if(list == NULL) {
        printf("Non ci sono elementi.\n");
    } else {
        for(nNodo = list, i = 0; nNodo != NULL; nNodo = nNodo -> next, i++) {
            printf("Nodo %d: %d\n", i, nNodo -> value);
        }    
    }
}

void stampaElementi_contrario(struct node *list) {
    struct node *nNodo;
    int *p;
    int sizeP = 1;
    
    int i;
    if(list == NULL) {
        printf("Non ci sono elementi.\n");
    } else {
        p = malloc(sizeof(struct node));
        
        for(nNodo = list, i = 0; nNodo != NULL; nNodo = nNodo -> next, i++) {
            if(sizeP < i) {
                p = realloc(p, sizeof(struct node) + 1);
                sizeP++;
            }
            
            p[i] = nNodo -> value;
        }
        
        for(int l = i - 1; l >= 0; l--) {
            printf("Nodo %d: %d\n", l, p[l]);
        }
    }
}


struct node *my_malloc(int size) {
    struct node *p = malloc(size);
    if(p != NULL) {
        return p;
    } else {
        printf("Errore\n");
        exit(1);
        return 0;
    }
}