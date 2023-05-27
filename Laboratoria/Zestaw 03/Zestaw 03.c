#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

// Zainicjalizowanie mutexa jako PTHREAD_MUTEX_INITIALIZER
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Utworzenie globalnych zmiennych do obliczeń - a oraz b
int a;
int b;

// Funkcja dodająca dwie liczby przy użyciu wątków
void * addition(void *args) {
    // Odblokowanie mutexa
	pthread_mutex_unlock(&mutex);
	// Zainicjalizowanie result jako wynik dodawania a i b
    int result = a + b;
    // Wyświetlenie wyniku dodawania
	printf("Addition result:        %i + %i = %i \n", a, b, result);	
	// Zamknięcie mutexa
	pthread_mutex_lock(&mutex);
}

// Funkcja odejmująca dwie liczby przy użyciu wątków
void * subtraction(void *args) {
    // Odblokowanie mutexa
    pthread_mutex_unlock(&mutex);
    // Zainicjalizowanie result jako wynik odejmowania a i b
    int result = a - b;
    // Wyświetlenie wyniku odejmowania
	printf("Subtraction result:     %i - %i = %i \n", a, b, result);
	// Zamknięcie mutexa
	pthread_mutex_lock(&mutex);
}

// Funkcja mnożąca dwie liczby przy użyciu wątków
void * multiplication(void *args) {
    // Odblokowanie mutexa
	pthread_mutex_unlock(&mutex);
	// Zainicjalizowanie result jako wynik mnożenia a i b
    int result = a * b;
    // Wyświetlenie wyniku mnożenia
	printf("Multiplication result:  %i * %i = %i \n", a, b, result);
	// Zamknięcie mutexa
	pthread_mutex_lock(&mutex);
}

// Funkcja dzieląca dwie liczby przy użyciu wątków
void * division(void *args) {
    // Odblokowanie mutexa
	pthread_mutex_unlock(&mutex);
	// Zainicjalizowanie result jako wynik dzielenia a i b
    int result = a / b;
    // Wyświetlenie wyniku dzielenia
	printf("Division result:        %i / %i = %i \n", a, b, result);
	// Zamknięcie mutexa
	pthread_mutex_lock(&mutex);
}

// Main
int main() {
    // Utworzenie wątków
	pthread_t thread_addition;              // Wątek dodawania
	pthread_t thread_subtraction;           // Wątek odejmowania
	pthread_t thread_multiplication;        // Wątek mnożenia
	pthread_t thread_division;              // Wątek dzielenia
	
	// Wyświetlenie informacji o podaniu parametrów na standardowym wejściu
	printf("Enter two numbers: ");
	// Przyjęcie dwóch liczb - a i b na standardowym wejściu
	scanf("%d %d \n", &a, &b);
	
	// Utworzenie wątku dodawania
	if(pthread_create(&thread_addition, NULL, addition, NULL)) {
	    // Informacja o błędzie podczas tworzenia wątku
		printf("Creating Thread Error!\n");
		// Przerwanie tworzenia wątku
		abort();
	}
	
	// Dołączanie wątku dodawania
	if(pthread_join(thread_addition, NULL)) {
	    // Informacja o błędzie podczas dołączania wątku
		printf("Attaching Thread Error!\n");
		// Przerwanie dołączania wątku
		exit(0);
	}
	
	// Utworzenie wątku odejmowania
	if(pthread_create(&thread_subtraction, NULL, subtraction, NULL)) {
	    // Informacja o błędzie podczas tworzenia wątku
		printf("Creating Thread Error!\n");
		// Przerwanie tworzenia wątku
		abort();
	}
	
	// Dołączanie wątku odejmowania
	if(pthread_join(thread_subtraction, NULL)) {
		printf("Attaching Thread Error!\n");
		// Przerwanie dołączania wątku
		exit(0);
	}
	
	// Utworzenie wątku mnożenia
	if(pthread_create(&thread_multiplication, NULL, multiplication, NULL)) {
	    // Informacja o błędzie podczas tworzenia wątku
		printf("Creating Thread Error!\n");
		// Przerwanie tworzenia wątku
		abort();
	}
	
	// Dołączanie wątku mnożenia
	if(pthread_join(thread_multiplication, NULL)) {
		printf("Attaching Thread Error!\n");
		// Przerwanie dołączania wątku
		exit(0);
	}
	
	// Utworzenie wątku dzielenia
	if(pthread_create(&thread_division, NULL, division, NULL)) {
	    // Informacja o błędzie podczas tworzenia wątku
		printf("Creating Thread Error!\n");
		// Przerwanie tworzenia wątku
		abort();
	}
	
	// Dołączanie wątku dzielenia
	if(pthread_join(thread_division, NULL)) {
		printf("Attaching Thread Error!\n");
		// Przerwanie dołączania wątku
		exit(0);
	}
	
	return 0;
}
