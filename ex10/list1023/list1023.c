#include <stdio.h>
#include <clapack.h>

double A[] =
{
  -1.0, 0.0, 2.0, 1.0,
  0.0, -1.0, 3.0, 2.0,
  1.0, 2.0,  3.0, 0.0,
  -3.0, 1.0, 4.0, 2.0
};

double y[] = { 0.0, 1.0, 2.0, 1.0 };

int main() {
  int i, ipiv[4];
  clapack_dgesv(CblasRowMajor, 4, 1, A, 4, ipiv, y, 4);
  for (i = 0; i < 4; ++i) {
    printf("%6.1f\n", y[i]);
  }

  return 0;
}
