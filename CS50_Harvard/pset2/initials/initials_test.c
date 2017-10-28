#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int len(string s);
int arg(int argc, string argv);


int main(void)
{
    string name = get_string();
    // char *test = get_string();

    printf("%c %i\n", name[-1], (int) name[-1] );
    printf("%c %i\n", name[-2], (int) name[-2] );
    printf("%i\n", len(name));

    // printf("%c <---\n", test[1][1]);


    for (int i =0; i < strlen(name); i++)
    {
        printf("%i ", (int) name[i]);

        printf("%c %c %i\n", name[i], toupper(name[i]), i);
    }



    for (int i =0; i < strlen(name); i++)
    {
        int t = (int) name[i-1];

        if( t == 0 || t == 32)
        {
            printf("%c ", toupper(name[i]));
        }

    }


}

/*
int arg(int argc, string argv)
{
    printf("%s\n", argv[2]);
}
*/


int len(string s)
{
    int n = 0;

    while( s[n] != '\0' )
    {
        n++;
    }

    return n;
}
