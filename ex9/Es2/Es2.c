#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
struct occorrenze {
    char *word;
    int n;
};
 
typedef struct occorrenze *occ;
 
occ word_new(int sizeW, char *s);
 
int main(void) {
               
    occ *parole;
    
    int sizeParole = 2;
    parole = malloc(sizeParole * sizeof(struct occorrenze));
    int num_parole = 2;
    int stop = 0;
    int i = 0;
    int l = 0;
    int esisteParola = 0;
    int index_parola;
    
    occ *paroleTrovate;
    
    int sizeParoleTrovate = 5;
	paroleTrovate = malloc(sizeParoleTrovate * sizeof(struct occorrenze));
    int index_parTrov = 0;

    do {
        if(stop < 1) {
            if(i >= sizeParole) {
                sizeParole += 2;
                parole = realloc(parole, sizeParole * sizeof(struct occorrenze));
            }
            char *string = malloc(10 * sizeof(char));
            char ch;
            scanf(" %c", &ch);
            do {
                string[l] = ch;
                l++;
            } while(isalpha((ch = getchar())));

            if(i == 0) {
                parole[i] = word_new(l, string);
            }

            int k;
            for(k = 0; k < i; k++) {
                if(strcmp(string, "stop") != 0) {
                    if(strcmp(string, parole[k]-> word) != 0) {
                        esisteParola = 0;
                    } else {
                        esisteParola = 1;
                        index_parola = k;
                        break;
                    }
                } else {
                	stop += 1;
                	break;
				}
            }

            if(esisteParola == 1) {
                printf("B\n");
                parole[index_parola] -> n += 1;
            } else {
                printf("A\n");
                parole[i] = word_new(l, string);
                i++;
            }

            l = 0;
            esisteParola = 0;
        } else {
            //ricerca delle parole
            printf("\nCerco parole\n");
            do {
            	if(index_parTrov >= sizeParoleTrovate) {
            		sizeParoleTrovate += 2;
            		paroleTrovate = realloc(paroleTrovate, sizeParoleTrovate);
				}
                char *string = malloc(10 * sizeof(char));
                char ch;
                scanf(" %c", &ch);
                do {
                    string[l] = ch;
                    l++;     
                } while((ch = getchar()) != '\n');
                
	            paroleTrovate[index_parTrov] = word_new(l, string);
	            paroleTrovate[index_parTrov] -> n = 0;
	
	            int k;
	            if(strcmp(string, "stop") != 0) {
	            	for(k = 0; k < i - 1; k++) {
	                    if(strcmp(string, parole[k]-> word) == 0) {
	                        paroleTrovate[index_parTrov] -> n = parole[k] -> n;
	                    }
	                }
	            } else {
	            	stop += 1;
	            	break;
				}
	
	            l = 0;
	            index_parTrov++;
            } while(stop == 1);
        }
        
    } while(stop < 2);
	
	printf("OCCORRENZE DI PAROLE NEL TESTO IN ORDINE ALFABETICO: ****************************************************");    
    int j;
    for(j = 0; j < i - 1; j++) {
        printf("%s, %d\n", parole[j] -> word, parole[j] -> n);
    }
    
    printf("Parole trovate: \n");
    
    int p;
    for(p = 0; p < index_parTrov; p++) {
    	printf("%s %d\n", paroleTrovate[p] -> word, paroleTrovate[p] -> n);
	}
	
    
    
    return 0;
}
 
occ word_new(int sizeW, char *s) {
                occ w = malloc(sizeof(struct occorrenze));
                w -> n = 1;
                w -> word = malloc((sizeW * sizeof(char)) + 1);
                w -> word = s;   
                return w;            
}


