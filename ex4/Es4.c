#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    int length = 0;
    char *inizio, *fine;
    int pal = 1;
    
    while(argv[1][length] != 0) {
        length++;
    }
    
    for(inizio = &argv[1][0], fine = &argv[1][length-1]; inizio < &argv[1][length/2]; inizio++, fine--) {
        if(*inizio != *fine) {
            pal = 0;
            printf("Non è palindroma\n");
            break;    
        }
    }
    
    if(pal == 1) {
        printf("Palindroma\n");
    }
    
    return 0;
}