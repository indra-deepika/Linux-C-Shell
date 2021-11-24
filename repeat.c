#include "headers.h"
void repeat(char *token[], int count)
{
    // printf("ehjfjh");
    int no_times = atoi(token[1]);

    char fi_tok[1000]="";

     for (int i = 2; i < count; i++)
     {
        
        strcat(fi_tok, token[i]);
        strcat(fi_tok," ");
     }
   
     //printf("%s swiss\n",fi_tok);
     char temp[1000]="";
     strcpy(temp,fi_tok);
    while (no_times--)
    {
        command(fi_tok);
        //printf("%s  now wt\n",fi_tok);
        strcpy(fi_tok,temp);
    }
}