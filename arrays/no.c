int main() {
  int nl, nc, i, j;
  printf("Inserisci numero righe\n");
  scanf("%d",&nl);
  printf("Inserisci numero colonne\n");
  scanf("%d",&nc);

  char matrix[nl][nc];
  for (i = 0; i < nl; i++) {
    for (j = 0; j < nc; j++) {
      int ch = getchar();
      if (ch == '\n' || ch == EOF)
        break;
      matrix[i][j] = (char) ch;
    }
    for (; j < nc; j++) {
      matrix[i][j] = 0;
    }
  }
  // Better to use fputs() or puts() when simply printing a string
  fputs("This is your matrix:\n", stdout);
  for (i = 0; i < nl; i++) {
    for (j = 0; j < nc; j++) {
      if (matrix[i][j]) {
        printf("%c", matrix[i][j]);
      }
    }
    // Add EOL
    fputs("\n", stdout);
  }
  return 0;
}