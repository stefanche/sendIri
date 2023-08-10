#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    for(int i= 0, n= height; i<n; i++)
    {
        for (int j= 0, m= width; j<m; j++)
        {
            average = image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen;
            average = round(average/3.00);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i= 0, n= height; i<n; i++)
    {
        if (width % 2 == 0)
        {
            for (int j= 0, m= width/2-1; j<=m; j++)
            {
                RGBTRIPLE temp;
                temp = image[i][j];
                image[i][j] = image[i][width-j-1];
                image[i][width-j-1] = temp;
            }
        }
        else
            {
                for (int j= 0, m= width/2; j<m; j++)
            {
                RGBTRIPLE temp;
                temp = image[i][j];
                image[i][j] = image[i][width-j-1];
                image[i][width-j-1] = temp;
            }
            }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i=0, n=height; i<n; i++)
    {
        for(int j=0, m=width; j<m; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    int average = 0;
    for(int i=0, n=height; i<n; i++)
    {
        for(int j=0, m=width; j<m; j++)
        {
            float sumBlue = 0;
            float sumGreen = 0;
            float sumRed = 0;
            float counter = 0;
            for (int r = i-1; r <= i+1; r++)
            {
                for (int c = j-1; c <= j+1; c++)
                {
                    if (r >= 0 && c >= 0 && r < height && c < width)
                    {
                        sumBlue += copy[r][c].rgbtBlue;
                        sumGreen += copy[r][c].rgbtGreen;
                        sumRed += copy[r][c].rgbtRed;
                        counter++;
                    }
                }
            }
            image[i][j].rgbtBlue = round(sumBlue/counter);
            image[i][j].rgbtGreen = round(sumGreen/counter);
            image[i][j].rgbtRed = round(sumRed/counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for(int i=0, n=height; i<n; i++)
    {
        for(int j=0, m=width; j<m; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    int average = 0;
    for(int i=0, n=height; i<n; i++)
    {
        for(int j=0, m=width; j<m; j++)
        {
            int sumBlue[] = {0,0};
            int sumGreen[] = {0,0};
            int sumRed[] = {0,0};
            int a = 0;
            for (int r = i-1; r <= (i+1); r++)
            {
                int b = 0;
                for (int c = j-1; c <= (j+1); c++)
                {
                    if (r >= 0 && c >= 0 && r < height && c < width)
                    {
                        sumBlue[0] += copy[r][c].rgbtBlue * gx[a][b];
                        sumGreen[0] += copy[r][c].rgbtGreen * gx[a][b];
                        sumRed[0] += copy[r][c].rgbtRed * gx[a][b];
                        sumBlue[1] += copy[r][c].rgbtBlue * gy[a][b];
                        sumGreen[1] += copy[r][c].rgbtGreen * gy[a][b];
                        sumRed[1] += copy[r][c].rgbtRed * gy[a][b];
                    }
                    b++;
                }
                a++;
            }
            sumBlue[0] = round(sqrt(pow(sumBlue[0],2) + pow(sumBlue[1],2)));
            sumRed[0] = round(sqrt(pow(sumRed[0],2) + pow(sumRed[1],2)));
            sumGreen[0] = round(sqrt(pow(sumGreen[0],2) + pow(sumGreen[1],2)));

            if(sumBlue[0] >255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sumBlue[0];
            }
            if(sumRed[0] >255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sumRed[0];
            }
            if(sumGreen[0] >255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sumGreen[0];
            }
        }
    }
    return;
}
