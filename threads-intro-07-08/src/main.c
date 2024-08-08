#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_THREADS 10

pthread_t main_table[MAX_THREADS];

typedef struct {
  int id;
  char *str;
} thr_param_table; // est. que guarda los parametros para asignarlos al main
                   // table.

thr_param_table params[MAX_THREADS];
// demo de hilos

/*
 *  crear una tabla para los params
 *  ya que pasarán por referencia.
 *  si solo tenemos una variable para los parametros, cambiamos todo lo que
 * habiamos pasado.
 */
void thr_function(void *p) {

  thr_param_table *data;
  data = (thr_param_table *)p;
  printf("%s\n", data->str);
  printf("%d\n", data->id);
  pthread_exit(&data->id); // al devolver direcciones de memoria, debo pasar por
                           // parametro aquello.
}

int main(int argc, char *argv[]) {
  int *res;
  void *r;
  // por valor

  int my_var = 20;
  int new_var = my_var; // inicializacion copiando el valor.
  printf("%d valor myvar\n", my_var);
  printf("%d valor newvar \n", new_var);

  int another_var = 15;
  printf("%d valor actual de anothervar \n", another_var);
  int *my_pointer =
      &another_var; // al tener la direccion de memoria, puedo cambiar el valor
                    // directamente desde esa referencia.
  *my_pointer = 20;

  // demo de threads
  printf("%d valor nuevo de anothervar por el cambio a traves de referencia \n",
         another_var);

  printf("creando threads\n");

  for (int i = 0; i < MAX_THREADS; i++) {
    params[i].str = "Hola, soy el thread con el id";
    params[i].id = i;
    pthread_create(&main_table[i], NULL, (void *)thr_function,
                   (void *)&params[i]);
  }

  printf("esperando a que terminen los hilos...\n");

  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(main_table[i], &r);
    res = (int *)r;
    printf("El thread %d dio el valor %d\n", i, *res);
  }
  return 0;
}
