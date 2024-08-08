#include <stdio.h>
#define SIZE 100
struct informacion_celda {

  char nombre[SIZE];
  unsigned int identificador;
  float calidad_senal;
  struct informacion_operador *ptr_operador;
};

struct informacion_operador {

  char nombre[SIZE];
  unsigned int prioridad;
  unsigned int ultima_comprob;
};

struct pack3 {
  int a;
};
struct pack2 {
  int b;
  struct pack3 *next;
};
struct pack1 {
  int c;
  struct pack2 *next;
};

struct pack1 data1, *data_ptr;
struct pack2 data2;
struct pack3 data3;

int main(int argc, char *argv[]) {

  struct informacion_celda c;
  printf("%p", &c.ptr_operador);
  /* testing expressions
  data1.c;
  data_ptr->c;
  data_ptr.c;
  data1.next->b;
  data_ptr->next->b;
  data_ptr.next.b;
  data_ptr->next.b;
  (*(data_ptr->next)).b;
  data1.next->next->a;
  data_ptr->next->next.a;
  data_ptr->next->next->a;
  data_ptr->next->a;
  data_ptr->next->next->b;*/
  return 0;
}
