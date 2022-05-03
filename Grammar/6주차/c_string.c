#include <stdio.h>
#include <string.h>

/*
/ 문자열 입력받기
/
*/

int main(void) {
  char str_arr[10];
  scanf("%s", str_arr);
  printf("%s\n", str_arr);

  char* str_ptr = "hello world";
  for (int i = 0; i < strlen(str_ptr); i++) {
    printf("%c", str_ptr[i]);
  }
  printf("\n");

  // 아래가 가능할까요?
  str_ptr[0] = 'H';
  printf("%s\n", str_ptr);

  return 0;
}