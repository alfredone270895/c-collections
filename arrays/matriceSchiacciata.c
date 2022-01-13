
#include <stdio.h>
#include <ctype.h>
typedef int bool;
#define true 1
#define false 0
int main(void)
{
	/*
	Scrivete un programma che legga due interi r, c, seguiti da una matrice di r righe e c 
	colonne contenente lettere maiuscole e asterischi, e che stampi in output la matrice che si 
	ottiene da quella in input schiacciando verso il basso le lettere e facendo galleggiare gli asterischi.
	 Ad esempio, se la matrice è data da
	V * S
	* * B
	K * *
	* S *
	il programma dovrà stampare la matrice seguente:
	* * *
	* * *
	V * S
	K S B
	Potete assumere che r e c siano al massimo pari a 100.
	*/
	

	int r,c,i,j;
	printf("Inserisci numero di righe\n");
	scanf("%d",&r);
	printf("Inserisci numero di colonne\n");
	scanf("%d",&c);

	char matrice[100][100]={""};
	printf("Inserisci la tua matrice\n");
	for(i = 0; i < r; ++i)
	{	
		if(i>0){
			printf("\n");
		}
	   	for(j = 0; j < c; ++j) 
	   	{
	      scanf("%c",&matrice[i][j]);
	      printf("%c",matrice[i][j]);
	   	}
	}
	
  
   return(0);

}