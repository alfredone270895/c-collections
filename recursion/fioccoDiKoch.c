#include "libpsgraph.h"
void disegnaKoch(int x, int i){
	if(i==0){
		draw(x);
	}else if(i>0){
		draw(x/3);
		turn(315);
		draw(x/3);
		turn(135);
		draw(x/3);
	}
	end (); 
}
int main() { 
/*Realizzate una funzione che, data una lunghezza in millimetri x e un intero i, produce la curva di Koch di ordine i
e di lunghezza x. Essa è definita come segue:
• se i = 0, è un segmento di lunghezza x;
• se i > 0, è ottenuta giustapponendo quattro curve di Koch di ordine i − 1 e di lunghezza x/3, come in
Figura 1.
Dopo averla realizzata, verificate che funzioni (scrivendo un main che la invoca e guardando il file risultante).
a questo punto,per disegnare potete usare le seguenti funzioni(che prendono come argomento un double):
– draw(x): disegna un segmento lungo x millimetri;
– move(x): si sposta (senza disegnare) di un segmento lungo x millimetri;
  1
– turn(x): si gira a destra di x gradi;
• alla fine, dovete invocare la funzione end().
*/	
	start("fiocco.ps");
	disegnaKoch(50,1);
	return 0;
}
