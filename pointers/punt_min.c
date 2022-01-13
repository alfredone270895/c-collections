#include <stdio.h>
#include <ctype.h>
int *smallest( int a[], int n ){
	int *min=a;
	for (int i = 1; i < n; i++)
	{
		if(*min>a[i]){
			min=&a[i];
		}
	}
	return min;
}
int main()
{
	/* Scrivete una funzione con prototipo int *smallest( int a[], int n ) che,
	 dato un array a di lunghezza n, 
	 resti- tuisca un puntatore all’elemento più piccolo dell’array. */
	int array[10]={100000,20222,1512,602312312,10023,3433,34,355,90,22};
	printf("%d",*(smallest(array,10)));
	return 0;
}