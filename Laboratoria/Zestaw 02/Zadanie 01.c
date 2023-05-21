#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

// Main
int main() {
	// Maksymalna ilość liter do zapisania w pliku plik1
	const int size = 50;
	
	// Zaalokowanie zmiennej do wyświetlenia ile znaków zapisano
	int actual_size;
	
	// Ścieżka do pliku 2
	const char* path2 = "plik2";
	
	// Potomek 1
	if(fork()) {
		// Wyświetlenie ID procesu oraz ID procesu potomnego
		printf("1.Potomek, Proces %i, potomek %i \n", getpid(), getppid());
		// Zaalokowanie pliku file1, z możliwością utworzenia oraz zapisu
		int file1 = open("plik1.txt", O_WRONLY|O_CREAT, 0777);
		
		// Potomek 1 potomka 1
		if(fork()) {
			// Wyświetlenie ID procesu oraz ID procesu potomnego
			printf("1.Potomek potomka, proces %i, potomek %i \n", getpid(), getppid());
			// Zaalokowanie bufera znaków buffer1 z pojemnością size
			char buff[size];
			// Zapisanie wartości ze standardowego wejścia do bufera buffer1
			scanf("%s", buff);
			
			// Zaalokowanie realnej wartości potrzebnej bo bufera buffer1
			actual_size = strlen(buff);
			// Zapisanie zawartości bufera buffer1 do pliku file1
			write(file1, buff, actual_size);
			
			// Wyjście z potomka
			exit(0);		
		}
	// Zamknięcie pliku file1
	close(file1);
	// Wyjście z potomka
	exit(0);
	}
	
	// Potomek 2
	if(fork()) {
		// Wyświetlenie ID procesu oraz ID procesu potomnego
	  	printf("2.Potomek, Proces %i, potomek %i \n", getpid(), getppid());
		// Zaalokowanie pliku file1, z możliwością odczytu
		int file1 = open("plik1.txt", O_RDONLY, 0777);
		// Zaalokowanie pliku file2, z możliwością utworzenia, zapisu oraz odczytu
		int file2 = open("plik2.txt", O_CREAT|O_WRONLY|O_RDONLY, 0777);
		// Zaalokowanie buffera znaków buffer2 z pojemnością size
		char buffer2[size];
		
		// Odczyt z pliku file1 do bufera buffer2
		read(file1, buffer2, size);
		// Zapis z bufera buffer2 do pliku file2
		write(file2, buffer2, size);
		
		// Potomek 1 potomka 2
		if(fork()) {
			// Wyświetlenie ID procesu oraz ID procesu potomnego
			printf("2.Potomek potomka, proces %i, potomek %i \n", getpid(), getppid());
			
			// Sprawdzenie czy plik file2 ma możliwość odczytu
			if(access(path2, R_OK)) {
				// Wyświetlenie wiadomości możliwości odczytu
				printf("plik2 ma mozliwosc odczytu \n");
			} else {
				// Wyświetlenie wiadomości o braku możliwości odczytu
				printf("plik2 nie ma mozliwosci odczytu \n");
			}
			
			// Sprawdzenie czy plik file2 ma możliwość zapisu
			if(access(path2, W_OK)) {
				// Wyświetlenie wiadomości możliwości zapisu
				printf("plik2 ma mozliwosc zapisu \n");
			} else {
				// Wyświetlenie wiadomości o braku możliwości zapisu
				printf("plik2 nie ma mozliwosc zapisu \n");
			}
			
			// Sprawdzenie czy plik file2 ma możliwość wykonywania
			if(access(path2, X_OK)) {
				// Wyświetlenie wiadomości możliwości wykonywania
				printf("plik2 ma mozliwosc wykonania \n");
			} else {
				// Wyświetlenie wiadomości o braku możliwości wykonywania
				printf("plik2 nie ma mozliwosc wykonania \n");
			}

			// Wyjście z potomka
	    	exit(0);
		}
	// Zamknięcie pliku file1
	close(file1);
	// Zamknięcie pliku file2
	close(file2);
  
	// Wyjście z potomka
	exit(0);
	}
	
	// Proces macierzysty
	// Wyświetlenie ilości zapisanych znaków do pliku file1
	printf("Ilosc znakow zapisanych do pliku1: %i \n", actual_size);
	
	// Zakończenie działania programu
	return 0;
}
