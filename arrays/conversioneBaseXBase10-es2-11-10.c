#include <stdio.h>

int potenza(numero,esponente){
	int numeroInPotenza=numero;
	if(esponente>0){
		for (int i = 1; i < esponente; i++)
		{
			numeroInPotenza*=numero;
			//printf("numero%d\n",numeroInPotenza);
		}
	}else{
		numeroInPotenza=1;
	}
	return numeroInPotenza;

}

int main(void)
{
	/*Scrivere un programma che dato un numero b (in base 10) e una sequenza s di cifre in {0, . . . b − 1} terminata da un punto, stampi il numero la cui rappresentazione in base b è data da s. Potete assumere che il numero di cifre di s sia sempre minore di 100.
	Esempio di funzionamento:
	Inserisci un intero b e un numero in base b da convertire in base 10: 3 211. Il numero 211 in base 3 equivale al numero 22 in base 10.
	NOTA: è proprio necessario usare un array per svolgere questo esercizio?*/


	int numero=0,base=0,cifraConvertita=0,contatore=0,numeroOk=0;

	printf("Inserisci una base");
	scanf("%d",&base);
	printf("Inserisci un numero");
	scanf("%d",&numero);

	//printf("10 alla terza: %d\n",potenza(10,3));

	do{
		//printf("contatore %d\n",contatore);
		//printf("numero %d\n",numero);
		numeroOk = potenza(base,contatore);
		//printf("numeroOK%d\n",numeroOk);
		cifraConvertita += numeroOk * (numero%10);
		numero/=10;
		contatore++;
	}while(numero!=0);
	printf("Il numero convertito da base %d a base 10 e: %d",base,cifraConvertita);
	
	return 0;
}

