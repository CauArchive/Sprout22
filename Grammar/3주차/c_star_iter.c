// Week 02
#include <stdio.h>

// 반복문을 이용해서
// 콘솔창에 별 찍어보기
// *
// **
// ***
// ****
// https://www.acmicpc.net/problem/2438
// scanf까지

// Hint: for(반복문 시작조건; 종료조건; 한 번의 반복 이후
// 다음 반복문이 실행되기 전 실행하고 싶은 코드)

int main() {
  int n = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}