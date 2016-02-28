#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("\n");
        return 1;
    }
    
    /*Converts int string to int */
    int k = atoi(argv[1]);
    
    string text = GetString();

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        
        if isalpha(text[i])
        {
            if isupper(text[i])
            {
                /*Converts ASCII to alphabet to ASCII*/
                int toAlpha = (text[i] - 65);
                int toASC = (((toAlpha + k) % 26) + 65);
                printf("%c", (toASC));
            }
            
            else if islower(text[i])
            {
                /*Converts ASCII to alphabet to ASCII*/
                int toAlpha = (text[i] - 97);
                int toASC = (((toAlpha + k) % 26) + 97);
                printf("%c", (toASC));
            }
        }
        
        else
        {
            /*Prints non-letters*/
            printf("%c", text[i]);
        }
            
        
    }
    
    printf("\n");
    return 0;
}