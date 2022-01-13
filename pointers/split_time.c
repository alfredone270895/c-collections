#include <stdio.h>
#include <ctype.h>
void split_time( long int tot_sec, int *h, int *m, int *s ){

	*h=tot_sec/3600;
	*m=(tot_sec-(*h*3600))/60;
	*s=(tot_sec-(*h*3600)-(*m*60));
}

int main()
{
	/* Scrivete una funzione con prototipo void split_time ( long int tot_sec, int *h, int *m, int *s ) che, 
	dato un orario fornito in numero di secondi dalla mezzanotte, calcoli l’orario equivalente in ore, 
	minuti, secondi, e lo memorizzi nelle tre variabili puntate da (h), (m) e (s) rispettivamente. */
	int h=0,m=0,s=0;
	split_time(1000000,&h,&m,&s);
	printf("Ore: %d ,Minuti: %d ,Secondi %d",h,m,s);
	return 0;
}