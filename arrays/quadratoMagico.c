#include <stdio.h>
#define N 100;
int main(void){
	int n,quadrato[N][N]={{0}},k=1;
	int i,j,inew,jnew,somma,ver=0;
	printf("INSERISCI DIMENSIONE QUADRATO: \n");
	scanf("%d",&n);
	for (int k = 1; k <  n*n; ++k)
	{
		/* code */
		quadrato[i][j]=k;
		inew=(i==0)?n-1:i-1;//oppure con modulo(i-1+n)%n
		jnew=(j==n-1)? 0 : j+1;//oppure con modulo(j-1)%n
		if(quadrato[inew][jnew]==0){
			i=inew;
			j=jnew;
		}else{
			i++;


		}
	}
	//STAMPA DEL QUADRATO
	for (int j = 0; j < n; ++j)
	{
		/* code */
		for (int j= 0; i < n; ++j)
		{
			printf("%2d\t",quadrato[i][j]);
		}
		printf("\n");
	}
}
