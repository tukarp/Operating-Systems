#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// Main
int main() {
	// Zadanie 1
	// Wyświetlenie ID procesu potomnego
	printf("Proces potomny %i \n", getpid());

	// Zaalokowanie ścieżek do plików P1 i P2
	const char* path1 = "/home/tom/Desktop/P1.txt";
	const char* path2 = "/home/tom/Desktop/P2.txt";
	
	// Potomek 1
	if(fork()) {
		// Wyświetlenie ID procesu oraz ID procesu potomnego
		printf("1.Proces %i, potomek %i \n", getpid(), getppid());
		// Zaalokowanie pliku file1, z możliwością utworzenia, zapisu oraz odczytu
		int file1 = open("/home/tom/Desktop/P1.txt", O_WRONLY|O_CREAT|O_RDONLY, 0777);
		// Zaalokowanie pliku file2, z możliwością utworzenia, zapisu oraz odczytu
		int file2 = open("/home/tom/Desktop/P2.txt", O_WRONLY|O_CREAT|O_RDONLY, 0777);
		// Potomek 1 potomka 1
		if(fork()) {
			// Wyświetlenie ID procesu oraz ID procesu potomnego
			printf("1.Proces %i, potomek %i \n", getpid(), getppid());
			// Zaalokowanie buffera znaków buffer1
			char buffer1[20];
			// Wczytywanie znaków ze standardowego wejścia do buffera1
			read(stdin, buffer1, 20);
			// Zapis danych z buffera1 do pliku file1
			write(file1, buffer1, 20);
			
			// Potomek 1 potomka 1 potomka 1
			if(fork()) {
				// Wyświetlenie ID procesu oraz ID procesu potomnego
				printf("1.Proces %i, potomek %i \n", getpid(), getppid());
				// Utworzenie kopii deskryptora pliku file1
				int dup_file1 = dup(file1);
				// Zaalokowanie buffera znaków buffer2
				char buffer2[20];
				// Wczytanie deskryptora pliku dup_file1 do bufera buffer2
				read(dup_file1, buffer2, 20);
				
				// Wyjście z potomka
				exit(0);
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

	// Potomek 2
	if(fork()) {
		// Wyświetlenie ID procesu oraz ID procesu potomnego
		printf("2.Proces %i, potomek %i \n", getpid(), getppid());
		// Zaalokowanie pliku file1, z możliwością odczytu
		int file1 = open("/home/tom/Desktop/P1.txt", O_RDONLY);
		// Zaalokowanie pliku file2, z możliwością zapisu
		int file2 = open("/home/tom/Desktop/P2.txt", O_WRONLY);
		
		// Zaalokowanie buffera znaków buffer3
		char buffer3[100];

		// Czytanie danych z pliku file1 do bufera buffer3
		read(file1, buff3, 100);
		// Zapis danych z bufera buffer3 do pliku file2
		write(file2, buff3, 100);
		
		// Zamknięcie pliku file1
		close(file1);
		// Zamknięcie pliku file2
		close(file2); 
		
		// Potomek 1 potomka 2
		if(fork()) {
			// Wyświetlenie ID procesu oraz ID procesu potomnego
			printf("2.Proces %i, potomek %i \n", getpid(), getppid());
			// Zaalokowanie pliku file2, z możliwością odczytu
			int file2 = open("/home/tom/Desktop/P2.txt", O_RDONLY);

			// Zaalokowanie buffera znaków buffer4
			char buffer4[100];

			// Zmienianie pozycji wskaźnika odczytu deskryptora pliku file2
			lseek(file2, 10, SEEK_CUR);
			
			// Zaalokowanie licznika "i" i zainicjalizowanie jego wartości
			int i = 0;
			// Póki buffer4 nie jest pusty
			while(buffer4[i] != '\0') {
				// Wartość bufera buffer4[i] jest znakiem spacji
				buffer4[i] = ' ';
				// Iteruj dalej
				i++;
			}

			// Odczyt zawartości pliku file2 za pomocą bufera buffer4
			read(file2, buffer4, 100);
			// Wyświetlenie zawartości pliku przesunietej o 10 bajtów w prawo
			printf("Tresc pliku przesunieta o 10 bajtow w prawo: %s \n", buffer3);
			
			// Zamknięcie pliku file2
			close(file2);
			
			// Potomek 1 potomka 1 potomka 2
			if(fork()) {
				// Wyświetlenie ID procesu oraz ID procesu potomnego
				printf("2.Proces %i, potomek %i \n", getpid(), getppid());
				
				// Jeśli dostęp do pliku ze ścieżki path2 nie jest równy:
				// Właściciel może odczytać, zapisać oraz wykonać plik
				// Grupa może odczytać, zapisać oraz wykonać plik
				// Pozostali mogą jedynie odczytać plik
				if(access(path2, 0774) != 0) {
					// Zamień go 0774
					chmod(path2, 0774);
				}
				// Wyjście z potomka
				exit(0);
			}
		// Wyjście z potomka
		exit(0);
		}
	// Wyjście z potomka
	exit(0);
	}
	
	// Potomek 3
	if(!fork()) {
		// Wyświetlenie ID procesu oraz ID procesu potomnego
		printf("3.Proces %i, potomek %i \n", getpid(), getppid());
		
		// Utworzenie procesu zombie numer 1
		if(!fork()) {
			// Wyświetlenie ID procesu zombie oraz ID procesu potomnego
			printf("Zombie nr.1, proces %i, potomek %i \n", getpid(), getppid());
			// Wyjście z potomka
			exit(0);
		}
		
		// Utworzenie procesu zombie numer 2
		if(!fork()) {
			// Wyświetlenie ID procesu zombie oraz ID procesu potomnego
			printf("Zombie nr.2, proces %i, potomek %i \n", getpid(), getppid());
			// Wyjście z potomka
			exit(0);
		}
		// Uśpij program na 10 milisekund
		sleep(10);
		// Poczekaj
		wait(0);
	}
	// Poczekaj
	wait(0);
	
	// Zadanie 2
	// Potomek 4
	if(fork()) {
		// Wyświetlenie ścieżki do bieżącego katalogu za pomocą funkcji "execlp()"
		// oraz komendy "pwd"
		printf("Sciezka biezacego katalogu: %i \n", execlp("pwd", "pwd", NULL));	
		// Wyjście z potomka
		exit(0);
	}
	
	// Potomek 5
	if(fork()) {
		// Wyświetlenie listy procesów za pomocą funkcji "execlp()"
		// oraz komendy "ps"
		printf("Lista procesow: %i \n", execlp("ps", "ps", NULL));
		// Wyjście z potomka
		exit(0);
	}
	
	// Zakończenie działania programu
	return 0;
}
