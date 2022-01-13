#include <stdio.h>
#include <ctype.h>
void max_secondmax ( int a[], int n, int *max, int *second_max ){
	for (int i = 0; i < n; i++)
	{
		if(*max<a[i]){
			*max=a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if((*max>a[i])&&*second_max<a[i]){
			*second_max=a[i];
		}
	}
}
int main()
{
	/* Scrivete una funzione con prototipo void max_secondmax ( int a[], int n, int *max, int *second_max ) che,
	 dato un array a di lunghezza n individui il valore più grande in a e il secondo elemento per grandezza in a,
	  e li memorizzi nelle variabili puntate da max e second_max. */
	int array[10]={100000,20222,1512,602312312,10023,3433,34,355,90,22};
	int max=0,second_max=0;
	max_secondmax(array,10,&max,&second_max);
	printf("First max: %d Second max: %d",max,second_max);
	return 0;
}