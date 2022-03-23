// Week 02
#include <stdio.h>

int main(void) {
  // 사용법
  int n1 = 1;
  int n2 = 2;
  int n3 = 3;
  int n4 = 4;
  int n5 = 5;

  // 가장 간단한 예제
  if (n1 > 0) {
    printf("%d is positive number\n", n1);
  } else if (n1 < 0) {
    printf("%d is negative number\n", n1);
  } else {
    printf("%d is 0\n", n1);
  }

  // 짝수 판별 예시
  if (n1 % 2 == 0) {
    printf("%d is even number\n", n1);
  } else {
    printf("%d is odd number\n", n1);
  }

  if (n2 % 2 == 0) {
    printf("%d is even number\n", n2);
  } else {
    printf("%d is odd number\n", n2);
  }

  if (n3 % 2 == 0) {
    printf("%d is even number\n", n3);
  } else {
    printf("%d is odd number\n", n3);
  }

  // ... 이하 생략

  // ======================================

  // 배열을 이용한 예제
  // 여러개의 값에 대해서 적은 코드로 처리할 수 있습니다.
  // 아래 소스코드는 이해하려 노력하지 않아도 됩니다. 나중에 저절로 이해될겁니다
  // :)
  int n[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    if (n[i] % 2 == 0) {
      printf("%d is even number\n", n1);
    } else {
      printf("%d is odd number\n", n1);
    }
  }

  return 0;
}