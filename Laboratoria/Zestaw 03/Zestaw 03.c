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

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

const char* START_MESSAGE = "Podawaj dwie liczby: "
const char* CREATE_THREAD_ERROR_MESSAGE = "Blad tworzenia watku\n";
const char* JOIN_THREAD_ERROR_MESSAGE = "Blad dolaczania watku\n"

int a;
int b;

/**
 * Funkcja przeprowadzająca operacje dodawania z blokowaniem zmiennej podczas przeprowadzania operacji
 *
 * @param args Argumenty operacji
 */
void * addition(void *args) {
	pthread_mutex_unlock(&mutex);
    int result = (a + b);
	printf("%i + %i = %i \n", a, b, result);	
	pthread_mutex_lock(&mutex);
}

/**
 * Funkcja przeprowadzająca operacje odejmowania z blokowaniem zmiennej podczas przeprowadzania operacji
 *
 * @param args Argumenty operacji
 */
void * subtraction(void *args) {
    pthread_mutex_unlock(&mutex);
    int result = (a - b);
	printf("%i - %i = %i \n", a, b, result);
	pthread_mutex_lock(&mutex);
}

/**
 * Funkcja przeprowadzająca operacje mnożenia z blokowaniem zmiennej podczas przeprowadzania operacji
 *
 * @param args Argumenty operacji
 */
void * multiplication(void *args) {
	pthread_mutex_unlock(&mutex);
    int result = (a * b);
	printf("%i * %i = %i \n", a, b, result);
	pthread_mutex_lock(&mutex);
}

/**
 * Funkcja przeprowadzająca operacje dzielenia z blokowaniem zmiennej podczas przeprowadzania operacji
 *
 * @param args Argumenty operacji
 */
void * division(void *args) {
	pthread_mutex_unlock(&mutex);
    int result = (a / b);
	printf("%i / %i = %i \n", a, b, result);
	pthread_mutex_lock(&mutex);
}

int main() {
	pthread_t thread_addition;
	pthread_t thread_subtraction;
	pthread_t thread_multiplication;
	pthread_t thread_division;
	
	printf(START_MESSAGE);
	scanf("%d %d \n", &a, &b);

	if (pthread_create(&thread_addition, NULL, addition, NULL)) {
		printf(CREATE_THREAD_ERROR_MESSAGE);
		abort();
	}

	if (pthread_join(thread_addition, NULL)) {
		printf(JOIN_THREAD_ERROR_MESSAGE);
		exit(0);
	}

	if (pthread_create(&thread_subtraction, NULL, subtraction, NULL)) {
		printf(CREATE_THREAD_ERROR_MESSAGE);
		abort();
	}

	if (pthread_join(thread_subtraction, NULL)) {
		printf(JOIN_THREAD_ERROR_MESSAGE);
		exit(0);
	}

	if (pthread_create(&thread_multiplication, NULL, multiplication, NULL)) {
		printf(CREATE_THREAD_ERROR_MESSAGE);
		abort();
	}

	if (pthread_join(thread_multiplication, NULL)) {
		printf(JOIN_THREAD_ERROR_MESSAGE);
		exit(0);
	}

	if (pthread_create(&thread_division, NULL, division, NULL)) {
		printf(CREATE_THREAD_ERROR_MESSAGE);
		abort();
	}

	if (pthread_join(thread_division, NULL)) {
		printf(JOIN_THREAD_ERROR_MESSAGE);
		exit(0);
	}

	return 0;
}
