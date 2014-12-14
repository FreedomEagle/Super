/*
 * Using Monte Carlo integration to calculate the volume of a
 * superellipsoids in 5-dimensional space.
 */

#include <gsl/gsl_rng.h>
#include <math.h>

double mc_se(long m, int n, gsl_rng *r)
{
    double x, y, z, p, q;          /* five dimensional coordinate, all between 0 and 1  */
    long count = 0L;
    long i;
    
    for (i = 0; i < m; i++)
    {
                                 
        x = gsl_rng_uniform (r);    /* generate random coordinates */
        y = gsl_rng_uniform (r);
        z = gsl_rng_uniform (r);
        p = gsl_rng_uniform (r);
        q = gsl_rng_uniform (r);

                                  /*Equation for the volume of a superellipsoid*/
        if (( pow(x, (double) n) + pow(y, (double) n) + pow(z, (double) n)  
             +pow(p, (double) n) + pow(q, (double) n) ) < 1.0)         
        {
            count += 1;
        }
    }

    return (32 * ((double) count)/m);
}
