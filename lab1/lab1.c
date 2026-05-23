#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  while (1) {

    char *line = NULL;
    size_t len = 0;
    printf("Please enter some text: ");
    ssize_t num_char = getline(&line, &len, stdin);
    if (num_char == -1 || num_char == 1) {
      free(line);
      perror("getline failed");
      break;
    }
    char *saveptr;
    char *tokenize = strtok_r(line, " \n", &saveptr);
    printf("Tokens:\n");
    while (tokenize != NULL) {
      printf("\t%s\n", tokenize);
      tokenize = strtok_r(NULL, " \n", &saveptr);
    }

    free(line);
  }
  return 0;
}
