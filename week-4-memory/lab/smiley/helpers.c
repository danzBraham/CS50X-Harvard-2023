#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    // Iterate over each row of the image
    for (int i = 0; i < height; i++)
    {
        // Iterate over each column of the image
        for (int j = 0; j < width; j++)
        {
            // Check if the current pixel is black (RGB values are all 0)
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtRed == 0x00)
            {
                // Change the green component of the pixel to 255 (full intensity)
                image[i][j].rgbtGreen = 0xff;
                image[i][j].rgbtBlue = 0xaa;
            }
        }
    }
}
