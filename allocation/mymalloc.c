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
int main(void)
{
	/* code */
	int *arr,i=0;
	int size=10;

	arr=my_malloc(size*(sizeof(int)));

	for (;;++i)
	{
		if(i>=size){
			size=(size+10)*(sizeof(int));
			arr=my_realloc(arr,size*(sizeof(int)));
		}	
		scanf("%d",&arr[i]);
		if(arr[i]==0)break;
	}
	i--;
	for (int k=i; k >=0 ; k--)
	{
		/* code */
		printf("%d\n",arr[k]);
		//printf("%p\n",&arr[k]);//se voglio sapere indirizzo delle variabili &nomeVar e %p(%puntatoreType)
	}
	

	//arr=my_realloc(arr,1024*(sizeof(int))); per il primo esercizio dovevo allocare con mymalloc e riallocare con myrealloc

	//printf("%p",arr); puntatore allocato dell'array(indirizzo)
	return 0;
}