#' Row Euclidean Norms Computed in Parallel with OpenMP
#'
#' Computes the Euclidean (L2) norm of each row of a numeric matrix, with the
#' rows divided across threads by _OpenMP_. The compiled routine is reached from
#' _R_ through the _cpp11_ package.
#'
#' @param x A `numeric` matrix.
#'
#' @return
#' A `numeric` vector with one entry per row of `x`, each the square root of the
#' sum of squares of that row.
#'
#' @export
#' @examples
#' x = matrix(rnorm(20), nrow = 5)
#' parallel_row_norms(x)
parallel_row_norms <- function(x) {
  storage.mode(x) <- "double"
  cpp_row_norms(x)
}
