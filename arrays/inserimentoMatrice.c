#include<stdio.h>
#include<stdlib.h>


int main() {
  int r, c, i, j,k,f,ch,chMat;
  printf("Inserisci numero righe\n");
  scanf("%d",&r);
  printf("Inserisci numero colonne\n");
  scanf("%d",&c);
  
  
  char matrix[r][c];
  for (i = 0; i < r; i++) {
    if(i==0){
      do{
      }while (getchar() != '\n');
    }
    for (j = 0; j < c; j++) {
      ch = getchar();
      if (ch == '\n')
        break;
      matrix[i][j] = (char)ch;
    }
    
    if (j == c)  {
      do{
      }while (getchar()!= '\n');
    }
    /*
    for (; j < c; j++) {
      matrix[i][j] = 0;
    }
    */
  }

  for (f= 0; f< r; f++) {
    for (k = 0;k < c; k++) {
      if(matrix[f][k]!='*'){
        chMat=matrix[f+1][k];
        matrix[f+1][k]=matrix[f][k];
        matrix[f][k]=chMat;
      }
    }
  }
  printf("This is your matrix:\n");
  for (i = 0; i < r; i++) {
    if(i>0){
      printf("\n");
    }
    for (j = 0; j < c; j++) {
      if (matrix[i][j]) {
        printf("%c", matrix[i][j]);
      }
    }
  }
  return 0;
}