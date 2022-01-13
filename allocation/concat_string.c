#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *concat( const char *s1, const char *s2) { 
	char *result;
	result = malloc( strlen(s1) + strlen(s2) + 1 ); 
	if(result == NULL) {
		printf("malloc␣failure\n");
		exit(EXIT_FAILURE); 
	}
	strcpy(result , s1); 
	strcat(result , s2); 
	return result;
}
int main()
{
	/* Il seguente programma concatena le due stringhe s1 e s2 
	in una nuova stringa di cui restituisce l’indirizzo (ovvero un puntatore che punta ad essa). */
	char *p="";
	p = concat( "abc", "def");
	while(*p!='\0'){
		printf("%c",*p);
		p++;
	}
	return 0;
}