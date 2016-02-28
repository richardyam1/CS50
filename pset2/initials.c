#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string name = GetString();
    printf("%c", toupper(name[0]));
        
    for (int j = 0, n = strlen(name); j < n; j++)
        if (name[j-1] ==  ' ')
        {                    
            printf("%c", toupper(name[j]));
        }
    printf("\n");
        
}