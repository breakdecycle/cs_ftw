#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count(long long num);
int front(long long num, int n);
int add_dgt(int val);
int check(long long num);

int main(void)
{

    long long num;

    do
    {
        printf("Number: ");
        num = get_long_long();
    }
    while(num < 0);

    // establish variables for sorting card type
    int len = count(num);
    int frt_one = front(num, 1);
    int frt_two = front(num, 2);


    /* Checking...
    // printf("front %i digit is %i\n", 2, front(num, 2));

    // printf("%i\n", check(num) );

    // printf("%i summ\n", add_dgt((int) num));
    */

    if (len == 15)
    {
        if (frt_two == 34 || frt_two == 37)
        {
            if (check(num) == 0)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else if (len == 13)
    {
        if (frt_one == 4)
        {
            if (check(num) == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else if (len == 16)
    {
        if (frt_one == 4)
        {
            if (check(num) == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (frt_two == 51 || frt_two == 52 || frt_two == 53 || frt_two == 54 || frt_two == 55)
        {
            if (check(num) == 0)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else // don't change
    {
        printf("INVALID\n");
    }


}


// count the number of digits
int count(long long num)
{
    int count = 0;

    while(num != 0)
    {
        num /=10;
        ++count;
    }

    return count;
}

// return the front 'n' digits
int front(long long num, int n)
{
    int len = count(num);

    int frt = num / pow(10, len - n);

    return frt;
}

// function to add each digits in a number.
int add_dgt(int val)
{
    int len = count((long long) val);
    long long mod, rem;
    int dgt;
    int sum = 0;

    for (int i = 1; i <= len; i++)
    {
        mod = pow(10, i);
        rem = pow(10, i-1);
        dgt = (val % mod) / rem;
        sum = sum + dgt;
    }

    return sum;
}


int check(long long num)
{

    // establish variables for checking end value == 0 or != 0
    long long mod, rem;
    int i, j, val;
    int sum = 0;

    // sum of the product of 2 and every 2 digits starting form the second-to-last digit
    for (i = 1; i <= count(num)/2; i++)
    {
        mod = pow(10,i*2);
        rem = pow(10,i*2-1);
        val = (num % mod) / rem;
        // printf("%ith Last Number is %i\n", i*2, val);
        sum = sum + add_dgt(val*2);
        // printf("Cumulative sum of digits in %i is %i\n", val*2, sum);
    }
    // sum of the digits not multiplied by 2.
    for (i = 0, j = 1; i < count(num)/2+1; i++)
    {
        mod = pow(10,(2*i+1));
        rem = pow(10,2*i);
        val = (num % mod) / rem;
        // printf("%ith Last Number is %i\n", 2*i+1, val);
        sum = sum + val;
        // printf("Cumulative sum is %i\n", sum);
    }

    // printf("sum is %i\n", sum);
    // printf("last digit is %i\n", sum % 10);

    if ((sum % 10) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}