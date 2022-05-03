#include <stdio.h>

/*
/ 참고자료: https://visualgo.net/en/sorting
/ 가장 기본적인 정렬 알고리즘
/ 거품이 올라오는 것 처럼 보여서 버블정렬이라고 부름
/ 옷을 검색하거나, 지도에서 원하는 것만 필터링할때 사용
*/

void bubble_sort(int* arr, int size) {
  // 모든 배열을 순회한다
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      // 만약 앞의 값이 뒤의 값보다 크다면
      if (arr[j] > arr[j + 1]) {
        // 앞의 값과 뒤의 값을 바꿔준다
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// 역으로 정렬하는 방법
void bubble_sort_reverse(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void print_arr(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(void) {
  int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  print_arr(arr, 10);
  bubble_sort(arr, 10);
  print_arr(arr, 10);

  return 0;
}