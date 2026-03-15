#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculating average of pixels
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // Updating the values
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        // Loop over half side pixels
        for (int j = 0; j < width / 2; j++)
        {
            // Creating a temporary variable
            int tmp = image[i][j].rgbtRed;
            // Swaping the right to left side
            image[i][j].rgbtRed = image[i][(width - 1) - j].rgbtRed;
            // Swaping the left to right side
            image[i][(width - 1) - j].rgbtRed = tmp;

            // Creating a temporary variable
            tmp = image[i][j].rgbtGreen;
            // Swaping the right to left side
            image[i][j].rgbtGreen = image[i][(width - 1) - j].rgbtGreen;
            // Swaping the left to right side
            image[i][(width - 1) - j].rgbtGreen = tmp;

            // Creating a temporary variable
            tmp = image[i][j].rgbtBlue;
            // Swaping the right to left side
            image[i][j].rgbtBlue = image[i][(width - 1) - j].rgbtBlue;
            // Swaping the left to right side
            image[i][(width - 1) - j].rgbtBlue = tmp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels to create a copy to not mess with original image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int count = 0;

            for (int di = -1; di < 2; di++)
            {
                for (int dj = -1; dj < 2; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    if (0 <= ni && ni < height && 0 <= nj && nj < width)
                    {
                        sumRed += copy[ni][nj].rgbtRed;
                        sumGreen += copy[ni][nj].rgbtGreen;
                        sumBlue += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            int avgRed = round(sumRed / (float) count);
            int avgGreen = round(sumGreen / (float) count);
            int avgBlue = round(sumBlue / (float) count);

            image[i][j].rgbtRed = avgRed;
            image[i][j].rgbtGreen = avgGreen;
            image[i][j].rgbtBlue = avgBlue;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels to create a copy to not mess with original image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Declare Gx and Gy as a 3x3 kernels
    int Gx[3][3] = {{-1, 0, 1},
                    {-2, 0, 2},
                    {-1, 0, 1}};

    int Gy[3][3] = {{-1, -2, -1},
                    {0, 0, 0},
                    {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxRed = 0;
            int gxGreen = 0;
            int gxBlue = 0;
            int gyRed = 0;
            int gyGreen = 0;
            int gyBlue = 0;

            for (int di = -1; di < 2; di++)
            {
                for (int dj = -1; dj < 2; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;
                    int weightX = Gx[di + 1][dj + 1];
                    int weightY = Gy[di + 1][dj + 1];

                    if (0 <= ni && ni < height && 0 <= nj && nj < width)
                    {
                        gxRed += copy[ni][nj].rgbtRed * weightX;
                        gyRed += copy[ni][nj].rgbtRed * weightY;
                        gxGreen += copy[ni][nj].rgbtGreen * weightX;
                        gyGreen += copy[ni][nj].rgbtGreen * weightY;
                        gxBlue += copy[ni][nj].rgbtBlue * weightX;
                        gyBlue += copy[ni][nj].rgbtBlue * weightY;
                    }
                }
            }

            int red = round(sqrt(gxRed*gxRed + gyRed*gyRed));
            if (red > 255)
            {
                red = 255;
            }

            int green = round(sqrt(gxGreen*gxGreen + gyGreen*gyGreen));
            if (green > 255)
            {
                green = 255;
            }

            int blue = round(sqrt(gxBlue*gxBlue + gyBlue*gyBlue));
            if (blue > 255)
            {
                blue = 255;
            }

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;

        }
    }

    return;
}
