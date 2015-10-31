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

/* Global variable and function definitions */

#ifdef _MAIN
#define EXTERNAL 
#elif defined(_ALL)
#define EXTERNAL static
#else
#define EXTERNAL extern
#endif

# ifndef _GLOBAL_H
# define _GLOBAL_H

# include <values.h>


/* Global Constants */
# define INF MAXDOUBLE
# define EPS 1.0e-10
# define E  2.7182818284590452353602874713526625
# define PI 3.1415926535897932384626433832795029

/* Uncomment one of the lines corresponding to a particular function */
/* Function identifier */
/* # define f1 */
/* # define f2 */
/* # define f3 */
/* # define f4 */
/* # define f5 */
/* # define f6 */
/* # define f7 */
/* # define f8 */
/* # define f9 */
/* # define f10 */
# define f11
/* # define f12 */
/* # define f13 */
/* # define f14 */
/* # define f15 */
/* # define f16 */
/* # define f17 */
/* # define f18 */
/* # define f19 */
/* # define f20 */
/* # define f21 */
/* # define f22 */
/* # define f23 */
/* # define f24 */
/* # define f25 */

/* Global variables that you are required to initialize */
EXTERNAL int nreal;					/* number of real variables */
EXTERNAL int nfunc;					/* number of basic functions */
//EXTERNAL long double bound;			/* required for plotting the function profiles for nreal=2 */
//EXTERNAL int density;				/* density of grid points for plotting for nreal=2 */

/* Global variables being used in evaluation of various functions */
/* These are initalized in file def2.c */
EXTERNAL long double C;
EXTERNAL long double global_bias;
EXTERNAL long double *trans_x;
EXTERNAL long double *basic_f;
EXTERNAL long double *temp_x1;
EXTERNAL long double *temp_x2;
EXTERNAL long double *temp_x3;
EXTERNAL long double *temp_x4;
EXTERNAL long double *weight;
EXTERNAL long double *sigma;
EXTERNAL long double *lambda;
EXTERNAL long double *bias;
EXTERNAL long double *norm_x;
EXTERNAL long double *norm_f;
EXTERNAL long double **o;
EXTERNAL long double **g;
EXTERNAL long double ***l;

/* Auxillary function declarations */
long double maximum (long double, long double);
long double minimum (long double, long double);
long double modulus (long double*, int);
long double dot (long double*, long double*, int);
long double mean (long double*, int);

/* Basic funcion declarations */
long double calc_ackley (long double*);
long double calc_rastrigin (long double*);
long double calc_weierstrass (long double*);
long double calc_griewank (long double*);
long double calc_sphere (long double*);
long double calc_schwefel (long double*);
long double calc_rosenbrock (long double *x);
long double nc_schaffer (long double, long double);
long double nc_rastrigin (long double*);

/* Utility function declarations */
void allocate_memory();
void initialize();
void transform (long double*, int);
void transform_norm (int);
void calc_weight (long double*, int);
void free_memory();

/* Benchmark function declaration */
long double calc_benchmark_func (long double*);
void calc_benchmark_norm();

# endif
