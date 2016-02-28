#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
   
    
    /*Asks for pyramid height */
    do
    {
    printf("How high do you want the half-pyramid to be? (Max: 23)");
    height = GetInt();
    }
    while (height > 23 || height < 0);
    
    
    /* Builds the pyramid */ 
    for (int i = 0; i < height; i ++)
    {
        
        for (int space = 0; space < (height -1) - i; space++)
        {
           printf(" ");
            
        }
        
        
        
        for (int hash = 0; hash <i + 2 ; hash ++)
        {
            printf("#");
        }
        
        
        
        printf("\n");
    }
}