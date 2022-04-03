// Week 04
#include <stdio.h>

void initialize_array(int* arr) {
  // do something
}

void print_array(int* arr) {
  // do something
}

int main(void) {
  int n[100];

  for (int i = 0; i < 100; i++) {
    n[i] = i + 1;
  }

  for (int i = 0; i < 100; i = i + 1) {
    printf("%d ", n[i]);
  }

  return 0;
}