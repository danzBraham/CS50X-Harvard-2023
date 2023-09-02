#include "helpers.h"
#include "math.h"
#include "string.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average color value
            float avg = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;

            // Round the average value
            int rounded_avg = round(avg);

            // Assign average value to each channel
            image[i][j].rgbtRed = rounded_avg;
            image[i][j].rgbtGreen = rounded_avg;
            image[i][j].rgbtBlue = rounded_avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Store original color values
            int original_red = image[i][j].rgbtRed;
            int original_green = image[i][j].rgbtGreen;
            int original_blue = image[i][j].rgbtBlue;

            // Calculate sepia values for each channel
            int sepia_red = round(.393 * original_red + .769 * original_green + .189 * original_blue);
            int sepia_green = round(.349 * original_red + .686 * original_green + .168 * original_blue);
            int sepia_blue = round(.272 * original_red + .534 * original_green + .131 * original_blue);

            // Ensure sepia values are within the valid range
            image[i][j].rgbtRed = (sepia_red > 255) ? 255 : sepia_red;
            image[i][j].rgbtGreen = (sepia_green > 255) ? 255 : sepia_green;
            image[i][j].rgbtBlue = (sepia_blue > 255) ? 255 : sepia_blue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < width / 2; j++)
        {
            // Swap pixels horizontally
            int opposite_j = width - 1 - j;
            RGBTRIPLE temp = image[i][opposite_j];
            image[i][opposite_j] = image[i][j];
            image[i][j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // Create a temporary copy of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < width; j++)
        {
            int count = 0;
            float blur_red = 0;
            float blur_green = 0;
            float blur_blue = 0;

            // Iterate over 3x3 grid around the pixel
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int row = i + k;
                    int col = j + l;

                    // Check if the current pixel is within the image bounds
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        // Accumulate color values for averaging
                        blur_red += temp[row][col].rgbtRed;
                        blur_green += temp[row][col].rgbtGreen;
                        blur_blue += temp[row][col].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate the average color values and assign them to the original image
            image[i][j].rgbtRed = round(blur_red / count);
            image[i][j].rgbtGreen = round(blur_green / count);
            image[i][j].rgbtBlue = round(blur_blue / count);
        }
    }
}
