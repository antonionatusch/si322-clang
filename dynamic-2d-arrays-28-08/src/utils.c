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

void print_inferior_triangular_matrix(int **a, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i < j)
        break;
      else
        printf("%d, ", a[i][j]);
    }
    printf("\n");
  }
}

void print_superior_triangular_matrix(int **a, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j < i)
        printf("none, ");
      else
        printf("%d, ", a[i][j]);
    }
    printf("\n");
  }
}

int **create_inferior_triangular_matrix(int n) {
  int **a = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc((i + 1) * sizeof(int));
  }
  int valor = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      a[i][j] = valor++;
    }
  }
  return a;
}
int **create_superior_triangular_matrix(int n) {
  int **a = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc((n - i) * sizeof(int));
  }
  int valor = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j >= i; --j) {
      a[i][j] = valor++;
    }
  }
  return a;
}
void swap_columns(int **arr, int first_col, int second_col, int rows) {
  int tmp;
  for (int i = 0; i < rows; i++) {
    tmp = arr[i][first_col];
    arr[i][first_col] = arr[i][second_col];
    arr[i][second_col] = tmp;
  }
}
