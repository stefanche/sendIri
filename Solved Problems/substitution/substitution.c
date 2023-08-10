#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("No arguments or to many args\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key not long enough\n");
        return 1;
    }
    int i = 0;
    int alf[26];
    int key[26];
    key[0] = 0;
    for (int j = 0; j<26; j++)
    {
        if(j<25)
        {
            key[j+1] = key[j]+1;
        }
        alf[j] = 0;
    }
    int al = 0;
    while (argv[1][i] != '\0')
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Contains non alphabetical\n");
            return 1;
        }
        if (isupper(argv[1][i]) == 0)
        {
            argv[1][i] = toupper(argv[1][i]);
        }
        al = (int)(argv[1][i]-65);
        alf[al]++;
        if (alf[al] != 1)
        {
            printf("Repeated letters\n");
            return 1;
        }
        key[i] = (key[i] - (int)(argv[1][i]-65))*(-1);
        i++;
    }
    string cypher = get_string("Give string: \n");
    i=0;
    int f = 0;
    while (cypher[i] != '\0')
    {
        if(isalpha(cypher[i]) != 0)
        {
            f = (int)(cypher[i]);
            if(isupper(cypher[i]) != 0)
            {
                f += key[(int)(cypher[i])-65];
            }
            else
            {
                f += key[(int)(cypher[i])-97];
            }
            cypher[i] = (char)f;
        }
        i++;
    }
    printf("ciphertext: %s\n", cypher);
    return 0;
}