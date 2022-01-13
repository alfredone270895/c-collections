#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int smallest_word_index(char *s[] , int n) {
    char w_min = *s[0];
    int index = 0;
    
    for(int i = 1; i < n; i++) {
        if(strcmp(&w_min, s[i]) > 0) {
            w_min = *s[i];
            index = i;
        }
    }
    
    return index;
}

int main( void ) {
    char *dict[] = { "ciao", "mondo", "come", "aaa", "bene", "questo", "bane" };
    int lun = 7, pos;
    
    pos = smallest_word_index( dict, lun );
    
    printf( "La parola minima si trova in posizione %d.\n", pos );
    
    return 0;
}