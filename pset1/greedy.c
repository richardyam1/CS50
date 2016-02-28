#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int coins = 0;
    float change = 0;
    int quarters = 0;
    int dimes = 0;
    int nickles = 0;
    
    do
    {
    printf("How much change is owed?");
    change = GetFloat();
    }
    while (change < 0);
    
    /* Convert dollar to cent */
    int cent = roundf(change * 100);
    
    /*Quarters*/
    do 
    {
        quarters += (cent/25);
        coins += quarters;
        cent -= (25 * quarters);
        
    }
    while(cent/25 != 0 );
    
    /*Dimes*/
    do
    {
        dimes += (cent/10);
        coins += dimes;
        cent -= (10 * dimes);
    }
    while(cent/10 != 0);
    
    /*Nickles*/
    do
    {
        nickles += (cent/5);
        coins += nickles;
        cent -= (5 * nickles);
    }
    while(cent/5 != 0);
    
    /*Pennies*/
    coins += cent;
    
    printf("%d\n", coins);
}