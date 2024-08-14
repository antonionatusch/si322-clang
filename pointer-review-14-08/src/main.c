#include <stdio.h>

void FindMinAndMax(int a, int b, int *pMax, int *pMin) {

  if (a > b) {
    *pMin = b;
    *pMax = a;
  } else {
    *pMin = a;
    *pMax = b;
  }
}

int FindMaxOfThreeNumbers(int *list) {


  return max;
}

int min(int a, int b) { return a > b ? b : a; }

void swap(int *a, int *b) { // solo de esta forma es que se pueden cambiar los
                            // valores con una funcion
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(int argc, char *argv[]) {
  int a = 10, b = 15;
  int *ptrMax, *ptrMin;

  /*  printf("%d\n", a);
    printf("%d\n", b);
    swap(&a, &b);
    printf("%d\n", a);
    printf("%d\n", b);
  */

  printf("%d\n", min(a, b));

  FindMinAndMax(a, b, ptrMax, ptrMin);

  printf("%d\n", *ptrMax);
  printf("%d\n", *ptrMin);



  return 0;
}
