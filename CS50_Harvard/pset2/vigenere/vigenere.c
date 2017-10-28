#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


// INCOMPLETE! 2017 10 28

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./vinegere k\n");
        return 1;
    }

    else
    {

        string k = argv[1];
        printf("key: %s\n", k);

        int temp[strlen(k)];
        for(int i = 0; i < strlen(k); i++)
        {
            if(k[i] > 64 && k[i] < 91)
            {
                temp[i] = (int) k[i] - 65;
                printf("k %i, t2 %i\n", (int) k[i], temp[i]); // print to check results
            }
            else if(k[i] > 96 && k[i] < 123)
            {
                temp[i] = (int) k[i] - 97;
                printf("k %i, t2 %i\n", (int) k[i], temp[i]); // print to check results
            }
            else return 1;
        }

        printf("test: %i \n", temp);

        printf("plaintext: ");
        string ptext = get_string();

        printf("cyphertext: %s\n", ptext);

        return 0;
    }

}