#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Person {
  int id;
  int score;
  int rank;
} Person;

int main() {
  Person* student = (Person*)malloc(sizeof(Person));

  student->id = 1;
  student->score = 100;
  student->rank = 1;

  printf("id: %d score: %d rank: %d\n", student->id, student->score,
         student->rank);

  free(student);

  int num_of_student;
  scanf("%d", &num_of_student);

  Person* students = (Person*)malloc(sizeof(Person) * num_of_student);
  // Person students[100];

  for (int i = 0; i < num_of_student; i++) {
    students[i].id = i + 1;
    students[i].score = rand() % 100;
    students[i].rank = i + 1;
  }

  for (int i = 0; i < num_of_student; i++) {
    printf("id: %d score: %d rank: %d\n", students[i].id, students[i].score,
           students[i].rank);
  }

  free(students);

  return 0;
}