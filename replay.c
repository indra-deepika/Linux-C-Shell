#include "headers.h"

void replay(char *token[], int k)
{
    char new[1000]="";
    char temp[1000];

    for(int i=2 ; i<k-4 ;i++)
    {
        strcpy(temp,token[i]);
        strcat(new,temp);
        strcat(new," ");
    }

  // printf("%s",new);
    int interval = atoi(token[k-3]);
    int period = atoi(token[k-1]);

    char temp2[1000];
    strcat(temp2,"sleep");
    strcat(temp2 ," ");
    strcat(temp2,token[k-1]);
    //printf("%s",temp2);
    char temp3[1000];
    strcpy(temp3,new);


    for(int i=0 ; i<period ;i++)
    {
        command(new);
       // printf("%s",new);
        //command(temp2);
        sleep(interval);
        strcpy(new,temp3);
       //printf("%s",new);
    }
}