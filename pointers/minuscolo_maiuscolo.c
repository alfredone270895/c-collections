#include <stdio.h>
#include <ctype.h>
char *maiuscolo( char *stringa ){
	do{
		//printf("AHOOOOOOOO%c",*stringa);
		*stringa=toupper(*stringa);
	}while( *stringa++ != '\0');
	return stringa;
} 
int main()
{
	/* Scrivete una funzione con prototipo char *maiuscolo( char *stringa ) 
	che trasformi da minuscolo in maiuscolo tutte le lettere del suo argomento 
	stringa e ne restituisca un puntatore al primo carattere. 
	Potete assumere che stringa sia dato da una stringa terminata da ’\0’ contenente caratteri ASCII (non solo lettere). 
	Potete usare la funzione toupper della libreria ctype.h.*/
	char stringa[7] = {'a','l','f','r','e','d','o'};
	maiuscolo(&stringa[0]);
	printf("%s",stringa);
	return 0;
}