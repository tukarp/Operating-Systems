#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

int main() {
	// Maksymalna ilość liter do zapisania w pliku plik1
	const int size = 50;
	
	// Zmienna do wyświetlenia ile znaków zapisano
	int actual_size;
	
	// Ścieżka do pliku 2
	const char* path2 = "plik2";
	
	// Potomek 1
	if(fork()) {
		printf("1.Potomek, Proces %i, potomek %i \n", getpid(), getppid());
		int file1 = open("plik1.txt", O_WRONLY|O_CREAT, 0777);
		
		if(fork()) {
			printf("1.Potomek potomka, proces %i, potomek %i \n", getpid(), getppid());
			char buff[size];
			scanf("%s", buff);
			
			actual_size = strlen(buff);
			write(file1, buff, actual_size);
			
			exit(0);		
		}
	close(file1);
	exit(0);
	}
	
	// Potomek 2
	if(fork()) {
	  printf("2.Potomek, Proces %i, potomek %i \n", getpid(), getppid());
		int file1 = open("plik1.txt", O_RDONLY, 0777);
		int file2 = open("plik2.txt", O_CREAT|O_WRONLY|O_RDONLY, 0777);
		char buff[size];
		
		read(file1, buff, size);
		write(file2, buff, size);
		
		if(fork()) {
			printf("2.Potomek potomka, proces %i, potomek %i \n", getpid(), getppid());
			
			if(access(path2, R_OK)) {
				printf("plik2 ma mozliwosc odczytu \n");
			} else {
				printf("plik2 nie ma mozliwosci odczytu \n");
			}
			
			
			if(access(path2, W_OK)) {
				printf("plik2 ma mozliwosc zapisu \n");
			} else {
				printf("plik2 nie ma mozliwosc zapisu \n");
			}
			
			
			if(access(path2, X_OK)) {
				printf("plik2 ma mozliwosc wykonania \n");
			} else {
				printf("plik2 nie ma mozliwosc wykonania \n");
			}
			
	    exit(0);
	  }
	close(file1);
	close(file2);
  
	exit(0);
	}
	
	// Proces macierzysty
	printf("Ilosc znakow zapisanych do pliku1: %i \n", actual_size);
	
	return 0;
}
