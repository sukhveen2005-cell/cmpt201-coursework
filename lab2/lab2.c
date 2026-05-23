#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  while (1) {
    char *line = NULL;
    size_t len = 0;
    printf("Enter programs to run.\n> ");
    ssize_t num = getline(&line, &len, stdin);
    if (num == -1) {
      free(line);
      break;
    }
    if (strcmp(line, "\n") == 0 || strcmp(line, "exit\n") == 0) {
      free(line);
      break;
    }
    if (strcmp(line, "joke\n") == 0) {
      printf("knock knock joke");
      free(line);
      continue;
    }
    char *saveptr;
    char *tokenize = strtok_r(line, "\n", &saveptr);

    pid_t pid = fork();
    if(pid==-1)
    {
      perror("fork");
    }
    else if (pid == 0) {
      execl(tokenize, tokenize, NULL);
      perror("execl failed");
      exit(1);
    } 
    else {
      waitpid(pid, NULL, 0);
    }
    free(line);
  }
  return 0;
}
