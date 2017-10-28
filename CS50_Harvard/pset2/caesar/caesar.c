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
        printf("plaintext: ");
        string p = get_string();

        int plen = strlen(p);
        int k = atoi(argv[1]) % 26; // Converts the string argv[i] into an 'int'. 'atoi' is from stdlid.h but also in cs50.h.
        string ctext = malloc(plen); // Allocate same amount of memory to a new character.

        for (int i = 0; i < plen; i++)
        {
            int pchar = (int) p[i];
            int cchar = pchar + k;

            if (pchar > 64 && pchar < 91)
            {
                if (cchar > 91)
                {
                    ctext[i] = 65 + cchar - 91;
                }
                else
                {
                    ctext[i] = cchar;
                }
            }

            else if (pchar > 96 && pchar < 123)
            {
                if (cchar > 122)
                {
                    ctext[i] = 97 + cchar - 123;
                }
                else
                {
                    ctext[i] = cchar;
                }
            }

            else ctext[i] = pchar;

        }

        printf("ciphertext: %s\n", ctext);

        return 0;

    }

}