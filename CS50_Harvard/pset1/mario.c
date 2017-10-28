#include <stdio.h>
#include <cs50.h>
#include <string.h>

void steps(int n);
void space(int n);

int main(void)
{
    printf("Height: ");
    int h = get_int();

    if (h != 0)
    {
        if (h > 0 && h < 24)
        {
            for (int i = 1; i <= h; i++)
            {
                space(h-i);
                steps(i);
                printf("  ");
                steps(i);
                printf("\n");
            }
        }
        else
        {
            main(); // reruns itself
        }
    }
}

// function to generate the 'steps' for each level.
void steps(int n)
{
    for( int i = 0; i < n; i++)
    {
        printf("#");
    }
}

// function to generate space before the 'steps' on each level.
void space(int n)
{
    for( int i = 0; i < n; i++)
    {
        printf(" ");
    }
}