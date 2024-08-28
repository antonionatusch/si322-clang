#include <stdio.h>
#include <stdlib.h>
void swap_row(void **arr, int first_row, int second_row) {
  void *tmp; // aceptará la dirección de memoria de cualquier tipo de dato.
  tmp = arr[first_row];
  arr[first_row] = arr[second_row];
  arr[second_row] = tmp;
}

void print_matrix(int **matrix, int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%d, ", matrix[i][j]);
    }
    printf("\n");
  }
}

void print_inferior_triangular_matrix(int** a, int n) {
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      if (i < j) printf("0, ");
      else printf("%d, ", a[i][j]);
    }
    printf("\n");
  }
}

void print_superior_triangular_matrix(int** a, int n) {
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      if (i > j) continue;
      else printf("%d, ", a[i][j]);
    }
    printf("\n");
  }
}

int **create_inferior_triangular_matrix(int n) {
  int **a;
  a = (int **)malloc(n*sizeof(int));
  for (int i = 0; i < n; i++) {
    a[i] = (int * )malloc((i+1)*sizeof(int));
  }
  return a;
}
void swap_columns(int **arr, int first_col, int second_cold, int rows) {
  int tmp;
  for (int i = 0; i < rows, i++;) {

  }
}
