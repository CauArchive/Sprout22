#include <stdio.h>

/**
 * @brief count digits of a number
 * @ref https://www.acmicpc.net/problem/4673
 * @param n
 * @return int
 */

int count_digits(int n) {
  int count = 0;
  int i;

  for (i = 1; i <= n; i *= 10) {
    count++;
  }

  return count;
}

int sum_digits_for(int n) {
  int sum = 0;

  for (; n > 0; n /= 10) {
    sum += n % 10;
  }

  return sum;
}

int sum_digits_while(int n) {
  int sum = 0;

  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main(void) {
  int n;
  scanf("%d", &n);

  printf("%d\n", sum_digits_for(n));
  printf("%d\n", sum_digits_while(n));

  return 0;
}