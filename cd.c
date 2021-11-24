#include "headers.h"


void cd(char *inp, int count)
{
  char dir[20000];
  getcwd(dir, 20000);

  if (count == 1)
  {
    strcpy(store_prev,dir);
    chdir(root_dir);
    return;
  }

  if (count > 2)
  {
    printf("Too many arguments!");
  }

  if (inp == "~")
  {
    strcpy(store_prev,dir);
    chdir(root_dir);
    return;
  }
 if (strcmp(inp, "-") == 0) 
 {
   printf("%s\n",store_prev);
   chdir(store_prev);
   strcpy(store_prev,dir);
   return;
  }


 
  int ch = chdir(inp);
  // if the directory doesnt exist in the path
  if (ch == -1)
  {
    char *token;

    if ((token = strtok_r(inp, "/", &inp)) != NULL)
    {
      if (strcmp(token, "~") == 0)
      {
         
        int ch2 = chdir(inp);
        if (ch2 == -1)
        {
          printf("No such directory");
          return ;
        }
         strcpy(store_prev,dir);

        return;
      }

      else
      {
        printf("No such directory");
        return ;
      }
      strcpy(store_prev,dir);
    }
  }
 strcpy(store_prev,dir);

  /*strcpy(temp, inp);
 char temp[10000][10] = "";
  char *token;
  char *token_temp, *tok;
  char **rest = temp;

  printf("%s", token);

  token = strtok_r(rest, " ", &rest);

  printf("%s", token);
  tok = strtok_r(rest, " ", &rest);
  tok = strtok_r(rest, " ", &rest);
  token_temp = strtok_r(rest, " ", &rest);

  if (strcmp(token, "~") == 0)
  {
    chdir(root_dir);
    return;
  }
  tok = strtok_r(rest, "/", &rest);
  printf("%s fjngk", tok);

  int ch = chdir(token);
  // if the directory doesnt exist in the path
  if (ch == -1)
  {
    printf("No such directory");
  }

  char dir[200000];
  getcwd(dir, 200000);*/
}