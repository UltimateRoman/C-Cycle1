#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg_color;
    int color;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg_color = (float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)
                        / 3; //Calculates value of average RGB intensity
            color = round(avg_color);
            image[i][j].rgbtBlue = color; //Assigns grayscale value to Red channel values
            image[i][j].rgbtGreen = color; //Assigns grayscale value to Green channel value
            image[i][j].rgbtRed = color; //Assigns grayscale value to Blue channel values
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, k = width - 1; j < width / 2; j++, k--) // Reverses pixels in each row to get reflected image
        {
            temp_image = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = temp_image;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];
    int c;
    float sum_Blue, sum_Green, sum_Red;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            c = 0;
            sum_Blue = 0;
            sum_Green = 0;
            sum_Red = 0;
            for (int a = i - 1; a < i + 2; a++)
            {
                for (int b = j - 1; b < j + 2; b++)
                {
                    if ((a >= 0) && (a < height) && (b >= 0) && (b < width))
                    {
                        sum_Blue += image[a][b].rgbtBlue;
                        sum_Green += image[a][b].rgbtGreen;
                        sum_Red += image[a][b].rgbtRed;
                        c++;
                    }
                }
            }
            image_copy[i][j].rgbtBlue = round(sum_Blue / (float)c); // Calculates average value of RGB for neighbouring pixels in a 3x3 box
            image_copy[i][j].rgbtGreen = round(sum_Green / (float)c);
            image_copy[i][j].rgbtRed = round(sum_Red / (float)c);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image_copy[i][j]; // Assigns modified values to original image
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}}, Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}}; // Declares kernel matrices
    float gx_Blue, gx_Green, gx_Red, gy_Blue, gy_Green, gy_Red, Blue, Red, Green;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gx_Blue = 0;
            gx_Green = 0;
            gx_Red = 0;
            gy_Blue = 0;
            gy_Green = 0;
            gy_Red = 0;
            for (int a = i - 1, m = 0; a < i + 2; a++, m++)
            {
                for (int b = j - 1, n = 0; b < j + 2; b++, n++)
                {
                    if ((a >= 0) && (a < height) && (b >= 0) && (b < width))
                    {
                        gx_Blue += Gx[m][n] * image[a][b].rgbtBlue;
                        gx_Green += Gx[m][n] * image[a][b].rgbtGreen;
                        gx_Red += Gx[m][n] * image[a][b].rgbtRed;
                        gy_Blue += Gy[m][n] * image[a][b].rgbtBlue;
                        gy_Green += Gy[m][n] * image[a][b].rgbtGreen;
                        gy_Red += Gy[m][n] * image[a][b].rgbtRed;
                    }
                    Blue = round(pow((pow(gx_Blue, 2) + pow(gy_Blue, 2)), 0.5));
                    Green = round(pow((pow(gx_Green, 2) + pow(gy_Green, 2)), 0.5));
                    Red = round(pow((pow(gx_Red, 2) + pow(gy_Red, 2)), 0.5));
                    if (Blue > 255) // Checks if calculated value is greater than 255
                    {
                        image_copy[i][j].rgbtBlue = 255;
                    }
                    else // Else assigns calculated value
                    {
                        image_copy[i][j].rgbtBlue = Blue;
                    }
                    if (Green > 255) // Checks if calculated value is greater than 255
                    {
                        image_copy[i][j].rgbtGreen = 255;
                    }
                    else // Else assigns calculated value
                    {
                        image_copy[i][j].rgbtGreen = Green;
                    }
                    if (Red > 255) // Checks if calculated value is greater than 255
                    {
                        image_copy[i][j].rgbtRed = 255;
                    }
                    else // Else assigns calculated value
                    {
                        image_copy[i][j].rgbtRed = Red;
                    }
                }
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image_copy[i][j]; // Assigns modified values to original image
        }
    }
    return;
}
