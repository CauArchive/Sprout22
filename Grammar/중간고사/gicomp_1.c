#include <stdio.h>

int main(void) {
  int idx = 0;
  int arr[1000];

  int input;
  while (1) {
    scanf("%d", &input);
    if (input == 0) {
      break;
    }
    arr[idx] = input;
    idx = idx + 1;
  }

  int positive_counter = 0;
  int negative_counter = 0;
  for (int i = 0; i < idx; i++) {
    if (arr[i] < 0) {
      // do something
      negative_counter++;
    } else {
      // do something
      positive_counter++;
    }
  }

  printf("positive count: %d\n", positive_counter);
  printf("negative count: %d\n", negative_counter);

  return 0;
}