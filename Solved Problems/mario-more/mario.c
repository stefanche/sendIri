#include <cs50.h>
#include <stdio.h>

void printline(int nrSpaces, int nrHash)
{
    for(int i=0; i<nrHash+nrSpaces; i++)
    {
        if(i < nrSpaces)
        {
            printf(" ");
        }
        else
        {
            printf("#");
        }
    }
    printf("  ");
}

void printline2(int nrHash)
{
    for (int i=0; i<nrHash; i++)
    {
        printf("#");
    }
    printf("\n");
}

int main(void)
{
    int n = 0;
    while (true)
    {
        n = get_int("Input height: \n");
        if(n>0 && n<=8)
        {
            break;
        }

    }

    for( int i = 1; i <= n; i++)
    {
        printline(n-i,i);
        printline2(i);
    }
}