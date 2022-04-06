// Week 04
#include <stdio.h>

void initialize_array(int* arr, int size_of_array) {
  for (int i = 0; i < size_of_array; i++) {
    *(arr + i) = i + 1;
  }
}

void print_array(int* arr, int size_of_array) {
  for (int i = 0; i < size_of_array; i++) {
    printf("%d ", arr[i]);
  }
}

int main(void) {
  int n[10];

  initialize_array(n, 10);

  print_array(n, 10);

  return 0;
}