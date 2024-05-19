#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>

const char* FILE_PATH1 = "/home/example_user/file1.txt";
const char* FILE_PATH2 = "/home/example_user/file2.txt";

int main() {
	int actualSize;
	const int size = 50;

	// Potomek 1
	if (fork()) {
		char buffer[size];
		int firstChildProcessId = getpid()
		int firstChildParentProcessId = getppid()
		int file1 = open(FILE_PATH1, O_WRONLY|O_CREAT, 0777);
		printf("1.Potomek, Proces %i, potomek %i \n",childProcessId, childParentProcessId);

		// Potomek 1, potomka 1
		if (fork()) {
			int secondChildProcessId = getpid()
			int secondChildParentProcessId = getppid()
			printf("1.Potomek potomka, proces %i, potomek %i \n", secondChildProcessId, secondChildParentProcessId);

			scanf("%s", buffer);
			actual_size = strlen(buffer);
			write(file1, buffer, actual_size);

			exit(0);		
		}
		close(file1);
		exit(0);
	}

	// Potomek 2
	if(fork()) {
		char buffer[size];
		int firstChildProcessId = getpid()
		int firstChildParentProcessId = getppid()
		int file1 = open(FILE_PATH1, O_RDONLY, 0777);
		int file2 = open(FILE_PATH2, O_CREAT|O_WRONLY|O_RDONLY, 0777);
	  	printf("2.Potomek, Proces %i, potomek %i \n", firstChildProcessId, firstChildParentProcessId);

		read(file1, buffer, size);
		write(file2, buffer, size);

		if (fork()) {
			printf("2.Potomek potomka, proces %i, potomek %i \n", getpid(), getppid());

			if (access(FILE_PATH2, R_OK)) printf("Plik %s ma mozliwosc odczytu \n", FILE_PATH2);
			else printf("plik2 nie ma mozliwosci odczytu \n");

			if (access(FILE_PATH2, W_OK)) printf("Plik %s ma mozliwosc zapisu \n", FILE_PATH2);
			else printf("plik2 nie ma mozliwosc zapisu \n");

			if (access(FILE_PATH2, X_OK)) printf("Plik %s ma mozliwosc wykonania \n", FILE_PATH2);
			else printf("Plik %s nie ma mozliwosc wykonania \n", FILE_PATH2);

	    		exit(0);
		}
		close(file1);
		close(file2);
		exit(0);
	}

	printf("Ilosc znakow zapisanych do pliku: %s - %i \n", FILE_PATH1, actual_size);

	return 0;
}
