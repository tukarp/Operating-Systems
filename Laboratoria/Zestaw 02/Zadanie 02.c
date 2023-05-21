#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/wait.h>

// Main
int main() {
	// Ustawienie czasu w programie na losowy
	srand(time(NULL));
	// Zaalokowanie zmiennej n
	int n;
  
	// Inicjalizacja n ze standardowego wejścia
	printf("Podaj n: \n");
	scanf("%i", &n);
	
	// Zaalokowanie tablicy liczb p
	int p[2];
	// Otwarcie komunikacji między procesami
	pipe(p);
  
	// Wylosowanie liczby z zakresu od 1 do 100
	int random = (rand() % 100 + 1);
	// Wyświetlenie komuniaktu o wylosowanej liczbie
	printf("Wylosowano: %i \n", random);
  
	// Pętla iterująca się n - razy
	for(int i = 0; i < n; i++) {
		// Utworzenie potomka
		if(fork()) {
			// Utworzenie zmiennej potomka
			int descendant;
			
			// Inicjalizacja zmiennej potomka ze standardowego wejścia
			scanf("%d", &pdescendant);
			// Zapisanie wielkości liczby potomka do zmiennej p
			write(p[1], &descendant, sizeof(int));
			
			// Sprawdzenie czy potomek jest równy wylosowanej liczbie
			if(descendant == random) {
				// Wyświetlenie komunikatu o równości liczb
				printf("Liczby sa rowne \n");
			} else {
				// Wyświetlenie komunikatu o różności liczb
				printf("Liczby sa rozne \n");
			}
			// Wyjście z potomka
			exit(0);
		  }
	}
	// Zamknięcie komunikacji między procesami
	close(p[1]);

	// Zaalokowanie bufera buffer
	int buffer;
	// Pętla iterująca n - razy
	for(int i = 0; i < n; i++) {
		// Odczytywanie wartości w tablicy p za pomocą bufera buffer
		read(p[0], &buffer, sizeof(buffer));
		// Wyświetlenie wartości bufera buffer
		printf("%i \n", buffer);

		// Sprawdzenie czy buffer i wylosowana liczba są równe
		if(buffer == random) {
			// Wyświetlenie wiadomości o równości liczb
			printf("Liczby sa rowne!\n");
		} else {
			// Wyświetlenie wiadomości o różności liczb
			printf("Liczby sa rozne!\n");
		}
	}

	// Zakończenie działania programu
	return 0;
}
