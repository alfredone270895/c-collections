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
                        printf("Già scritto: %s\n", parole[k]->word);
                        esisteParola = 1;
                        index_parola = k;
                        break;
                    }
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
            if(strcmp(string, "stop") == 0) {
                stop += 1;
            }


            l = 0;
            esisteParola = 0;
        } else {
            //ricerca delle parole
            occ *paroleTrovate;
    
            int sizeParoleTrovate = 2;
            parole = malloc(sizeParoleTrovate * sizeof(struct occorrenze));
            
            printf("\nceroc parole\n");
            do {
                char *string = malloc(10 * sizeof(char));
                char ch;
                scanf(" %c", &ch);
                do {
                    string[l] = ch;
                    l++;     
                } while((ch = getchar()) != '\n');
                
                if(strcmp(string, "stop") == 0) {
                    stop += 1;
                } else {
                    int k;
                    for(k = 0; k < i - 1; k++) {
                        if(strcmp(string, parole[k]) == 0) {
                            int j
                            for(j = 0; j < )
                        }
                    }
                    l = 0;
                    free(string);
                }
      
            } while(stop == 1);
        }
        
    } while(stop < 2);
        
    int j;
    for(j = 0; j < i - 1; j++) {
        printf("%s, %d\n", parole[j] -> word, parole[j] -> n);
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
 