#include <stdio.h>
#include <gsl/gsl_statistics.h>
#include <gsl/gsl_rng.h>

#define NUM 5

int main() {
  int i;
  double data[NUM];
  double mean, variance, largest, smallest;

  gsl_rng* r = gsl_rng_alloc(gsl_rng_default);
  for (i = 0; i < NUM; ++i) data[i] = gsl_rng_uniform(r);

  mean = gsl_stats_mean(data, 1, NUM);
  variance = gsl_stats_variance(data, 1, NUM);
  largest = gsl_stats_max(data, 1, NUM);
  smallest = gsl_stats_min(data, 1, NUM);

  printf("The data set is");
  for (i = 0; i < NUM; ++i) printf(" %6.3f", data[i]);
  printf("\n");

  printf("Mean:     %6.3f\n", mean);
  printf("Variance: %6.3f\n", variance);
  printf("Max value:%6.3f\n", largest);
  printf("Min value:%6.3f\n", smallest);

  return 0;
}
