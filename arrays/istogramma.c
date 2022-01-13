
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	/*
	Scrivete un programma che legga una sequenza di caratteri terminata da un punto e che visualizzi un 
	istogramma con una barra per ogni carattere dell’alfabeto, lunga quanto il numero delle sue occorrenze. 
	Il programma non deve visualizzare le barre delle lettere che non compaiono e non deve fare distinzione fra maiuscole e minuscole 
	(a tal fine potete usare le funzioni dichiarate nel file ctype.h).
	*/
	int occorrenze['Z'-'A'+1]={};
	int i,n;
	char c;
	while((c=getchar())!='.'){
		if(isalpha(c))
			occorrenze[toupper(c)-'A']++;
	}

	for (c = 'A'; c <='Z'; c++)
	{
		printf("%c",c);
		if((n=occorrenze[c-'A'])>0){
			for (i = 0; i < n;i++)
			{
				printf("*");
			}
		}
		printf("\n");
	}
	
  
   return(0);

}

