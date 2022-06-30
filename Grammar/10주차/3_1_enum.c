#include <stdio.h>

enum DayOfWeek {  // 열거형 정의
  Sunday = 0,     // 초깃값 할당
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday
};

int main() {
  enum DayOfWeek week;  // 열거형 변수 선언

  week = Tuesday;  // 열거형 값 할당

  switch (week) {
    case Sunday:
      printf("Sunday\n");
      break;
    case Monday:
      printf("Monday\n");
      break;
    case Tuesday:
      printf("Tuesday\n");
      break;
    case Wednesday:
      printf("Wednesday\n");
      break;
    case Thursday:
      printf("Thursday\n");
      break;
    case Friday:
      printf("Friday\n");
      break;
    case Saturday:
      printf("Saturday\n");
      break;
    default:
      printf("Unknown\n");
      break;
  }

  printf("%d\n", week);  // 2: Tuesday의 값 출력

  return 0;
}