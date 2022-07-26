#include <math.h>
#include <stdio.h>

/**
 * @brief how to solve algorithm prob
 * @ref https://www.acmicpc.net/problem/4344
 * @return int
 */

int main(void) {
  int num_of_result;
  scanf("%d", &num_of_result);

  // variable for storing current iteration
  int num_of_input;

  int input_buffer[1001];
  for (int i = 0; i < num_of_result; i++) {
    int sum = 0;
    scanf("%d", &num_of_input);

    // sum all inputs;
    for (int j = 0; j < num_of_input; j++) {
      scanf("%d", &input_buffer[j]);
      sum += input_buffer[j];
    }

    // calculate average
    float avg = (float)sum / num_of_input;

    // count element which is over avg
    int over_avg_counter = 0;
    for (int j = 0; j < num_of_input; j++) {
      if (avg < input_buffer[j]) over_avg_counter++;
    }

    // print result;
    printf("%.3f%%\n", ((float)over_avg_counter / num_of_input) * 100);
  }

  return 0;
}