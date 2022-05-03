#include <stdio.h>

/*
/ 참고자료: https://visualgo.net/en/sorting
/ 가장 기본적인 정렬 알고리즘
/ 한번 배열을 순회하면서 가장 작은 값을 찾아서 시작점으로 이동
*/

void selection_sort(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    // 현재 index를 가장 작은 index라고 가정한다
    int min_idx = i;
    // 현재 index의 바로 뒤에 있는 값부터 끝까지 순회한다
    for (int j = i + 1; j < size; j++) {
      // 만약 min_idx의 값보다 현재 인덱스의 값이 작다면
      if (arr[j] < arr[min_idx]) {
        // 최소값을 가진 index를 업데이트한다
        min_idx = j;
      }
    }
    //순회가 끝났고 가장 작은 값을 가지는 index를 찾았다
    //현재의 값과 가장 작은 index를 가지는 곳의 값을 교환한다
    int tmp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = tmp;
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
  selection_sort(arr, 10);
  print_arr(arr, 10);

  return 0;
}