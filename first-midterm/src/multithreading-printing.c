#include <pthread.h>
#include <stdio.h>
#define MAX_THREADS 5
pthread_t threads[MAX_THREADS];

typedef struct thr_params {
  int id;
} thr_params;

void thr_creation(void *p) // p = param cualquiera
{
  thr_params *data;
  data = (thr_params *)p;
  pthread_exit(&data->id);
}

int main(int argc, char *argv[]) {
  int *res;
  int n;
  void *r;
  printf("Enter a number of threads: ");
  scanf("%d", &n);
  thr_params params[n];
  for (int i = 0; i < n; ++i) {
    params[i].id = i + 1;
    pthread_create(&threads[i], NULL, (void *)thr_creation, (void *)&params[i]);
  }
  for (int i = n - 1; i >= 0; --i) {
    pthread_join(threads[i], &r);
    res = (int *)r;
    printf("%d\n", *res);
  }
  return 0;
}
