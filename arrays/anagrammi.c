
#include <stdio.h>
#include <ctype.h>
typedef int bool;
#define true 1
#define false 0
int main(void)
{
	/*
	Due parole costituiscono un anagramma se l’una si ottiene dall’altra permutando 
	le lettere (es: attore, teatro). Scrivete un programma che legga due parole e verifichi se sono anagrammi.
	Suggerimento: sfruttate il programma scritto per l’esercizio precedente!
	*/
	int occorrenzePrimaParola['Z'-'A'+1]={};
	int occorrenzeSecondaParola['Z'-'A'+1]={};
	int i,n;
	int sonoAnagrammi=false;
	char car1,car2;
	printf("Inserisci una parola \n");
	while((car1=getchar())!='.'){
		if(isalpha(car1))
			occorrenzePrimaParola[toupper(car1)-'A']++;
	}
	printf("Inseriscine un'altra\n");
	while((car2=getchar())!='.'){
		if(isalpha(car2))
			occorrenzeSecondaParola[toupper(car2)-'A']++;
	}

	
	for (char c = 'A'; c <='Z'; c++)
	{
		if(occorrenzePrimaParola[c-'A']==occorrenzeSecondaParola[c-'A']){
			//printf("true\n");
			//printf("occorrenzePrimaParola%d\n",occorrenzePrimaParola[c-'A']);
			//printf("occorrenzeSecondaParola%d\n",occorrenzeSecondaParola[c-'A']);
			sonoAnagrammi=true;
		}else{
			//printf("false\n");
			//printf("occorrenzePrimaParola%d\n",occorrenzePrimaParola[c-'A']);
			//printf("occorrenzeSecondaParola%d\n",occorrenzeSecondaParola[c-'A']);
			sonoAnagrammi=false;	
			break;		
		}
	}

	if(sonoAnagrammi==true){
		printf("Le due parole sono anagrammi");
	}else{
		printf("Le due parole non sono anagrammi");
	}
	
  
   return(0);

}