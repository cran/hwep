% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/bayes.R
\name{simgl}
\alias{simgl}
\title{Simulator for genotype likelihoods.}
\usage{
simgl(
  nvec,
  rdepth = 10,
  od = 0.01,
  bias = 1,
  seq = 0.01,
  ret = c("gl", "gp", "all"),
  est = FALSE,
  ...
)
}
\arguments{
\item{nvec}{The genotype counts. \code{nvec[k]} contains the number of
individuals with genotype \code{k-1}.}

\item{rdepth}{The read depth. Lower means more uncertain.}

\item{od}{The overdispersion parameter. Higher means more uncertain.}

\item{bias}{The allele bias parameter. Further from 1 means more bias.
Must greater than 0.}

\item{seq}{The sequencing error rate. Higher means more uncertain.}

\item{ret}{The return type. Should we just return the genotype
likelihoods (\code{"gl"}), just the genotype posteriors
(\code{"gp"}), or the entire updog output (\code{"all"})}

\item{est}{A logical. Estimate the updog likelihood parameters while
genotype (\code{TRUE}) or fix them at the true values (\code{FALSE})?
More realistic simulations would set this to \code{TRUE}, but it makes
the method much slower.}

\item{...}{Additional arguments to pass to
\code{\link[updog]{flexdog_full}()}.}
}
\value{
By default, a matrix. The genotype (natural) log likelihoods.
The rows index the individuals and the columns index the dosage. So
\code{gl[i,j]} is the genotype log-likelihood for individual i
at dosage j - 1.
}
\description{
Uses the {updog} R package for simulating read counts and generating
genotype log-likelihoods.
}
\examples{
set.seed(1)
simgl(c(1, 2, 1, 0, 0), model = "norm", est = TRUE)
simgl(c(1, 2, 1, 0, 0), model = "norm", est = FALSE)

}
\author{
David Gerard
}
