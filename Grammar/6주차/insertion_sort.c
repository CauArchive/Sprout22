#include <stdio.h>

/*
/ 참고자료: https://visualgo.net/en/sorting
/ 가장 기본적인 정렬 알고리즘
/ 인덱스 -1 부터 시작하여 처음 인덱스까지 하나씩 내려가면서
/ 현재 인덱스 값과 비교한다
*/

void insertion_sort(int* arr, int size) {
  // 모든 배열을 순회한다
  for (int i = 1; i < size; i++) {
    // 현재 값을 임시변수에 저장한다
    int tmp = arr[i];
    // 현재 값 아래의 값들을 순회한다
    int j = i - 1;
    // 현재 값이 앞에 있는 값들보다 작다면
    // 한 칸씩 오른쪽으로 이동하기
    while (j >= 0 && arr[j] > tmp) {
      arr[j + 1] = arr[j];
      j--;
    }
    // 그러다가 값이 더 이상 현재 값보다 작지 않으면
    // 현재 값을 그 자리에 저장한다
    arr[j + 1] = tmp;
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
  insertion_sort(arr, 10);
  print_arr(arr, 10);

  return 0;
}