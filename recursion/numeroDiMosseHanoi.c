#include <stdio.h>
#include <ctype.h>
int moves=0;
void hanoi( int n, int from, int temp, int to){
	//numero di mosse
	moves++;
	if(n>1){
		hanoi(n-1,from,to,temp);

		hanoi(n-1,temp,from,to);
	}
}
int main() { 
/*Obiettivo dell’esercizio è scrivere un programma in grado di giocare al gioco delle torri di Hanoi, ossia di specificare la sequenza 
di mosse da effettuare per risolvere il rompicapo data l’altezza n > 0 della pila. Potete assumere che i tre paletti siano numerati da 
0 a 2 e che gli n dischi siano inizialmente impilati dal 
più piccolo (in cima alla pila) al più grande (sotto tutta la pila) sul paletto 0 e vadano spostati al paletto 2.
Per semplicità, le mosse sono date semplicemente dall’indicazione del paletto da e verso cui si deve muovere il disco.
Ad esempio, una soluzione per una pila di altezza 3 è data dalla seguente sequenza di mosse:
Questo vuol dire che il disco più piccolo va spostato dal paletto 0 al paletto 2, quindi il disco mediano,
ora in cima al paletto 0, va spostato al paletto 1; a questo punto il disco più piccolo (rimasto sul paletto 2)
va rimesso sopra il mediano (ora sul paletto 1) e, finalmente, il disco più grande va spostato dal paletto 0 al paletto 2, 
nella sua posizione finale. Le restanti tre mosse, spostando i due dischi rimanenti dal paletto 1 al paletto 2.
NUMERO DI MOSSE ALLA N meno 1
*/	

	int n;
	scanf("%d",&n);
	hanoi(n,0,1,2);
	printf("Numero di mosse ->%d",n);
	return 0;
}
