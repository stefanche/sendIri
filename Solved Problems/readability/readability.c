#include <cs50.h>
#include <stdio.h>
#include <math.h>

float grade(int w, int s, int l)
{
    float Le= l*100.0000;
    Le= Le/w;
    float Se= s *100.0000;
    Se= Se/w;
    float ind = 0.0588 *Le- 0.296*Se- 15.8;
    return ind;
}
int main(void)
{
    int sent = 0;
    int let = 0;
    int words = 0;
    string prop = get_string("Text: \n");
    int i = 0;
    string s = "'";
    while (prop[i] != '\0')
    {
        if (prop[i] == ' ')
        {
            words ++;
        }
        else if (prop[i]== '.' || prop[i]== '!' || prop[i]== '?' || prop[i]== '.')
        {
            sent++;
        }
        else if(prop[i] != ',' && prop[i] != s[0] )
        {
            let++;
        }
        i++;

    }
    words++;
    float gr = grade(words, sent, let);
    if (gr<1)
    {
        printf("Before Grade 1\n");
    }
    else if(gr>16)
    {
        printf("Grade 16+\n");
    }
    else
    printf("Grade %i\n", (int) round(gr));
}