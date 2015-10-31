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

/**
 * Interfaz para el resto del programa
 */

#define _ALL

#include <assert.h>
#include <string>
#include "global.h"
#include "sub.h"

#include "def1.cc"
#include "def2.cc"
#include "def3.cc"
#include "def4.cc"
#include "aux.cc"
#include "srandom.cc"
#include "random.cc"
#include "rand.cc"

using namespace std;

bool isBound_cec2005(void) {
    if (nfunc != 7 && nfunc != 25) {
	return true;
    }
    else {
	return false;
    }
}

void init_cec2005(int fun, int dim) {
    // Asigno valor a las variables
    nfunc = fun;
    nreal = dim;
   
    if (nfunc<1)
    {
        fprintf(stderr,"\n Wrong value of 'nfun' entered\n");
        exit(0);
    }
    if (nreal!=2 && nreal!=10 && nreal!=30 && nreal!=50)
    {
        fprintf(stderr,"\n Wrong value of 'nreal' entered, only 2, 10, 30, 50 variables are supported\n");
        exit(0);
    }

    /* Call these routines to initialize random number generator */
    /* require for computing noise in some test problems */
    randomize();
    initrandomnormaldeviate();

    /* nreal and nfun need to be initialized before calling these routines */
    /* Routine to allocate memory to global variables */
    allocate_memory();

    /* Routine the initalize global variables */
    initialize();
}



void finish_cec2005(void) {
   free_memory();
}

struct CECFUNCTION {
   int ident; 		/**< Parámetro identificador de la función */
   string name; 	/**< Nombre de la función (para poder mostrarla en pantalla */
   double range[2];	        /**< Guarda los valores mínimos y máximos para dicha función */
   double optime;    	/**< Valor óptimo */
};

static CECFUNCTION cec2005Fun[] = {
	{1, "Shifted Sphere Function", {-100, 100}, -450},
	{2, "Shifted Schwefel's Problem 1.2", {-100, 100}, -450},
	{3, "Shifted Rotated High Conditioned Elliptic Function", {-100, 100}, -450},
	{4, "Shifted Schwefel's Problem 1.2 with Noise in Fitness", {-100, 100}, -450},
	{5, "Schwefel's Problem 2.6 with Global Optimum on Bounds", {-100, 100}, -310},
	{6, "Shifted Rosenbrock's Function", {-100, 100}, 390}, 
	{7, "Shifted Rotated Griewnk's Function without Bounds", {0, 600}, -180},
	{8, "Shifted Rotated Ackley's Function with Global Optimum on Bounds", {-32, 32}, -140}, 
	{9, "Shifted Rastrigin's Function", {-5, 5}, -330}, 
	{10, "Shifted Rotated Rastrigin's Function", {-5, 5}, -330}, 
	{11, "Shifted Rotated Weierstrass Function", {-0.5, 0.5}, 90}, 
	{12, "Schwefel's Problem 2.13", {-PI, PI}, -460}, 
	{13, "Expanded Functions", {-5, 5}, -130}, 
	{14, "Shifted Rotated Expanded Scaffer's F6 Function", {-100, 100}, -300}, 
	{15, "Hybrid Composition Function 1", {-5, 5}, 120}, 
	{16, "Rotated Hybrid Composition Function 1", {-5, 5}, 120}, 
	{17, "Rotated Hybrid Composition Function 1 with Noise in Fitness", {-5, 5}, 120}, 
	{18, "Rotated Hybrid Composition Function 2", {-5, 5}, 10}, 
	{19, "Rotated Hybrid Composition Function 2 with Narrow Basin Global Optimum", {-5, 5}, 10}, 
	{20, "Rotated Hybrid Composition Function 2 with Global Optimum on the Bounds", {-5, 5}, 10}, 
	{21, "Rotated Hybrid Composition Function 3", {-5, 5}, 360}, 
	{22, "Rotated Hybrid Composition Function 3 with High Condition Number Matrix", {-5, 5}, 360}, 
	{23, "Non-Continuous Rotated Hybrid Composition Function 3", {-5, 5}, 360}, 
	{24, "Rotated Hybrid Composition Function 4", {-5, 5}, 260}, 
	{25, "Rotated Hybrid Composition Function 4 without Bounds", {2, 5}, 260}
};

static int cec2005FunSize = 25;

/**
 * Permite obtener la información sobre la función
 */
void getInfo_cec2005(int fun, char *name, double *min, double *max, double *optime) {
   int id;

   // Compruebo el rango
   assert(fun >= 0 && fun <= cec2005FunSize);

   id = fun-1;

   strcpy(name, cec2005Fun[id].name.c_str());
   *min = cec2005Fun[id].range[0];
   *max = cec2005Fun[id].range[1];
   *optime = cec2005Fun[id].optime;
}

/**
 * La función eval del CEC2005
 */
double eval_cec2005(const long double *x, int ndim) {
    double optime = cec2005Fun[nfunc-1].optime;
    long double *y = (long double*) x;
    double fit = calc_benchmark_func(y)-optime;
    assert(fit >= 0);
    return fit;
}

double eval_cec2005(const double *x, int ndim) {
    double optime = cec2005Fun[nfunc-1].optime;
    long double y[ndim];

    for (int i = 0; i < ndim; ++i) {
	y[i] = x[i];
    }

    double fit = calc_benchmark_func(y)-optime;

    if (fit < 0) {
	fprintf(stderr, "Value: %le\tOptime: %le\n", fit, optime);
    }

    assert(fit >= 0);
    return fit;
}
