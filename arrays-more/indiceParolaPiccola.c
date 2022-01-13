#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

/*Scrivete una funzione con prototipo int smallest_word_index( char *s[], int n ) che, dato un array s lungo n di stringhe, 
restituisca l’indice della parola più piccola (secondo l’ordine alfabetico) contenuta nell’array. 
Per effettuare confronti tra stringhe, potete usare la funzione strcmp dal file di intestazione string.h.
Inizializzare un array frastagliato da standard input non è banale; consiglio quindi di testare la vostra funzione 
smallest_word_index usando un main così strutturato:
Modificate le inizializzazioni di dict e lun in modo da testare la funzione con altri argomenti.
*/
int smallest_word_index( char *s[], int n ){
	int lunghezzaMinina=strlen(s[0]),posizione=0;
	for (int i = 1; i < n ; i++)
	{
		/* code */
		if(strlen(s[i])<lunghezzaMinina){
			lunghezzaMinina=strlen(s[i]);
			posizione=i;
		}
	}
	return posizione;
}

int main(int argc, char *argv[]) {
	/*char *dict[] = { "ciaoooooooooo", "mondo", "come", "funziona", "ben", "questo", "programma" };//con i puntatori ho la possibilita di usare array di stringhe
	*/
	int lun = argc, pos;
	pos = smallest_word_index( argv, lun );
	/*for (int i = 0; i < lun; i++)
	{
		printf("%s\n",argv[i]);
	}
	*/
	printf( "La parola minima si trova in posizione %d\n", pos ); 
	//printf("%lu",strlen(dict[6]));per sapere lunghezza della stringa 
	//printf("%d\n",argc);numero di argomenti
	return 0;
}