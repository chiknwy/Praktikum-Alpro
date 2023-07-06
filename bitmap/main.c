#include "stdio.h"

FILE *before;
FILE *after;
char buf[256];
char pixel[3];

int main()
{
  before = fopen("before.BMP", "rb");
  after = fopen("after.BMP", "wb");

  fread(buf, 1, 54, before);
  fwrite(buf, 1, 54, after);

  while (fread(pixel, 1, 3, before))
  {
    // Swap R to B and vice versa
    char temp = pixel[0];
    pixel[0] = pixel[2];
    pixel[2] = temp;
  
    for (int i = 0; i < 3; i++)
    {
      int value = pixel[i] + 55;  // Increase the brightness

      if (value > 255)
      {
        pixel[i] = 255;  // max the value to 255
      }
      else
      {
        pixel[i] = value;
      }
    }

    fwrite(pixel, 1, 3, after);
  }

  fclose(before);
  fclose(after);

  return 0;
}
