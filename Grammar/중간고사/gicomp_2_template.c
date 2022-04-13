#include <stdio.h>

// year: 2014, month: 7, day: 4
int checkDate(int year, int month, int day) {
  if (year <= 0) return 0;
  if (month <= 0) return 0;
  return 1;
}

// month  1  2  3  4  5  6  7  8  9  10  11  12
// day    31 28 31 30 31 30 31 31 30 31  30  31

// Input Example: 20140704

int main() {
  int date, year, month, day;

  printf("Input the date (20140704) : ");
  scanf("%d", &date);

  year = date / 10000;
  month = (date - (year * 10000)) / 100;
  day = date % 100;

  printf("%d %d %d", year, month, day);

  int result = checkDate(year, month, day);
  if (result) {
    printf("Right Input");
  } else {
    printf("Wrong Input");
  }

  return 0;
}