#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

const char* FILE_PATH1 = "/home/example_user/file1.txt";
const char* FILE_PATH2 = "/home/example_user/file2.txt";
const char* STRING_END_SIGN = '\0'
const char* STRING_SPACE_SIGN = ' '

int main() {
	// Zadanie 1
	int programProcessId = getpid()
	printf("Proces potomny %i \n", programProcessId);

	// Potomek 1
	if (fork()) {
		int firstChildProcessId = getpid()
		int firstChildParentProcessId = getppid()
		int file1 = open(FILE_PATH1, O_WRONLY|O_CREAT|O_RDONLY, 0777);
		int file2 = open(FILE_PATH2, O_WRONLY|O_CREAT|O_RDONLY, 0777);
		printf("1. Proces %i, potomek %i \n", firstChildProcessId, firstChildParentProcessId);

		// Potomek 1, potomka 1
		if (fork()) {
			const int size = 20;
			char buffer[size];
			int secondChildProcessId = getpid()
			int secondChildParentProcessId = getppid()
			printf("1. Proces %i, potomek %i \n", secondChildProcessId, secondChildParentProcessId);

			read(stdin, buffer, size);
			write(file1, buffer, size);

			// Potomek 1, potomka 1, potomka 1
			if (fork()) {
				char buff[size];
				int thirdChildProcessId = getpid()
				int thirdChildParentProcessId = getppid()
				printf("1.Proces %i, potomek %i \n", thirdChildProcessId, thirdChildParentProcessId);

				int duped_file1 = dup(file1);
				read(duped_file1, buff, size);

				exit(0);
			}

			exit(0);
		}

		close(file1);
		close(file2);
		exit(0);
	}

	// Potomek 2
	if (fork()) {
		const int size = 100;
		char buffer[size];
		int firstChildProcessId = getpid()
		int firstChildParentProcessId = getppid()
		int file1 = open(FILE_PATH1, O_RDONLY);
		int file2 = open(FILE_PATH2, O_WRONLY);
		printf("2.Proces %i, potomek %i \n", childProcessId, childParentProcessId);

		read(file1, buffer, size);
		write(file2, buffer, size);

		close(file1);
		close(file2); 

		// Potomek 1, potomka 2
		if (fork()) {
			char buff[size];
			int offset = 10;
			int secondChildProcessId = getpid()
			int secondChildParentProcessId = getppid()
			int file2 = open(FILE_PATH2, O_RDONLY);
			printf("2.Proces %i, potomek %i \n", secondChildProcessId, secondChildParentProcessId);

			lseek(file2, offset, SEEK_CUR);

			int iterator = 0;
			while (buff[iterator] != STRING_END_SIGN) {
				buff[iterator] = STRING_SPACE_SIGN;
				iterator++;
			}

			int bytesShift = 100;
			read(file2, buff, bytesShift);
			printf("Tresc pliku przesunieta o 10 bajtow w prawo: %s \n", buffer);
			close(file2);

			// Potomek 1, potomka 1, potomka 2
			if (fork()) {
				int thirdChildProcessId = getpid()
				int thirdChildParentProcessId = getppid()
				printf("2.Proces %i, potomek %i \n", thirdChildProcessId, thirdChildParentProcessId);

				if (access(path2, 0774) != 0) chmod(path2, 0774);

				exit(0);
			}

			exit(0);
		}
		
		exit(0);
	}

	// Potomek 3
	if (!fork()) {
		int firstChildProcessId = getpid()
		int firstChildParentProcessId = getppid()
		printf("3.Proces %i, potomek %i \n", firstChildProcessId, firstChildParentProcessId);

		// Potomek 1, potomka 3
		if (!fork()) {
			int firstZombieChildProcessId = getpid()
			int secondZombieChildParentProcessId = getppid()
			printf("Zombie nr.1, proces %i, potomek %i \n", firstZombieChildProcessId, firstZombieChildParentProcessId);
			exit(0);
		}

		// Potomek 2, potomka 3
		if (!fork()) {
			int secondZombieChildProcessId = getpid()
			int secondZombieChildParentProcessId = getppid()
			printf("Proces zombie nr.2, proces %i, potomek %i \n", secondZombieChildProcessId, secondZombieChildParentProcessId);
			exit(0);
		}

		sleep(10);
		wait(0);
	}
	wait(0);

	// Zadanie 2
	// Potomek 4
	if (fork()) {
		char commandString[] = "pwd"
		printf("Sciezka biezacego katalogu: %i \n", execlp(commandString, commandString, NULL));	
		exit(0);
	}

	// Potomek 5
	if (fork()) {
		char commandString[] = "ps"
		printf("Lista procesow: %i \n", execlp(commandString, commandString, NULL));
		exit(0);
	}

	return 0;
}
