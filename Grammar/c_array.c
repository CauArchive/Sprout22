// Week 02
#include <stdio.h>

int main(void) {
  int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;
  printf("%d %d %d %d %d\n", n1, n2, n3, n4, n5);
  // 그런데 만약 변수가 100개가 넘어가면 관리에 어려움이 있습니다.

  int n[5] = {1, 2, 3, 4, 5};
  printf("%d %d %d %d %d\n", n[0], n[1], n[2], n[3], n[4]);

  return 0;
}