#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        printf("To many args\n");
        return 1;
    }

    FILE *card= fopen(argv[1], "r");

    //breaks if card is null
    if (card == NULL)
    {
        printf("Could not open raw file\n");
        return 1;
    }

    BYTE chunk[512];
    int jpgnr = 0;
    char *jpgname = malloc(8 * sizeof(char));
    char yes = 'n';
    FILE *JPG;
    //repeats until first jpg then opens a jpg file for writing
    do
    {
        fread(chunk, sizeof(BYTE), 512, card);

        if (chunk[0] == 0xff && chunk[1] == 0xd8 && chunk[2] == 0xff && (chunk[3] & 0xf0) == 0xe0)
        {
            sprintf(jpgname, "%03i.jpg", jpgnr);
            JPG= fopen(jpgname, "w");
            jpgnr++;
            yes ='y';
            fwrite(chunk, sizeof(BYTE), 512, JPG);
            break;
        }

    }while (1);

    //copies to new jpg all the bytes checking if the new chunk is the beggining of a new jpg
    if( yes == 'y')
        while(fread(chunk, sizeof(BYTE), 512, card)==512)
        {
            //checks if new chunk is the beggining of a new jpg
            if (chunk[0] == 0xff && chunk[1] == 0xd8 && chunk[2] == 0xff && (chunk[3] & 0xf0) == 0xe0)
            {
                fclose(JPG);
                sprintf(jpgname, "%03i.jpg", jpgnr);
                jpgnr++;
                JPG = fopen(jpgname, "w");
            }
            fwrite(chunk, sizeof(BYTE), 512, JPG);

        }

    free(jpgname);
    fclose(card);
    fclose(JPG);
    return 0;

}