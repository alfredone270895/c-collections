#include <stdio.h>

int main(int argc, char **argv)
{
	int n; int ncifre = 0; int n1; int i = 0; int j = 0; int k = 0;
	scanf("%d", &n);
	n1 = n;
	do {
		ncifre++;
		n1 = nc1 / 10;
	} while (n1 > 0);
	int arrayCifre[ncifre];
	while (n > 0) {
		arrayCifre[i] = n % 10;
		n = n / 10;
		i++;
	}
	int contCifre[10] = {0};
	while (j < ncifre) {
			contCifre[arrayCifre[k]] ++;
			j++;
			k++;
	}
	for (i = 0; i < 10; i++) {
		if(contCifre[i] > 0) {
			printf("La cifra %d viene ripetuta %d volte\n", i, contCifre[i] );
		}
	}
	return 0;
}
