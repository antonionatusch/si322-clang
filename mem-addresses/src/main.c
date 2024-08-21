#include "pt2.c"
#include <stdbool.h>
#include <stdio.h>
int sum(int *ptr_array, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++)
    sum += ptr_array[i];

  return sum;
}

// usando punteros, dado un numero, pillarlo en el vector

bool IsFound(int *array_ptr, int target, int size) {

  for (int i = 0; i < size; i++) {
    if (target == array_ptr[i])
      return true;
  }

  return false;
}
// usando punteros, encontrar el minimo y maximo de un arreglo.

void MaxAndMin(int *arr_ptr, int *max_ptr, int *min_ptr, int size) {
  *min_ptr = arr_ptr[0];
  *max_ptr = arr_ptr[0];

  for (int i = 0; i < size; i++) {
    if (*max_ptr > arr_ptr[i])
      *max_ptr = arr_ptr[i];
    if (*min_ptr < arr_ptr[i])
      *min_ptr = arr_ptr[i];
  }
}

// verificar si el vector está ordenado o no

bool IsSorted(int *arr_ptr, int size) {

  for (int i = 1; i < size; i++) {
    if (arr_ptr[i - 1] > arr_ptr[i]) {
      return false;
    }
  }
  return true;
}

void demo_pt1() {

  int max, min;
  int a[3] = {10, 20,
              30}; // en cuanto a los punteros, el nombre de un arreglo apunta a
                   // la dirección de memoria del primer elemento.
  int b[10] = {10, 80, 90, 40, 50, 88, 2, 78, 10, 42};
  int a_size = sizeof(a) / sizeof(a[0]);
  int b_size = sizeof(b) / sizeof(b[0]);
  //  int *a_ptr = a;
  printf("sum of a: %d \n", sum(a, a_size));
  printf("is 11 in the array? %b \n", IsFound(a, 11, a_size));
  printf("is 10 in the array? %b \n", IsFound(a, 10, a_size));
  MaxAndMin(a, &max, &min, a_size);
  printf("min of array: %d, max of array %d\n", max, min);
  MaxAndMin(b, &max, &min, b_size);
  printf("min of array: %d, max of array %d\n", max, min);
  printf("is a sorted? %b\n", IsSorted(a, a_size));
  printf("is b sorted? %b\n", IsSorted(b, b_size));
}

void arr_print(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

int main(int argc, char *argv[]) {
  int initial_array[2] = {10, 20};
  int val_to_ins = 30;
  int *new_array = NULL;
  new_array = generic_insert(initial_array, sizeof(initial_array),  2 *  sizeof(initial_array[0]),
                                  &val_to_ins, sizeof(val_to_ins));
  printf("old arr\n");
  arr_print(initial_array, sizeof(initial_array) / sizeof(initial_array[0]));
  printf("new arr\n");
  arr_print(new_array, (sizeof(initial_array) / sizeof(initial_array[0])) + 1);
  return 0;
}
