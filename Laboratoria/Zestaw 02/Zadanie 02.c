#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <time.h>

const char* START_MESSAGE = "Podaj n: "
const char* NUMBERS_ARE_EQUAL_MESSAGE = "Liczby sa rowne \n"
const char* NUMBERS_ARE_DIFFERENT_MESSEGE = "Liczby sa rozne \n"

int main() {
	int n;

	srand(time(NULL));
	printf(START_MESSAGE);
	scanf("%i", &n);

	int p[2];
	pipe(p);

	int random = (rand() % 100 + 1);
	printf("Wylosowano: %i \n", random);

	for (int i = 0; i < n; i++) {
		if (fork()) {
			int descendant;

			scanf("%d", &pdescendant);
			write(p[1], &descendant, sizeof(int));

			if(descendant == random) printf(NUMBERS_ARE_EQUAL_MESSAGE);
			else printf(NUMBERS_ARE_DIFFERENT_MESSEGE);

			exit(0);
		}
	}
	close(p[1]);

	int buffer;
	for (int i = 0; i < n; i++) {
		read(p[0], &buffer, sizeof(buffer));
		printf("%i \n", buffer);

		if (buffer == random) printf(NUMBERS_ARE_EQUAL_MESSAGE);
		else printf(NUMBERS_ARE_DIFFERENT_MESSEGE);
	}

	return 0;
}
