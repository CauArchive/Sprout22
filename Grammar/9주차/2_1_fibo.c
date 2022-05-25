#include <stdio.h>

/**
 * @brief 피보나치 함수 구하기
 * @ref
 * https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=archslave&logNo=221037103011
 * @param n
 * @return int
 */

int fibo(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fibo(n - 1) + fibo(n - 2);
}

int main(void) {
  int n;
  scanf("%d", &n);
  printf("%d\n", fibo(n));
  return 0;
}