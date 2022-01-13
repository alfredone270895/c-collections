#include <stdio.h>
#include <ctype.h>
int main() {
  /*Scrivete un programma per la gestione di una semplice rubrica: attraverso 
  un menu l’utente deve poter visualiz- zare la rubrica e inserire nuovi numeri.
  Ogni voce della rubrica deve essere composta almeno da un nominativo e da un numero di telefono;
  documentate con opportuni commenti eventuali assunzioni sulla lunghezza massima delle stringhe e sul numero massimo di 
  voci presenti in rubrica.*/
  char carattereInserito='';
  
  while(carattereInserito!='e'){
    printf("Inserisci un comando(v per Rubrica,a per inserire nuovo contatto ,e per uscire)\n");
    scanf("%c",&carattereInserito);
    if(carattereInserito=='v'){
      for (int i = 0; i < count; ++i)
      {
        
      }
    }else if(carattereInserito=='a'){

    }
    printf("Vuoi continuare? e per uscire\n");
    scanf("%c",&carattereInserito);
  }
  return 0;
}