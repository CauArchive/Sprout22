#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Person {
  int id;
  int score;
  int rank;
} Person;

void swap(Person* a, Person* b) {
  Person temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort_by_id(Person* arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      // 오름차순
      if (arr[j].id > arr[j + 1].id) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

void bubble_sort_by_score(Person* arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      // 오름차순
      if (arr[j].score > arr[j + 1].score) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

void bubble_sort_by_score_desc(Person* arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      // 내림차순
      if (arr[j].score < arr[j + 1].score) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

void bubble_sort_by_rank(Person* arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j > size - i - 1; j++) {
      // 내림차순
      if (arr[j].rank > arr[j + 1].rank) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

int main() {
  Person student[100];

  for (int i = 0; i < 100; i++) {
    student[i].id = i;
    student[i].score = (rand() % 101);
    student[i].rank = i;
  }

  bubble_sort_by_score(student, 100);

  for (int i = 0; i < 100; i++) {
    printf("%d %d %d\n", student[i].id, student[i].score, student[i].rank);
  }

  return 0;
}