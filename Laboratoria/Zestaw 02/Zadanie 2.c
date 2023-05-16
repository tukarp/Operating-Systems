#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {
	srand(time(NULL));
	int n;
  
	printf("Podaj n: \n");
	scanf("%i", &n);
	
	int p[2];
	pipe(p);
  
	int random = rand() % 100 + 1;
	printf("Wylosowano: %i \n", random);
  
	for(int i = 0; i < n; i++) {
		if(fork()) {
			int potomek;
			
			scanf("%d", &potomek);
			write(p[1], &potomek, sizeof(int));
			
			if(potomek == random) {
				printf("Liczby sa rowne \n");
			} else {
				printf("Liczby sa rozne \n");
			}

			exit(0);
		  }
	}
	close(p[1]);

	int temp;
	for(int i = 0; i < n; i++) {
		read(p[0], &temp, sizeof(temp));
		printf("%i \n", temp);

		if(temp == random) {
			printf("Liczby sa rowne \n");
		}
		else {
			printf("Liczby sa rozne \n");
		}
	}

	return 0;
}
