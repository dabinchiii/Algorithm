#include <stdio.h>

int main() {
	int n;
	int i, j, tmp;

	scanf("%d", &n);

	tmp = n - n / 2;

	for (i = 0; i < n; i++) {

		for (j = 0; j < tmp*2-1; j++) {
			if(j%2==0) printf("*");
			else printf(" ");
		}

		printf("\n ");

		for (j = 0; j < (n - tmp)*2-1; j++) {
			if(j%2==0) printf("*");
			else printf(" ");
				
		}

		printf("\n");

	}

	return 0;
}