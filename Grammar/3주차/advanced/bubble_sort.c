#include <stdio.h>

// 아래 링크를 들어가면 시각적으로 볼 수 있습니다
// https://visualgo.net/en/sorting
// 배열에 담긴 숫자를 순서에 맞게 정렬하는 예제
int main() {
  int arr[] = {5, 4, 3, 10, 9};

  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}