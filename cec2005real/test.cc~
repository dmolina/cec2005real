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

/* Sample main to demonstrate the use of various functions */
/* Please go through this file carefully */
/* It demonstrates the use of various routines */

# include <stdio.h>
# include <stdlib.h>

#define _MAIN

#include "cec2005.h"
#include "random.h"
#include "srandom.h"

int main (int argc, char**argv)
{
    int i;
    long double *x;
    long double f;
    Random random(new SRandom(12345679));

    if (argc<3)
    {
        fprintf(stderr,"\n Usage ./%s nfunc nreal\n", argv[0]);
        exit(0);
    }

	/* Assign nfunc and nreal in the begining */
    int nfunc = (int)atoi(argv[1]);
    int nreal = (int)atoi(argv[2]);

	if (nfunc<1)
    {
        fprintf(stderr,"\n Wrong value of 'nfunc' entered\n");
        exit(0);
    }
    if (nreal!=2 && nreal!=10 && nreal!=30 && nreal!=50)
    {
        fprintf(stderr,"\n Wrong value of 'nreal' entered, only 2, 10, 30, 50 variables are supported\n");
        exit(0);
    }
    printf("\n Number of basic functions = %d",nfunc);
    printf("\n Number of real variables  = %d",nreal);

    init_cec2005(&random, nfunc, nreal);

	/* Variable vector */
	x = (long double *)malloc(nreal*sizeof(long double));

	for (i=0; i<nreal; i++)
	{
		printf("\n Enter the value of variable x[%d] : ",i+1);
		scanf("%Lf",&x[i]);
	}

	f = eval_cec2005( (const tGen *) x, nreal);
	printf("\n Objective value = %1.15LE",f);

	/* Routine to free the memory allocated at run time */
	finish_cec2005();

    printf("\nRoutine exited without any error.\n");
    return(1);
}
