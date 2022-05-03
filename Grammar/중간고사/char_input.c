#include <stdio.h>
#include <stdlib.h>

int length(char* string) {
  int counter = 0;
  while (string[counter] != '\0') {
    counter++;
  }
  return counter;
}

int main(void) {
  char str[100];
  scanf("%s", str);

  int up_counter = 0;
  int low_counter = 0;
  for (int i = 0; i < length(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      low_counter++;
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      up_counter++;
    }
  }

  printf("%d %d", up_counter, low_counter);
  return 0;
}