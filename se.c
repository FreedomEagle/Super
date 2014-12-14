/* 
 *Analysis of statistical errors of Monte Carlo Calculation for the Volume of a Superellipsoid.
 */
#include <stdio.h>                          /*Including necessay Libraries*/
#include <gsl/gsl_rng.h>
#include <gsl/gsl_statistics.h>

double mc_se(long m, int n, gsl_rng * r);

#define POINTS 400000
#define NEXP 60                             /* number of experiments for each value of points */

int main (void)
{
    double vol[NEXP];                        /* calculated values of pi */
    gsl_rng *r;
    double mean, sd;
    int j, n;
    unsigned long seed = 1UL;
    long p = POINTS;

    r = gsl_rng_alloc (gsl_rng_taus2);        /* allocate random number generator */  
    gsl_rng_set (r, seed);                    /* seed the random number generator */
                                  
   
    for (n = 1; n < 10; n++)
    {
        for (j = 0; j < NEXP; j++)
        {
            /* calculate pi using Monte Carlo algorithm */
            vol[j] = mc_se (p, n, r);
        }
        mean = gsl_stats_mean (vol, 1, NEXP);
        sd = gsl_stats_sd_m (vol, 1, NEXP, mean);
        printf (" %5d   %14.8f   %13.8f\n", n, mean, sd);
    }

    gsl_rng_free (r);

    return (0);
}
