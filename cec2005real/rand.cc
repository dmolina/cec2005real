/**
 * Copyright 2008, Daniel Molina Cabrera
 * 
 * This file is part of software Realea
 * 
 * Realea is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Realea is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Definition of random number generation routines */
/* This file now acts as a wrapper for the sprng random number generator */
/* Web-site of SPRNG is http://sprng.cs.fsu.edu */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
#include "random.h"
#include "srandom.h"

static Random *m_random;
/* Variable declarations for the random number generator */
int rndcalcflag;
long double rndx1, rndx2;


/* Get seed number for random and start it up */
void randomize()
{
    m_random = new Random(new SRandom(1234579));
}

/* Fetch a single random number between 0.0 and 1.0 */
long double randomperc()
{
      return m_random->rand();
}

/* Fetch a single random integer between low and high including the bounds */
int rnd (int low, int high)
{
    int res;
    if (low >= high)
    {
        res = low;
    }
    else
    {
        res = (int) (low + (randomperc()*(high-low+1)));
        if (res > high)
        {
            res = high;
        }
    }
    return (res);
}

/* Fetch a single random real number between low and high including the bounds */
long double rndreal (long double low, long double high)
{
    return (low + (high-low)*randomperc());
}

/* Initialize the randome generator for normal distribution */
void initrandomnormaldeviate()
{
    rndcalcflag = 1;
    return;
}

/* Return the noise value */
long double noise (long double mu, long double sigma)
{
    return((randomnormaldeviate()*sigma) + mu);
}

/* Compute the noise */
long double randomnormaldeviate()
{
    long double t;
    if(rndcalcflag)
    {
        rndx1 = sqrt(- 2.0*log(randomperc()));
        t = 6.2831853072*randomperc();
        rndx2 = sin(t);
        rndcalcflag = 0;
        return(rndx1*cos(t));
    }
    else
    {
        rndcalcflag = 1;
        return(rndx1*rndx2);
    }
}
