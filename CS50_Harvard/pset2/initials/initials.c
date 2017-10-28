#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string name = get_string();

    for (int i = 0; i < strlen(name); i++)
    {
        int t = (int) name[i-1];
        int c = (int) name[i];

        if(c != 0 && c != 32)
        {
            if( t == 0 || t == 32)
            {
                printf("%c", toupper(name[i]));
            }
        }
    }
    printf("\n");
}
