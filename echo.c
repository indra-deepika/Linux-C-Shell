#include "headers.h"
void echo(char *token[])
{

  int i=1;
   while(token[i]!=NULL)
   {
    printf("%s ", token[i]);
    i++;
   }

    printf("\n");
  
}                                        