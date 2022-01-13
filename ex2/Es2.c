#include <stdio.h>
#include <stdlib.h>

int isVocal(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    }
    
    return 0;
}

int main(int argc, char **argv) {
    for(int i = 1; i < argc; i++) {
        int lettera = 0;
        do {
            if(isVocal(argv[i][lettera]) == 1) {
                printf("%cf%c", argv[i][lettera], argv[i][lettera]);
            } else {
                printf("%c", argv[i][lettera]);
            }
            lettera++;            
        } while(argv[i][lettera] != '\0');
        printf(" ");
    }
    
    printf("\n");
    
    return 0;
}