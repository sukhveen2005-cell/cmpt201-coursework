#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void clear(char **a, size_t count);
int main() {
  char **lines = calloc(5, sizeof(char *));
  size_t count = 0;
  while (1) {
    char *line = NULL;
    size_t len = 0;
    printf("Enter input: ");
    getline(&line, &len, stdin);
    if (strcmp(line, "print\n") == 0) {
      for (size_t i = 0; i < count; i++) {
        printf("%s", lines[i]);
      }
      continue;
    }
    if (strcmp(line, "\n") == 0) {
      free(line);
      continue;
    }
    if (strcmp(line, "clear\n") == 0) {
      clear(lines, count);
      free(line);
      lines = calloc(5, sizeof(char *));
      count = 0;
      continue;
    }
    if (count >= 5) {
      free(lines[0]);
      for (int i = 1; i < 5; i++) {
        lines[i - 1] = lines[i];
      }
      lines[4] = line;
    } else {
      lines[count] = line;
      count++;
    }
  }
  clear(lines, count);

  return 0;
}
void clear(char **lines, size_t count) {
  for (size_t i = 0; i < count; i++) {
    free(lines[i]);
  }
  free(lines);
}
