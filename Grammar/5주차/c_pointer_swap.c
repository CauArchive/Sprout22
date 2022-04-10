#include <stdio.h>

// https://d.pr/i/xfWOGd

void copy_swap(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}

void real_swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void print_variable(int a, int b) { printf("%d %d\n", a, b); }

int main(void) {
  // we should swap those two variables
  int a = 2, b = 5;
  printf("Before Copy Swap Function Exec\n");
  print_variable(a, b);

  printf("After Copy Swap Function Exec\n");
  copy_swap(a, b);
  print_variable(a, b);

  // re-initialize two variables(to prove pointer swap)
  a = 2, b = 5;
  printf("Before Real Swap Function Exec\n");
  print_variable(a, b);

  printf("After Real Swap Function Exec\n");
  real_swap(&a, &b);
  print_variable(a, b);
}