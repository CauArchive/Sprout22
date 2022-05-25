#include <stdio.h>

/*
/ 참고자료:
https://www.google.com/url?sa=i&url=https%3A%2F%2Fm.blog.naver.com%2FPostView.naver%3FisHttpsRedirect%3Dtrue%26blogId%3Dkyuhgmi%26logNo%3D220073551241&psig=AOvVaw3RUjtnV4d0JPwwF_13ChHd&ust=1651681791347000&source=images&cd=vfe&ved=0CAwQjRxqFwoTCJjd46Xgw_cCFQAAAAAdAAAAABAD
/ 아스키코드
/ 컴퓨터는 문자를 어떻게 인식하고 출력할까?
*/

int main(void) {
  char a = '1';
  // a = 49

  printf("%c\n", a);
  // 예상되는 결과: 1
  printf("%d\n", a);
  // 예상되는 결과: 49

  int itoc = 49;

  printf("%d\n", itoc);
  // 예상되는 결과: 65
  printf("%c\n", itoc);
  // 예상되는 결과: A

  return 0;
}