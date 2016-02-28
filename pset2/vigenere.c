#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2 )
    {
        printf("\n");
        return 1;
    }
    
    /*Keyword typed in command line*/
    string key = argv[1];
    
    /*Checks to see if the strings contains non-integers*/
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Don't put any numbers in your sentence.");
            return 1;
        }
        
    }
    
    /*Gets plaintext to encrypt*/
    string text = GetString();
    
    /*Loops through text to encrypt it*/
    for (int j = 0, k = 0, o = strlen(text); j < o; j++)
    {
        if (isalpha(text[j]))
        {
            if (isupper(text[j]))
            {
                int toAlpha = (text[j] - 65);
                int toAlphakey = (toupper(key[k % strlen(key)]) - 65);
                int toASC = (((toAlpha + toAlphakey) % 26) + 65);
                printf("%c", (toASC));
                k++;
                
            }
            
            else if (islower(text[j]))
            {
                int toAlpha = (text[j] - 97);
                int toAlphakey = (tolower(key[k % strlen(key)]) - 97);
                int toASC = (((toAlpha + toAlphakey) % 26) + 97);
                printf("%c", (toASC));
                k++;
            }
            
        }
        
        /*Types out non-alphabetic letters */
        else
        {
            printf("%c", text[j]);
            
        }
    }
    
    printf("\n");
    return 0;
    
}