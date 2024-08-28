#include "utils.c"
#include <stdio.h>
#include <stdlib.h>
// en el manejo de memoria, el S.O. intercambia todo el tiempo a diferentes
// direcciones.
// ej: en una matriz, puedo cambiar filas.
int main(int argc, char *argv[]) {

  int **a;
  a = (int **)malloc(3 * sizeof(int *));
  for (int i = 0; i < 3; i++) {
    a[i] = (int *)malloc(4 * sizeof(int));
  }
  int initial_values[3][4] = {{5, 9, 7, 2}, {8, 11, 13, 14}, {4, 1, 6, 5}};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      a[i][j] = initial_values[i][j];
    }
  }
  print_matrix(a, 3, 4);
  printf("\n");
  swap_row((void**)a, 0, 1);
  print_matrix(a, 3, 4);
  printf("\n");
  print_inferior_triangular_matrix(a, 3);
  int **b = create_inferior_triangular_matrix(3);
  print_matrix(b, 3, 3);
  print_inferior_triangular_matrix(b, 3);
  return 0;
}
