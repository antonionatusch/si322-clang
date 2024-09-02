#include <pthread.h>
#include <stdio.h>
#define MAX_THREADS 5
pthread_t threads[MAX_THREADS];

void thr_creation(void *p);  // p = param cualquiera

int main(int argc, char *argv[]) {

  printf("Hello World!\n");
  return 0;
}
