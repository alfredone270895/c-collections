#include <stdlib.h>
#include <stdio.h>
#include <string.h> 


//Conviene porre la definizione
typedef struct element element;


struct element {
	int value; /* valore dell’elemento */
	element *next; /* indirizzo del prossimo elemento */
};

void *my_malloc(int size){//alloco variabile del puntatore in memoria
	int *pointer;
	pointer=malloc(size);
	if(pointer!=NULL){
		return pointer;
	}else{
		printf("\nATTENZIONE ALLOCAZIONE FALLITA!\n");
		exit(0);
	}
}
//ricerca elemento nella lista 
element *search(int n,element *h){
	element *p;
	for ( p = h; p!= NULL; p = p -> next ) 
		if ( p -> value == n ){
			return p; 
		}
	return NULL;
}

/*che inserisce in testa alla lista h un nuovo elemento contenente n e restituisce la lista ottenuta 
(ossia, l’indirizzo
del primo elemento della nuova lista).
Conviene inserire il nuovo elemento in testa in modo tale che il numero di operazioni 
richieste sia costante (non
dipende dalla lunghezza della lista). Non è necessario trattare il caso della lista h vuota a parte.
*/
element *insert(int n,element *h){
	element *new_element; //assegno variabile new element alla struct dei nodi 
	new_element = my_malloc( sizeof( element ) );//alloco variabile in memoria
	new_element -> value = n;
	new_element -> next = h;
	return new_element;
}
/*che stampa tutti gli elementi della lista h.
Per provare le funzioni scritte finora, scrivere in main() 
il codice dell’operazione ’p’ e dell’operazione ’+n’, 
tralasciando per il momento il controllo di appartenenza di n alla lista h.*/
//stampa ricorsiva 
void printList(element* h){
	if(h==NULL)
    return;
	printf("%d\n", h->value);
  	printList(h->next);
}
/*che cancella l’elemento con valore n nella lista h e restituisce la lista ottenuta.
Distinguere i casi in cui l’elemento da cancellare è il primo della lista e il caso in cui non è il primo.
Se n non è nella lista, la funzione non deve fare nulla.
Aggiungere in main() il codice per l’operazione ’-n’.*/
element* delete(int n, element *h){
	for ( cur = h, prev = NULL;cur != NULL && cur -> value != n; prev = cur; cur = cur -> next ){
		if ( cur == NULL )
			return h; /* n non trovato */
		if (prev == NULL )
			h = h -> next; /* n nel primo nodo */
		else
			prev -> next = cur -> next; 
			free(cur);
		return h;
	}

}

/*che cancella tutti gli elementi della lista h.
Aggiungere in main() l’operazione ’d’.*/
void destroy(element* h){

}
/*Per completare il programma list.c, rimane da fare la stampa degli elementi della lista in ordine inverso.
Per accedere ad un elemento della lista bisogna scorrerla a partire dalla testa e,
dato un puntatore ad un elemento, non è possibile ottenere un puntatore all’elemento precedente
se non scorrendo nuovamente la lista dalla testa.
Per evitare questo problema, si può quindi procedere in due modi.
*/
/*
•Si possono copiare gli elementi della lista in un array, quindi stamparlo al contrario. 
Più in dettaglio, occorre per prima cosa definire una funzione
che, data una lista h contenente n interi, restituisce l’indirizzo di un array di interi creato dinamicamente 
contenente gli elementi della lista. Quindi si stampa l’array al contrario. 
A questo punto l’array non serve più e la memoria da esso occupata può essere rilasciata.

int* listToArray(element* h, int n){

}
*/
//• In alternativa si può usare la ricorsione. Più precisamente, occorre definire una funzione
//che scorre la lista richiamando sè stessa ad ogni nuovo elemento e si conclude stampando l’elemento stesso.
void printInv( element* h ){
	if(h==NULL)
	return;
	printInv(h->next);
	printf("%d ",h->value);
}

int main(){
// DEFINIZIONE VARIABILI LOCALI
	element *list;
	char c;
	int numeroInserito,count=0;
	while( ( c = getchar()) != 'f' ){
	/* c e’ il prossimo carattere letto da standard input
	       Il ciclo termina quando c e’ il carattere ’f’ */
		switch(c){ 
			
			case '+':	//Se n non appartiena all’insieme lo inserisce, altrimenti non compie alcuna operazione
				printf("Inserisci numero che vuoi inserire\n");
				scanf("%d",&numeroInserito);
				list=insert(numeroInserito,list);
			break; 

			case '-':	//Se n appartiene all’insieme lo elimina, altrimenti non compie alcuna operazione
			             
			break;

			case '?'://Stampa un messaggio che dichiara se n appartiene all’insieme
				printf("Inserisci numero che vuoi cercare\n");
			    scanf("%d",&numeroInserito); 
			    if(search(numeroInserito,list)!=NULL){
			    	printf("Il numero che stai cercando e presente nella lista\n");  
			    }
			break;

			case 'c':// Stampa il numero di elementi dell’insieme
			         
			break;

			case 'o':	//Stampa gli elementi dell’insieme nell’ordine inverso
				printList(list);
			            
			break;

			case 'd'://Cancella tutti gli elementi dell’insieme
			            
			break;
			/*
			case 's':	//Cancella tutti gli elementi dell’insieme
				printf("Inserisci numero che vuoi cercare\n");
			    scanf("%d",&numeroInserito); 
			    if(search(numeroInserito)!=NULL){
			    	printf("Il numero che stai cercando e presente nella lista");  
			    }

			break;
			*/


		} // end switch 
	} // end while
   // LA LISTA PUO’ ESSERE CANCELLATA
return 0;
} // end main()