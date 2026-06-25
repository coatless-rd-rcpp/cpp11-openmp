#include <cpp11.hpp>
#include <vector>
#include <cmath>

#ifdef _OPENMP
#include <omp.h>
#endif

// Compute the Euclidean (L2) norm of each row of a matrix, with the rows
// divided across threads by OpenMP. The result is built in a plain std::vector
// inside the parallel region and converted to an R vector afterwards, so the R
// API is never touched from inside the threads.
[[cpp11::register]]
cpp11::doubles cpp_row_norms(cpp11::doubles_matrix<> x) {
  int n = x.nrow();
  int p = x.ncol();
  std::vector<double> out(n);

  #pragma omp parallel for schedule(static)
  for (int i = 0; i < n; i++) {
    double ss = 0.0;
    for (int j = 0; j < p; j++) {
      double v = x(i, j);
      ss += v * v;
    }
    out[i] = std::sqrt(ss);
  }

  return cpp11::as_sexp(out);
}
