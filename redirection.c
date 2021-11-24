#include "headers.h"

void com(char *inp)
{
  char temp[10000] = "";
  strcpy(temp, inp);
  char *token[100],*token[100];
  char *rest = temp;

  int count = 0;

  while ((token[count] = strtok_r(rest, " \t", &rest)))
  {
    count++;
  }
 
  pid_t pid;

  pid = fork();

  if (pid < 0)
    perror("Error: \n");

  if (pid == 0)
  {
    int z = execvp(token[0], token);
    if (z < 0)
      perror("Error:\n");

    exit(0);
  }
  else
  {
    int status;
    waitpid(pid, &status, WUNTRACED);
  }  
  return;
}
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
  //printf("check 1 %s\n",inp);

  char *token[100];
  char *rest = inp;

  int count = 0;

  while ((token[count] = strtok_r(rest, "|", &rest)))
  {
    count++;
  }

   int filedes[count-1][2];
 
   for(int i=0; i<count-1 ; i++)
   {
     printf("check 2\n");
     if(pipe(filedes[i])<0)
     {
       perror("Could not create a pipe");
       exit(1);
     }

         if (i==0)
          {
              printf("0\n");
              int outFile = dup(STDOUT_FILENO);
              dup2(filedes[i][1], STDOUT_FILENO);
              close(filedes[i][1]);
              printf("--is it gobbled--\n");
              printf("check 3, %s\n",token[i]);
              com(token[i]);
              dup2(outFile, STDOUT_FILENO);
              close(outFile);
              printf("1\n");
          }
          else
          {
             //printf("0\n");
              int inFile = dup(STDIN_FILENO);
              int outFile = dup(STDOUT_FILENO);
              dup2(filedes[i][1], STDOUT_FILENO);
              dup2(filedes[i - 1][0], STDIN_FILENO);

              close(filedes[i][1]);
              close(filedes[i - 1][0]);
              printf("check 4 %s\n",token[i]);
               com(token[i]);
              dup2(inFile, STDIN_FILENO);
              dup2(outFile, STDOUT_FILENO);
              close(inFile);
              close(outFile);
             // printf("1\n");
          }
     }
      int inFile = dup(STDIN_FILENO);
      dup2(filedes[count - 2][0], STDIN_FILENO);

      close(filedes[count- 2][0]);
      printf("check 5 %s\n",token[count-1]);
      com(token[count - 1]);
      dup2(inFile, STDIN_FILENO);
     close(inFile);
}




















for(int i=0;i<k;i++){



int k1=0;

char* c1[100];

token=strtok(c[i]," \t\n");

while(token!=NULL){

c1[k1++]=token;

token=strtok(NULL," \t\n");

}



if(i==0){

pipe(p);

if(dup2(p[1],1)<0){

printf("error in dup2\n");

return;

}

close(p[1]);

}

else if(i==k-1){

dup2(p[0],0);

dup2(out_o,1);

}

else{

dup2(p[0],0);

pipe(p);

if(dup2(p[1],1)<0){

printf("error in dup2\n");

return;

}

close(p[1]);



}

int f_r=fork();

int stat;

if(f_r<0){

printf("failed to fork\n");

}

else if(f_r==0){

// io_redirect(c,k1);

if(is_ioredirect(c1,k1)==1){

io_redirect(c1,k1);

}

else{

execvp(c1[0],c1);

}

exit(0);

}

else{

waitpid(f_r,&stat,WUNTRACED);

dup2(in_o,0);

dup2(out_o,1);

}

}

return;

}

[Yesterday 22:14] Sudi Ananya
#include"headers.h"int is_ioredirect(char** list,int count){for(int i=0;i<count;i++){if(strcmp(list[i],">>")==0||strcmp(list[i],"<")==0||strcmp(list[i],">")==0){return 1;}}return 0;}

[Yesterday 22:14] Sudi Ananya
void pipefunc(char* command,char** list_of_args,int count){char* c[100];int k=0; //number of commands after separated by |char* token=strtok(command,"|");while(token!=NULL){c[k++]=token;token=strtok(NULL,"|");}int p[2];int in_o=dup(0);int out_o=dup(1);

[Yesterday 22:14] Sudi Ananya
for(int i=0;i<k;i++){int k1=0;char* c1[100];token=strtok(c[i]," \t\n");while(token!=NULL){c1[k1++]=token;token=strtok(NULL," \t\n");}if(i==0){pipe(p);if(dup2(p[1],1)<0){printf("error in dup2\n");return;}close(p[1]);}else if(i==k-1){dup2(p[0],0);dup2(out_o,1);}else{dup2(p[0],0);pipe(p);if(dup2(p[1],1)<0){printf("error in dup2\n");return;}close(p[1]);}int f_r=fork();int stat;if(f_r<0){printf("failed to fork\n");}else if(f_r==0){// io_redirect(c,k1);if(is_ioredirect(c1,k1)==1){io_redirect(c1,k1);}else{execvp(c1[0],c1);}exit(0);}else{waitpid(f_r,&stat,WUNTRACED);dup2(in_o,0);dup2(out_o,1);}}return;}


