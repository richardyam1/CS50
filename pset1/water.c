#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /* Calculates the equivalent amount of water bottles used in the shower */
    printf("In minutes, input how long you shower\n");
    int minute = GetInt();
    int bottle = ((1.5 * minute) * 128)/16;
    printf("Minutes: %d\n", minute);
    printf("Bottles: %d\n", bottle);
}