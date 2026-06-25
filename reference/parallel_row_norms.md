# Row Euclidean Norms Computed in Parallel with OpenMP

Computes the Euclidean (L2) norm of each row of a numeric matrix, with
the rows divided across threads by *OpenMP*. The compiled routine is
reached from *R* through the *cpp11* package.

## Usage

``` r
parallel_row_norms(x)
```

## Arguments

- x:

  A `numeric` matrix.

## Value

A `numeric` vector with one entry per row of `x`, each the square root
of the sum of squares of that row.

## Examples

``` r
x = matrix(rnorm(20), nrow = 5)
parallel_row_norms(x)
#> [1] 2.656382 2.013038 3.204453 1.736271 1.250746
```
