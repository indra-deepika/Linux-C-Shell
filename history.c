#include "headers.h"
void st_hist(char *token, int his)
{
    for(int i=his ; i >=0 ; i--)
    {
      strcpy(hist[i+1], hist[i]);
    }
    strcpy(hist[0],token);

   

}

void history(int count)
{ 
    
    for(int i=count-1; i >=0 ; i--)
    {
        printf("%s \n",hist[i]);

    }

}