#include <stdlib.h>
#include <stdio.h>
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

void *my_realloc(int *pointer,int size){//rialloco variabile del puntatore in memoria
	pointer=realloc(pointer,size);
	if(pointer!=NULL){
		return pointer;
	}else{
		printf("\nATTENZIONE REALLOCAZIONE FALLITA!\n");
		exit(0);
	}
}
int main(int argc, char const *argv[])
{
	/* Scrivete due programmi che leggano una sequenza di interi 
	e la stampino al contrario, allocando la memoria necessaria in modo dinamico attraverso 
	l’uso della funzione malloc.
	1.L’input è dato da una sequenza di numeri terminata da 0;
	 non potendo prevedere quanti numeri verranno inseriti,
	  il vettore andrà ridimensionato man mano: partite da una dimensione fissata piccola (es: 2)
	   e raddoppiate la lunghezza del vettore ogni volta che questo si riempie.

	2.L’input è dato da una sequenza di numeri terminata da 0, 
	come nel caso precedente; di nuovo, 
	il vettore andrà ridimensionato man mano: partite da una dimensione fissata (es: 15) 
	e allungate il vettore di una lunghezza fissa (es: 10) ogni volta che questo si riempie. */
	int *arr,i=0;
	int size=2;
	char c;
	arr=my_malloc(size*(sizeof(int)));
	while((c=getchar())!='0'){
		*arr=(int)c;
		my_realloc(arr,size*=2);
		i++;
		arr++;
	}

	return 0;
}