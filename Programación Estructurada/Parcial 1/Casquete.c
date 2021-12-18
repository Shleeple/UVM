#include <stdio.h>
#include <math.h>

// Area = 2pi * Radius of the sphere * height
// Volume = (pi * height^2 * (3R-h))/3
int main()
{
  double pi = 3.14159265;
  float h, R, V, A;
  printf("What's the radius of the sphere?\nWhat's the height of the casquete?\n");
  scanf("%f%f", &R, &h);
  A = 2*pi*R*h;
  V = ((pi)*(pow(h,2))*(3*R-h))/3;
  printf("The Area is: %f\n", A);
  printf("The Volume is: %f\n", V);
  return 0;
}
