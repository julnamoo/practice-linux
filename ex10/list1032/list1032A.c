#include <stdio.h>
#include <gsl/gsl_poly.h>

int main() {
  double a = 1.0, b = -3.0, c = 2.0;
  double x0 = 0.0, x1 = 0.0;
  gsl_poly_solve_quadratic(a, b, c, &x0, &x1);
  printf("%4.1fx^2 + %4.1fx + %4.1f = 0 -> x = %4.1f, %4.1f\n",
      a, b, c, x0, x1);
  return 0;
}
