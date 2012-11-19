#include <stdio.h>
#include <cblas.h>

double A[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };

double x[] = { 1.0, -1.0, 2.0 };
double y[] = { -1.0, 0.0, 2.0 };

int main() {
  int i;
  cblas_dgemv(CblasRowMajor, CblasNoTrans, 3, 3, 2.5, A, 3, x, 1, 1.2, y, 1);
  for (i = 0; i < 3; ++i) { printf("%6.1f\n", y[i]); }

  return 0;
}
