#include <cs50.h>
#include <stdio.h>

string checkamex(int nr)
{
    if (nr == 34)
    {
        return "AMEX";
    }
    if (nr == 37)
    {
        return "AMEX";
    }
    return "INVALID";
}
string checkmaster(int nr)
{
    if (nr <= 55 && nr >= 51)
    {
        return "MASTERCARD";
    }
    return "INVALID";
}
string checkvisa(int nr)
{
    if(nr/10 == 4)
    {
        return "VISA";
    }
    return "INVALID";
}
int prod(int n)
{
    n   *=2;
    int sum= n%10;
    n /= 10;
    sum += n%10;
    return sum;
}
int main(void)
{
    long nr = get_long("Give credit card number\n");
    string comp = "B";
    int sum = 0;
    int par = 1;
    int dig = 0;
    while (nr > 0)
    {
        if (par == 1)
        {
            sum += nr%10;
            nr /= 10;
            par = 2;
        }
        else
        {
            sum += prod(nr%10);
            nr/=10;
            par = 1;
        }
        if(nr<100 && comp[0] == 'B' )
        {
            comp = checkamex(nr);
            if(comp[0] == 'I')
                comp = checkmaster(nr);
            if(comp[0] == 'I')
                comp = checkvisa(nr);
        }
        dig ++;
    }
    if (sum%10 == 0 && dig>=13)
    {
        printf("%s\n",comp);
    }
    else {
        printf("INVALID\n");
    }
    return 0;

}