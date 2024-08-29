#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
  // Loop over all pixels
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      // Take average of red, green, and blue
      int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

      // Update pixel values
      image[i][j].rgbtRed = (BYTE)average;
      image[i][j].rgbtGreen = (BYTE)average;
      image[i][j].rgbtBlue = (BYTE)average;
    }
  }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
  // Loop over all pixels
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      int originalRed = image[i][j].rgbtRed;
      int originalGreen = image[i][j].rgbtGreen;
      int originalBlue = image[i][j].rgbtBlue;

      // Compute sepia values
      int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
      int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
      int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

      // Update pixel with sepia values
      image[i][j].rgbtRed = (BYTE)(sepiaRed > 255 ? 255 : sepiaRed);
      image[i][j].rgbtGreen = (BYTE)(sepiaGreen > 255 ? 255 : sepiaGreen);
      image[i][j].rgbtBlue = (BYTE)(sepiaBlue > 255 ? 255 : sepiaBlue);
    }
  }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
  // Loop over all pixels
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width - j; j++)
    {
      // Swap pixels
      RGBTRIPLE temp = image[i][j];
      image[i][j] = image[i][width - 1 - j];
      image[i][width - 1 - j] = temp;
    }
  }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
  RGBTRIPLE copy[height][width];

  // Create a copy of image
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
      double pixel_count = 0.0;
      int sum_red = 0;
      int sum_green = 0;
      int sum_blue = 0;

      for (int k = -1; k < 2; k++)
      {
        if (i + k < 0 || i + k >= height)
        {
          continue;
        }

        for (int l = -1; l < 2; l++)
        {
          if (j + l < 0 || j + l >= width)
          {
            continue;
          }

          sum_red += copy[i + k][j + l].rgbtRed;
          sum_green += copy[i + k][j + l].rgbtGreen;
          sum_blue += copy[i + k][j + l].rgbtBlue;

          pixel_count++;
        }
      }

      image[i][j].rgbtRed = (BYTE)round(sum_red / pixel_count);
      image[i][j].rgbtGreen = (BYTE)round(sum_green / pixel_count);
      image[i][j].rgbtBlue = (BYTE)round(sum_blue / pixel_count);
    }
  }
}
