###########################
## Utility functions
###########################

#' Greatest common divisor
#'
#' @param x An integer
#' @param y Anothe rinteger
#'
#' @author David Gerard
#'
#' @examples
#' gcd(105, 168)
#'
#' @noRd
gcd <- function(x, y) {
  r <- x %% y
  return(ifelse(r > 0, gcd(y, r), y))
}


#' Use log-sum-exp trick on vector
#'
#' Calculates \deqn{\log(\sum_i\exp(x_i))}
#'
#' @param x A numeric. We want to sum the exponent of x, then log.
#' @param na.rm A logical. Should we remove \code{NA}'s (\code{TRUE}) or not
#'     (\code{FALSE})? Defaults to \code{FALSE}.
#'
#' @author David Gerard
#'
#' @noRd
log_sum_exp <- function(x, na.rm = FALSE) {
  stopifnot(is.numeric(x))
  stopifnot(is.logical(na.rm))
  stopifnot(length(na.rm) == 1)

  x_max <- max(x, na.rm = TRUE)
  if (x_max == -Inf) {
    return (-Inf)
  } else {
    return(log(sum(exp(x - x_max), na.rm = na.rm)) + x_max)
  }
}

logit <- function(x) {
  log(x) - log(1 - x)
}

expit <- function(x) {
  1 / (1 + exp(-x))
}


#' Function to aggregate groups.
#'
#' @param which_keep A logical vector. Should be \code{FALSE} if that
#'     group is being aggregated.
#'
#' @author David Gerard
#'
#' @noRd
aggfun <- function(which_keep) {
  stopifnot(is.logical(which_keep))
  ploidy <- length(which_keep) - 1
  numkeep <- sum(which_keep)
  if (numkeep >= ploidy) {
    H <- diag(ploidy + 1)
  } else {
    H <- matrix(0, nrow = numkeep + 1, ncol = ploidy + 1)
    j <- 1
    for (i in 0:ploidy) {
      if (which_keep[[i + 1]]) {
        H[j, i + 1] <- 1
        j <- j + 1
      } else {
        H[numkeep + 1, i + 1] <- 1
      }
    }
  }
  return(H)
}

#' Applies a transform from simplex to reals.
#'
#' Transform due to Betancourt (2012).
#'
#' @param q A point on the unit simplex.
#'
#' @references
#' \itemize{
#'   \item{Betancourt, M. (2012, May). Cruising the simplex:
#'         Hamiltonian Monte Carlo and the Dirichlet distribution.
#'         In AIP Conference Proceedings 31st (Vol. 1443, No. 1, pp. 157-164).
#'         American Institute of Physics. \doi{10.1063/1.3703631}}
#'   \item{\url{https://mc-stan.org/docs/2_18/reference-manual/simplex-transform-section.html}}
#' }
#'
#' @seealso \code{\link{real_to_simplex}()} for inverse.
#'
#' @author David Gerard
#'
#' @noRd
simplex_to_real <- function(q) {
  K <- length(q)
  stopifnot(K > 1)
  z <- q / (1 - c(0, cumsum(q)[-K]))
  y <- logit(z[-K]) - log(1 / (K - 1:(K-1)))
  return(y)
}

#' Applies a transform from reals to simplex
#'
#' Transform due to Betancourt (2012).
#'
#' @param y A point on the reals.
#'
#' @references
#' \itemize{
#'   \item{Betancourt, M. (2012, May). Cruising the simplex:
#'         Hamiltonian Monte Carlo and the Dirichlet distribution.
#'         In AIP Conference Proceedings 31st (Vol. 1443, No. 1, pp. 157-164).
#'         American Institute of Physics. \doi{10.1063/1.3703631}}
#'   \item{\url{https://mc-stan.org/docs/2_18/reference-manual/simplex-transform-section.html}}
#' }
#'
#' @seealso \code{\link{simplex_to_real}()} for inverse.
#'
#' @author David Gerard
#'
#' @noRd
real_to_simplex <- function(y) {
  stopifnot(length(y) > 0)
  K <- length(y) + 1
  z <- c(expit(y + log(1 / (K - 1:(K-1)))), 1)

  x <- rep(NA_real_, length.out = K)
  cumval <- 0
  for (i in seq_len(K)) {
    x[[i]] <- (1 - cumval) * z[[i]]
    cumval <- cumval + x[[i]]
  }

  return(x)
}



#' Choose which levels to aggregate
#'
#' @param x A non-negative numeric vector.
#' @param thresh A non-negative double. We aggregate when x < thresh
#' @param like Need a little adjustment for likelihood approach
#'
#' @return A logical vector. It will place a \code{FALSE} wherever we will
#'     aggregate those cells. It aggregates small cells until all cells have
#'     at least the threshhold.
#'
#' @author David Gerard
#'
#' @noRd
choose_agg <- function(x, thresh = 0, like = FALSE) {
  stopifnot(thresh >= 0, length(thresh) == 1)
  stopifnot(x >= 0)

  if (thresh == 0) {
    return(rep(TRUE, length.out = length(x)))
  }

  # all ok
  which_keep <- x >= thresh
  if (all(which_keep)) {
    return(rep(TRUE, length.out = length(x)))
  }

  if (all(!which_keep) & !like) {
    ibdr <- floor((length(x) - 1) / 4)
    which_keep <- rep(FALSE, length.out = length(x))
    which_keep[order(-x)][1:(ibdr + 1)] <- TRUE
    return(which_keep)
  } else if (all(!which_keep) & like) {
    ibdr <- floor((length(x) - 1) / 4)
    which_keep <- rep(FALSE, length.out = length(x))
    which_keep[order(-x)][1:(ibdr + 2)] <- TRUE
    return(which_keep)
  }

  # keep aggregating until done
  aggvec <- c(x[which_keep], sum(x[!which_keep]))
  while(any(aggvec < thresh)) {
    which_keep[which_keep][which.min(x[which_keep])] <- FALSE
    aggvec <- c(x[which_keep], sum(x[!which_keep]))
  }

  # aggregate as much as we can
  ibdr <- floor((length(x) - 1) / 4)
  if (sum(which_keep) < ibdr + 1 & !like) {
    which_keep <- rep(FALSE, length.out = length(x))
    which_keep[order(-x)][1:(ibdr + 1)] <- TRUE
  } else if (sum(which_keep) <= ibdr + 1 & like) {
    which_keep <- rep(FALSE, length.out = length(x))
    which_keep[order(-x)][1:(ibdr + 2)] <- TRUE
  }

  return(which_keep)
}


#' Get every possible non-negative tuple with of a given sum.
#'
#' The total number of rows is \code{choose(n = k + n - 1, k = k - 1)}.
#' This function uses recursion, so is not the most efficient.
#'
#' @param n Number of indistinguishable balls.
#' @param k Number of distinguishable bins.
#'
#' @return A matrix, rows index different possible multinomial counts,
#'    the columns index the bins.
#'
#' @author David Gerard
#'
#' @examples
#' n <- 5
#' k <- 3
#' all_multinom(n = n, k = k)
#' choose(n = n + k - 1, k = k - 1)
#'
#' @export
all_multinom <- function(n, k) {
  if (k == 0) {
    return(NULL)
  } else if (k == 1) {
    return(n)
  }

  mat_list <- list()
  for (i in 0:n) {
    mat_list[[i + 1]] <- cbind(i, all_multinom(n - i, k - 1))
  }

  mat <- do.call(what = rbind, args = mat_list)
  colnames(mat) <- NULL
  mat
}






