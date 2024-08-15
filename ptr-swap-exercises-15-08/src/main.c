#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapInts(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void swapIntsNoThird1(int *a, int *b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

void swapIntsNoThird2(int *a, int *b) {

  *a = *a * *b;
  *b = *a / *b;
  *a = *a / *b;
}

void genericSwap(void *a, void *b, size_t s) {
  void *tmp = malloc(s);
  memcpy(tmp, a, s);
  memcpy(a, b, s);
  memcpy(b, tmp, s);
  free(tmp); // liberar espacio de memoria.
}

int main(int argc, char *argv[]) {
  int first_num = 5, second_num = 2;
  float third_num = 2.5, fourth_num = 9.0;

  printf("first b4 swap: %d, second b4 swap: %d\n", first_num, second_num);
  swapInts(&first_num, &second_num);
  printf("first after swap: %d, second after swap: %d\n", first_num,
         second_num);
  swapIntsNoThird1(&first_num, &second_num);
  printf("first after swap through addition and subtraction: %d, second after "
         "swap: %d\n",
         first_num, second_num);
  swapIntsNoThird2(&first_num, &second_num);
  printf("first after swap through multiplication and division: %d, second "
         "after swap: %d\n",
         first_num, second_num);
  printf("first b4 genericSwap: %d, second: %d\n", first_num, second_num);
  genericSwap(&first_num, &second_num, sizeof(first_num));
  printf("first after genericSwap: %d, second: %d\n", first_num, second_num);
  printf("with floats\n");
  printf("first b4 genericSwap: %f, second: %f\n", third_num, fourth_num);
  genericSwap(&third_num, &fourth_num, sizeof(third_num));
  printf("first after genericSwap: %f, second: %f\n", third_num, fourth_num);

  return 0;
}
