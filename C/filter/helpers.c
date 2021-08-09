#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            int a = (round)(((float)image[i][n].rgbtBlue + (float)image[i][n].rgbtGreen + (float)image[i][n].rgbtRed)/3);
            image[i][n].rgbtBlue = a;
            image[i][n].rgbtGreen = a;
            image[i][n].rgbtRed = a;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            float a = image[i][n].rgbtBlue;
            float b = image[i][n].rgbtRed;
            float c = image[i][n].rgbtGreen;

            int sepiaRed = (round)((.393 * b) + (.769 * c) + (.189 * a));
            int sepiaGreen = (round)((.349 * b) + (.686 * c) + (.168 * a));
            int sepiaBlue = (round)((.272 * b) + (.534 * c) + (.131 * a));

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][n].rgbtBlue = sepiaBlue;
            image[i][n].rgbtGreen = sepiaGreen;
            image[i][n].rgbtRed = sepiaRed;
        }
    }
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE store;

    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width/2; n++)
        {
            store = image[i][n];
            image[i][n] = image[i][width - n - 1];
            image[i][width - n - 1] = store;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE store[height][width];
    int j = 0;
    
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            int averageb = 0;
            int averageg = 0;
            int averager = 0;

            for (int a = i - 1; a < i + 2 && a < height; a++)
            {
                if (a < 0)
                {
                    a = 0;
                }

                for (int b = n - 1; b < n + 2 && b < width; b++)
                {
                    if (b < 0)
                    {
                        b = 0;
                    }

                    averageg = averageg + (float)image[a][b].rgbtGreen;
                    averageb = averageb + (float)image[a][b].rgbtBlue;
                    averager = averager + (float)image[a][b].rgbtRed;
                    j++;
                }
            }

            store[i][n].rgbtGreen = (round)((float)averageg/j);
            store[i][n].rgbtRed = (round)((float)averager/j);
            store[i][n].rgbtBlue = (round)((float)averageb/j);
    
            averageb = 0;
            averageg = 0;
            averager = 0;
            j = 0;
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            image[i][n] = store[i][n];
        }
    }
}