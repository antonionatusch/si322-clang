#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_THREADS 5
pthread_t threads[MAX_THREADS];

typedef struct thr_params {
  int id;
} thr_params;

void *thr_creation(void *p) {
  int *id = (int *)p;
  pthread_exit(id); // Sale del hilo devolviendo el puntero al ID
}
int main(int argc, char *argv[]) {
  int *res;
  int n;
  void *r;
  printf("Enter a number of threads: ");
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int *id = malloc(sizeof(int)); // Asigna memoria para cada ID
    *id = i + 1;
    pthread_create(&threads[i], NULL, thr_creation, id);
  }

  for (int i = n - 1; i >= 0; --i) {
    pthread_join(threads[i], &r);
    res = (int *)r;
    printf("%d\n", *res);
    free(res); // Libera la memoria después de usar el ID
  }

  return 0;
}
