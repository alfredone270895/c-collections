#include <stdio.h>
#include <ctype.h>
int lung_stringa(char *s){
	int lungh=0;
	while(*s++!='\0'){
		lungh++;
	}
	return lungh;
}

int main()
{
	/* Scrivete una funzione con prototipo int lung_stringa( char *s ) che, 
	data una stringa s, ne calcoli la lunghezza.
	 Provate a scrivere il programma usando un puntatore a carattere per scorrere la stringa.
 	*/
 	char *string="alfredodallari";
 	printf("%d",lung_stringa(string));
	return 0;
}