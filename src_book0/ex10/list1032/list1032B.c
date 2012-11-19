#include <stdio.h>
#include <gsl/gsl_linalg.h>

double A[] =
{
  -1.0, 0.0, 2.0, 1.0,
  0.0, -1.0, 3.0, 2.0,
  1.0, 2.0, 3.0, 0.0,
  -3.0, 1.0, 4.0, 2.0
};

double y[] = { 0.0, 1.0, 2.0, 1.0 };

int main() {
  gsl_matrix_view m = gsl_matrix_view_array(A, 4, 4);
  gsl_vector_view b = gsl_vector_view_array(y, 4);
  gsl_vector* x = gsl_vector_alloc(4);

  int s;
  gsl_permutation* p = gsl_permutation_alloc(4);
  gsl_linalg_LU_decomp(&m.matrix, p, &s);
  gsl_linalg_LU_solve(&m.matrix, p, &b.vector, x);

  printf("x = \n");
  gsl_vector_fprintf(stdout, x, "%5.1f");

  gsl_permutation_free(p);
  gsl_vector_free(x);
  return 0;
}
