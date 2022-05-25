#include <stdio.h>
#include <stdlib.h>

int max_score(int* scores, int length) {
  int max = scores[0];
  for (int i = 1; i < length; i++) {
    if (max < scores[i]) {
      max = scores[i];
    }
  }
  return max;
}

int sum_scores(int* scores, int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += scores[i];
  }
  return sum;
}

int main(void) {
  int num;
  scanf("%d", &num);

  int* scores = (int*)malloc(sizeof(int) * num);
  for (int i = 0; i < num; i++) {
    scanf("%d", &scores[i]);
  }

  int max = max_score(scores, num);
  int sum = sum_scores(scores, num);

  printf("%.2f\n", (float)sum / (max * num) * 100);

  return 0;
}