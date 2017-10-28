#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    if(argc != 2)
    {
        printf("Usage: ./caesar k\n");

        return 1;
    }

    else
    {
        // printf("argc: %i\n", argc); // [x] Check to see the number of strings that are in argv - based on what was typed in command-line.
        // string k = argv[1]; // [x] To test and printf as string. Can be as 'int' using atoi().

        int k = atoi(argv[1]) % 26; // Converts the string argv[i] into an 'int'. 'atoi' is from stdlid.h but also in cs50.h.

        printf("plaintext: ");
        string p = get_string();

        /* Test print each character and decimal value
        for (int i = 0; i < strlen(p); i++)
        {
            printf("%c %i\n", p[i], (int) p[i]);
        }
        */

        printf("ciphertext: ");

        for (int i = 0; i < strlen(p); i++) // char by char method (need to make more efficient)
        {
            // temp = (int) p[i] + k;

            int temp = (int) p[i];
            int temp2 = temp + k;

            if (temp > 64 && temp < 91)
            {
                if (temp2 > 91)
                {
                    printf("%c", 65 + temp2 - 91 );
                }
                else
                {
                    printf("%c", (char) temp2);
                }
            }
            else if (temp > 96 && temp < 123)
            {
                if (temp2 > 122)
                {
                    printf("%c", 97 + temp2 - 123 );
                }
                else
                {
                    printf("%c", (char) temp2);
                }
            }
            else printf("%c", (char) temp);
        }

        printf("\n");

    }

}