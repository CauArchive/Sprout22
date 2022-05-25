#include <stdio.h>

void hanoi(int n, int start, int to, int bypass) {
  if (n == 1)
    printf("%d %d\n", start, to);
  else {
    hanoi(n - 1, start, bypass, to);
    printf("%d %d\n", start, to);
    hanoi(n - 1, bypass, to, start);
  }
}
int main() {
  int num;
  scanf("%d", &num);
  printf("%d\n", num);
  hanoi(num, 1, 3, 2);
}