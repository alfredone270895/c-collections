#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    
    //printf("%d", strcmp("a", "b")); //Restituisce -1
    
    int lettera = 0;
    for(int i = 1; i < argc; i++) {
        
        do {
            if(argv[i][lettera + 1] != 0) {
                if(strcmp(&argv[i][lettera], &argv[1][lettera+1]) > 0) {
                    printf("%c-", argv[i][lettera]);
                } else {
                    printf("%c", argv[i][lettera]);
                }
                lettera++;
            } else {
                printf("%c", argv[i][lettera]);
                break;
            }
        } while(argv[i][lettera] != 0);
        
        printf("\n");

    }
    
    return 0;
}