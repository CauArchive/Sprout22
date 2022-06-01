#include <stdio.h>

/**
 * @brief Trash Value & Type casting
 *
 * @return int
 */

int main(void) {
  int a;
  printf("%d\n", a);

  a = 0;
  printf("%d\n", a);

  // type casting
  float b = 3.1415926575;
  printf("%f\n", b);
  a = b;
  // lose value
  printf("%d\n", a);

  a = 10;
  printf("%d\n", a / 3);
  // type casting
  printf("%f\n", (float)a / 3);

  return 0;
}