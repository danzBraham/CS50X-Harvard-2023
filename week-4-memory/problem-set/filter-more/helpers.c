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

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
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
        for (int j = 0; j < width; j++)
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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

    // Define the Sobel operator kernels
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Apply the Sobel operator to each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize the sum of gradients for each color channel
            float gx_red = 0, gx_green = 0, gx_blue = 0;
            float gy_red = 0, gy_green = 0, gy_blue = 0;

            // Convolve the image with the Sobel operator kernels
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int row = i + k;
                    int col = j + l;

                    // Check if the current pixel is within the image bounds
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        // Get the color values of the neighboring pixel
                        int red = temp[row][col].rgbtRed;
                        int green = temp[row][col].rgbtGreen;
                        int blue = temp[row][col].rgbtBlue;

                        // Convolve the pixel values with the corresponding Sobel kernel values
                        gx_red += red * Gx[k + 1][l + 1];
                        gy_red += red * Gy[k + 1][l + 1];
                        gx_green += green * Gx[k + 1][l + 1];
                        gy_green += green * Gy[k + 1][l + 1];
                        gx_blue += blue * Gx[k + 1][l + 1];
                        gy_blue += blue * Gy[k + 1][l + 1];
                    }
                }
            }

            // Calculate the magnitude of the gradient for each color channel
            int magnitude_red = round(sqrt(gx_red * gx_red + gy_red * gy_red));
            int magnitude_green = round(sqrt(gx_green * gx_green + gy_green * gy_green));
            int magnitude_blue = round(sqrt(gx_blue * gx_blue + gy_blue * gy_blue));

            // Set the pixel values in the image to the magnitude of the gradient
            image[i][j].rgbtRed = (magnitude_red > 255) ? 255 : magnitude_red;
            image[i][j].rgbtGreen = (magnitude_green > 255) ? 255 : magnitude_green;
            image[i][j].rgbtBlue = (magnitude_blue > 255) ? 255 : magnitude_blue;
        }
    }
}
