#include <iostream>
#include <math.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: " << argv[0] << " ZOOMFACTOR" << std::endl;
  }
  else
  {
    int width = 640;
    int height = 480;

    double z = atof(argv[1]);
    int color = 15;

    std::cout << "P2\n"
              << "# comment\n"
              << width << " " << height << "\n"
              << "255\n";

    for(int y = 1; y < height; ++y)
    {
      for(int x = 0; x < width; ++x)
      {
        double px = sinf((x * z) * (y * z));
        std::cout << static_cast<int>(((px + 1.0)/2.0) * 255) << " ";
      }
    }
    std::cout << std::endl;
  }
}

/* EOF */
