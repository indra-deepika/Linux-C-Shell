#include "headers.h"

int check_piping(char *inp)
{
  if (strstr(inp, "|"))
  {
    piping(inp);
    return 1;
  }

  return 0;
}
void piping(char *inp)
{

  char temp[10000] = "";
  strcpy(temp, inp);
  char *token[100];
  char *rest = temp;

  int count = 0;

  while ((token[count] = strtok_r(rest, "|", &rest)))
  {
    count++;
  }
   int fd[2];
   int in = dup(0);
   int out = dup(1);

  for (int i = 0; i < count; i++)
  {
    int k = 0;

    char temp[10000] = "";
    strcpy(temp, token[i]);
    char *token2[100];
    char *rest = temp;
    while ((token2[k] = strtok_r(rest, " \t\n", &rest)))
    {
      k++;
    }

    if (i == 0)
    {
      pipe(fd);
      if (dup2(fd[1], 1) < 0)
      {
        printf("error in dup2\n");
        return;
      }
      close(fd[1]);
    }
    else if (i == count - 1)
    {
      dup2(fd[0], 0);
      dup2(out, 1);
    }
    else
    {
      dup2(fd[0], 0);
      pipe(fd);
      if (dup2(fd[1], 1) < 0)
      {
        printf("error in dup2\n");
        return;
      }
      close(fd[1]);
    }
    command(token[i]);
  }

  return;
}
