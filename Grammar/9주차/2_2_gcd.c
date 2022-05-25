#include <stdio.h>

int gcd(int f, int s) {
  if (s == 0) return f;
  return gcd(s, f % s);
}

int main(void) {
  int N1, N2;
  printf("Enter two numbers: ");
  scanf("%d %d", &N1, &N2);
  int result = gcd(N1, N2);
  printf("GCD of %d and %d is %d\n", N1, N2, result);
  return 0;
}