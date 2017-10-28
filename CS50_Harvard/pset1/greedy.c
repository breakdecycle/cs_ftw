#include <stdio.h>
#include <cs50.h>


int main(void)
{
    printf("O hai! ");

    float d;
    do
    {
        printf("How much change is owed?\n");
        d = get_float();
    }
    while (d < 0);

    int c = (int) ((d + 0.0055) * 100);

    int qtr = c / 25; // number of quaters needed
    int dim = (c % 25) / 10; // number of dimes needed
    int nic = ((c % 25) % 10) / 5; // number of nickels needed
    int pen = ((c % 25) % 10) % 5; // number of pennies needed

    int t = qtr + dim + nic + pen; // total number of coins needed

    /* for testing results
    printf("%i cents\n", c);

    printf("%i qtr\n", c / 25);

    printf("%i dim\n", (c % 25) / 10);

    printf("%i nic\n", ((c % 25) % 10) / 5);

    printf("%i pen\n", ((c % 25) % 10) % 5);
    */

    printf("%i\n", t);
}
