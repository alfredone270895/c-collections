#include <stdio.h>
#include <stdlib.h>

typedef int *Heap;

struct pqueue { 
    Heap h;
    int size;
    int count; 
};
struct node {
    int dato;
    struct node *next;
};

typedef struct pqueue *Pqueue;

/* crea una coda di priorità vuota che potrà contenere al massimo n Item */
Pqueue pqueue_new( int n );

/* distrugge la coda di priorità */
void pqueue_destroy( Pqueue );

/* restituisce la lunghezza della coda di priorità */
int pqueue_length( Pqueue );

/* inserisce l’Item nella coda di priorità */
void pqueue_insert(Pqueue p, int x);

/* inserisce l’Item nella coda di priorità */
void pqueue_insert( Pqueue, int );
void pqueuee_insert(Pqueue p, struct node *n_node);

//void pqueuee_insert(Pqueue , struct node);

/* estrae dalla coda di priorità l’Item con chiave minima */
int pqueue_extractmin(Pqueue);

/* restituisce l’Item con chiave minima nella coda di priorità */
int pqueue_min( Pqueue );

void heapify_down(Heap h, int i, int n);
void heapify_up(Heap h, int i);

void pqueue_sort(int a[], int l, int r );



int main(void) {
    /***********      Es1.c      **********/
/*    int a[] = {11, 3, 2, 8, 4, 1, 5};
    
    pqueue_sort(a, 5, 6);*/
    
    struct node **list = malloc(3 * sizeof(struct node));
    struct node *node;
    
    Pqueue p = malloc(sizeof(Pqueue));
    p = pqueue_new(3);
    
    int i, k;
    for(i = 0;i < 2; i++) {
        list[i] = malloc(sizeof(struct node));
        node = list[i];
        for(k = 0; k < 2; k++) {
            int num;
            scanf("%d", &num);
            
            node -> dato = num;
            printf("%d\n", node -> dato);
            node -> next = malloc(sizeof(struct node));
            node = node -> next;
        }
        
    }
    
    for(i = 0; i < 3; i++) {
        pqueuee_insert(p, list[i]);
    }
    
    int t;
    int *tot = malloc(9 * sizeof(int));
    for(t = 0; t < 9; t++) {
        tot[t] = pqueue_extractmin(p);
        printf("%d ", tot[t]);
    }
    
    
    return 0;
}

Pqueue pqueue_new(int n) {
    
    Pqueue p = malloc(sizeof(struct pqueue));
    
    p -> h = malloc((n + 1) * sizeof(int));
    p -> size = n + 1;
    p -> count = 1;
    
    return p;
}

void pqueue_destroy(Pqueue p) {
    free(p);
}

int pqueue_length(Pqueue p) {
    return p -> size;
}

int pqueue_min(Pqueue p) {
    return p -> h[1];
}

int father(int i) {
    return i/2;
}

int pqueue_extractmin(Pqueue p) {
    int toReturn = pqueue_min(p);
    p -> h[1] = p -> h[p -> count - 1];
    p -> count--;
    heapify_down(p->h, 1, p->count);
    return toReturn;
}

void swap(Heap h, int x, int y) {
    int temp = h[x];
    h[x] = h[y];
    h[y] = temp;
}

void heapify_up(Heap h, int i) {
    if(i > 1) {
        int j = father(i);
        if(h[i] < h[j]) {
            swap(h, i, j);
            heapify_up(h, j); 
        }
    }
}

void heapify_down(Heap h, int i, int n) {
    if (2*i <= n ) {
        int j;
        if ( 2*i == n ) {
            j = 2*i;
        } else {
           if(h[2*i] < h[2*i + 1]) {
               j = 2*i;
           } else {
               j = 2*i + 1;
           }
        }
        
        if(h[j] < h[i]) {
            swap(h, i, j);
            heapify_down(h, j, n);
        }
    }
}

void pqueue_insert(Pqueue p, int x) {
    
    if(p -> count + 1 <= p -> size) {
        p -> h[p -> count++] = x;
        heapify_up(p -> h, p -> count - 1);
        printf("Inserito: %d\n", x);
    } else {
        printf("Heap completo!\n");
    }
    
}

void pqueuee_insert(Pqueue p, struct node *n_node) {
    if(p -> count + 1 <= p -> size) {
        p -> h[p -> count++] = n_node;
        heapify_up(p -> h, p -> count - 1);
       // printf("Inserito: %d\n", x);
    } else {
        printf("Heap completo!\n");
    }
}

void pqueue_sort(int a[], int l, int r) {
    int a_length = r-l;
    Pqueue p = pqueue_new(a_length);
    int i;
    printf("Dimensione coda: %d\n", a_length);
    for(i = l; i <= a_length + l; i++) {
        pqueue_insert(p, a[i]);
    }
    
    while(p -> count > 1) {
        printf("%d\n", pqueue_extractmin(p));
    }
    pqueue_destroy(p);
}