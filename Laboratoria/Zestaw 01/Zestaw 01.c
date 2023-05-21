#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	// Zadanie 1
	printf("Proces potomny %i \n", getpid());
	const char* path1 = "/home/tom/Desktop/P1.txt";
	const char* path2 = "/home/tom/Desktop/P2.txt";
	
	// Potomek 1
	if(fork()) {
		printf("1.Proces %i, potomek %i \n", getpid(), getppid());
		int file1 = open("/home/tom/Desktop/P1.txt", O_WRONLY|O_CREAT|O_RDONLY, 0777);
		int file2 = open("/home/tom/Desktop/P2.txt", O_WRONLY|O_CREAT|O_RDONLY, 0777);
		if(fork()) {
			printf("1.Proces %i, potomek %i \n", getpid(), getppid());
			char buff1[20];
			read(stdin, buff1, 20);
			write(file1, buff1, 20);
			
			if(fork()) {
				printf("1.Proces %i, potomek %i \n", getpid(), getppid());
				int dup_file1 = dup(file1);
				char buff2[20];
				read(dup_file1, buff2, 20);
				
				exit(0);
			}
		exit(0);
		}
	close(file1);
	close(file2);
	
	exit(0);
	}

	// Potomek 2
	if(fork()) {
		printf("2.Proces %i, potomek %i \n", getpid(), getppid());
		int file1 = open("/home/tom/Desktop/P1.txt", O_RDONLY);
		int file2 = open("/home/tom/Desktop/P2.txt", O_WRONLY);
		
		char buff3[100];
		read(file1, buff3, 100);
		write(file2, buff3, 100);
		
		close(file1);
		close(file2); 
		
		if(fork()) {
			printf("2.Proces %i, potomek %i \n", getpid(), getppid());
			int file2 = open("/home/tom/Desktop/P2.txt", O_RDONLY);
			char buff4[100];
			lseek(file2, 10, SEEK_CUR);
				
			int i = 0;
			while(buff4[i] != '\0') {
				buff4[i]=' ';
				i++;
			}
      
			read(file2, buff4, 100);
			printf("Tresc pliku przesunieta o 10 bajtow w prawo: %s \n", buff3);
			
			close(file2);
			
			if(fork()) {
				printf("2.Proces %i, potomek %i \n", getpid(), getppid());
				
				if(access(path2, 0774) != 0) {
					chmod(path2, 0774);
				}
        
				exit(0);
			}
		exit(0);
		}
	exit(0);
	}
	
	// Potomek 3
	if(!fork()) {
		printf("3.Proces %i, potomek %i \n", getpid(), getppid());
		
		if(!fork()) {
			printf("Zombie nr.1, proces %i, potomek %i \n", getpid(), getppid());
			exit(0);
		}
		
		if(!fork()) {
			printf("Zombie nr.2, proces %i, potomek %i \n", getpid(), getppid());
			exit(0);
		}
		sleep(10);
		wait(0);
	}
	wait(0);
	
	//Zadanie 2
	if(fork()) {
		printf("Sciezka biezacego katalogu: %i \n", execlp("pwd", "pwd", NULL));	
		exit(0);
	}
	
	if(fork()) {
		printf("Lista procesow: %i \n", execlp("ps", "ps", NULL));	
		exit(0);
	}
	
	return 0;
}
