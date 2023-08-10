#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

typedef struct
{
    int  rgbtBlue;
    int  rgbtGreen;
    int  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;


int main(int argc, char *argv[])
{
    RGBTRIPLE image;
    image.rgbtBlue = 25;
    image.rgbtGreen= 23;
    image.rgbtRed = 24;

    printf("Hello %i\n", image.argv[1]);
}