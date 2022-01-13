#include <stdio.h>
#include <ctype.h>
void scambia( int *p, int *q ){
	int palo=*p;
	*p=*q;
	*q=palo;
}
int main()
{
	/* Scrivete una funzione con prototipo void scambia( int *p, int *q )che 
	scambi i valori delle due variabili puntate da p e q. */
	int p=10,q=100;
	scambia(&p,&q);
	printf("P-> %d Q-> %d",p,q);
	return 0;
}