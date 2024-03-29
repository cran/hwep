## ---- include = FALSE---------------------------------------------------------
knitr::opts_chunk$set(
  collapse = TRUE,
  comment = "#>"
)
set.seed(997)

## ----setup--------------------------------------------------------------------
library(hwep)

## -----------------------------------------------------------------------------
drbounds(ploidy = 4)
drbounds(ploidy = 6)
drbounds(ploidy = 8)
drbounds(ploidy = 10)
drbounds(ploidy = 12)

## -----------------------------------------------------------------------------
dgamete(x = 0:2, alpha = 0.1, G = 3, ploidy = 4)

## -----------------------------------------------------------------------------
gsegmat(alpha = 0.1, ploidy = 4)

## -----------------------------------------------------------------------------
gsegmat(alpha = 0.1, ploidy = 4)[3, 2]

## -----------------------------------------------------------------------------
gsegmat_symb(ploidy = 4)

## -----------------------------------------------------------------------------
sega <- zsegarray(alpha = 0.1, ploidy = 4)
sega

## -----------------------------------------------------------------------------
sega[4, 3, 5]

## -----------------------------------------------------------------------------
hout <- hwefreq(r = 0.1, alpha = 0.1, ploidy = 6)
round(hout, digits = 5)

## -----------------------------------------------------------------------------
freqnext(freq = c(0.9, 0, 0, 0, 0.1), alpha = 0.1)

## -----------------------------------------------------------------------------
hwefreq(r = 0.1, alpha = 0.1, niter = 1, ploidy = 4)

## -----------------------------------------------------------------------------
library(future)
availableCores()
plan(multisession, workers = 2)

## -----------------------------------------------------------------------------
geno_freq <- hwefreq(r = 0.5, alpha = 0.1, ploidy = 6)
nmat <- t(rmultinom(n = 1000, size = 100, prob = geno_freq))
head(nmat)

## -----------------------------------------------------------------------------
uout <- hwefit(nmat = nmat, type = "ustat")

## -----------------------------------------------------------------------------
mean(uout$alpha1)

## -----------------------------------------------------------------------------
hist(uout$alpha1)

## -----------------------------------------------------------------------------
hist(uout$p_hwe, breaks = 10, xlab = "P-values", main = "")
qqplot(x = ppoints(length(uout$p_hwe)), 
       y = uout$p_hwe, 
       xlab = "Theoretical Quantiles",
       ylab = "Empirical Quantiles",
       main = "QQ-plot")
abline(0, 1, lty = 2, col = 2)

## -----------------------------------------------------------------------------
qqpvalue(pvals = uout$p_hwe, method = "base")

## -----------------------------------------------------------------------------
plan("sequential")

