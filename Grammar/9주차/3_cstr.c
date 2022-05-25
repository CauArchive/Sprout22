#include <stdio.h>
#include <string.h>

int main(void) {
  char str[100] = "Hello World.";
  printf("%s\n", str);
  char *str_1 = "Hi World.";
  printf("%s\n", str_1);
  strcat(str, str_1);
  printf("%s\n", str);
  printf("==============\n");
  char *origin_str = "Hello World.";
  char *cmp_str = "Hello World.";
  if (strcmp(origin_str, cmp_str) == 0) {
    printf("%s\n", "same");
  } else {
    printf("%s\n", "different");
  }

  printf("==============\n");
  char *main_str = "Hello World.";
  char *sub_str = strstr(main_str, "World");
  printf("%s\n", sub_str);
  printf("==============\n");

  char *token;
  char nice_str[] = "Nice to meet you. How are you?";
  token = strtok(nice_str, " ");
  while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, " ");
  }
  return 0;
}