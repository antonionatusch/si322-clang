#include <stdio.h>

int foo() { return 30; }

int main(int argc, char *argv[]) {

  int (*funcptr[])() = {foo, main};
  printf("%p\n", funcptr[0]);
  printf("%p\n", funcptr[1]);

  int *ptr;
  int x = 10;

  ptr = &x;
  printf("%d\n", x);
  printf("%d\n", &x);
  printf("%d\n", *ptr);

  return 0;
}
