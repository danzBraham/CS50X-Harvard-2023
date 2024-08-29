#include "math.h"
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
      image[i][j].rgbtRed = average;
      image[i][j].rgbtGreen = average;
      image[i][j].rgbtBlue = average;
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
      int red = 0, green = 0, blue = 0;

      for (int k = -1; k < 2; k++)
      {
        for (int l = -1; l < 2; l++)
        {
          int row = i + k;
          int col = j + l;

          if (row >= 0 && row < height && col >= 0 && col < width)
          {
            red += copy[row][col].rgbtRed;
            green += copy[row][col].rgbtGreen;
            blue += copy[row][col].rgbtBlue;

            pixel_count++;
          }
        }
      }

      image[i][j].rgbtRed = round(red / pixel_count);
      image[i][j].rgbtGreen = round(green / pixel_count);
      image[i][j].rgbtBlue = round(blue / pixel_count);
    }
  }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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

  int Gx[3][3] = {
      {-1, 0, 1},
      {-2, 0, 2},
      {-1, 0, 1},
  };

  int Gy[3][3] = {
      {-1, -2, -1},
      {0, 0, 0},
      {1, 2, 1},
  };

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      int gx_red = 0, gx_green = 0, gx_blue = 0;
      int gy_red = 0, gy_green = 0, gy_blue = 0;

      for (int k = -1; k < 2; k++)
      {
        for (int l = -1; l < 2; l++)
        {
          int row = i + k;
          int col = j + l;

          if (row >= 0 && row < height && col >= 0 && col < width)
          {
            gx_red += copy[row][col].rgbtRed * Gx[k + 1][l + 1];
            gx_green += copy[row][col].rgbtGreen * Gx[k + 1][l + 1];
            gx_blue += copy[row][col].rgbtBlue * Gx[k + 1][l + 1];

            gy_red += copy[row][col].rgbtRed * Gy[k + 1][l + 1];
            gy_green += copy[row][col].rgbtGreen * Gy[k + 1][l + 1];
            gy_blue += copy[row][col].rgbtBlue * Gy[k + 1][l + 1];
          }
        }
      }

      int red = round(sqrt(gx_red * gx_red + gy_red * gy_red));
      int green = round(sqrt(gx_green * gx_green + gy_green * gy_green));
      int blue = round(sqrt(gx_blue * gx_blue + gy_blue * gy_blue));

      image[i][j].rgbtRed = (red > 255) ? 255 : red;
      image[i][j].rgbtGreen = (green > 255) ? 255 : green;
      image[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
    }
  }
}
