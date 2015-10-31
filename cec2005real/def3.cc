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

/* Source file for custom initialization */
/* Hard-coded for every function based on the type and nature of input files */
/* At present hard-coded for D=2, 10, 30 and 50 */

# include <stdio.h>
# include <stdlib.h>
#include <string.h>
# include <math.h>

# include "global.h"
# include "sub.h"
# include "rand.h"

void calc_benchmark_norm_f15();
void calc_benchmark_norm_f16();
void calc_benchmark_norm_f17();
void calc_benchmark_norm_f18();
void calc_benchmark_norm_f19();
void calc_benchmark_norm_f20();
void calc_benchmark_norm_f21();
void calc_benchmark_norm_f22();
void calc_benchmark_norm_f23();
void calc_benchmark_norm_f24();
void calc_benchmark_norm_f25();

static char *dirname;

void set_directory(char *dir) {
  dirname = dir;
}

FILE *myopen(const char *file, const char *mode) {
    FILE *fpt;
    fpt = fopen(file,mode);

    if (fpt == NULL) {
        char fname[500];
	sprintf(fname, "%s/%s", dirname, file);
	fpt = fopen(fname, mode);
    }

    return fpt;
}


void initialize_f1()
{
    int i, j;
    FILE *fpt;
    fpt = myopen("sphere_func_data.txt","r");

    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -450.0;
    return;
}

void initialize_f2()
{
    int i, j;
    FILE *fpt;
    fpt = myopen("schwefel_102_data.txt","r");

    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -450.0;
    return;
}

void initialize_f3()
{
    int i, j;
    FILE *fpt;
    if (nreal==2) fpt = myopen("elliptic_M_D2.txt","r");
    if (nreal==10) fpt = myopen("elliptic_M_D10.txt","r");
    if (nreal==30) fpt = myopen("elliptic_M_D30.txt","r");
    if (nreal==50) fpt = myopen("elliptic_M_D50.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nreal; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&g[i][j]);
//	    printf("\n G[%d][%d] = %LE",i+1,j+1,g[i][j]);
        }
    }
    fclose(fpt);
    fpt = myopen("high_cond_elliptic_rot_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -450.0;
    return;
}

void initialize_f4()
{
    int i, j;
    FILE *fpt;
    fpt = myopen("schwefel_102_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -450.0;
    return;
}

void initialize_f5()
{
    int i, j;
    int index;
    FILE *fpt;
    char c;
    Af5 = (long double **)malloc(nreal*sizeof(long double));
    for (i=0; i<nreal; i++)
    {
        Af5[i] = (long double *)malloc(nreal*sizeof(long double));
    }
    Bf5 = (long double *)malloc(nreal*sizeof(long double));
    fpt = myopen("schwefel_206_data.txt","r");
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
    }
    for (i=0; i<nreal; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&Af5[i][j]);
//            printf("\n A[%d][%d] = %LE",i+1,j+1,A[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
    }
    fclose(fpt);
    if (nreal%4==0)
    {
        index = nreal/4;
    }
    else
    {
        index = nreal/4 + 1;
    }
    for (i=0; i<index; i++)
    {
        o[0][i] = -100.0;
    }
    index = (3*nreal)/4 - 1;
    for (i=index; i<nreal; i++)
    {
        o[0][i] = 100.0;
    }
    for (i=0; i<nreal; i++)
    {
        Bf5[i] = 0.0;
        for (j=0; j<nreal; j++)
        {
            Bf5[i] += Af5[i][j]*o[0][j];
        }
    }
    bias[0] = -310.0;
    return;
}

void initialize_f6()
{
    int i, j;
    FILE *fpt;
    fpt = myopen("rosenbrock_func_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
            o[i][j] -= 1.0;
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = 390.0;
    return;
}

void initialize_f7()
{
    int i, j;
    FILE *fpt;
    if (nreal==2)    fpt = myopen("griewank_M_D2.txt","r");
    if (nreal==10)    fpt = myopen("griewank_M_D10.txt","r");
    if (nreal==30)    fpt = myopen("griewank_M_D30.txt","r");
    if (nreal==50)    fpt = myopen("griewank_M_D50.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nreal; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&g[i][j]);
//            printf("\n G[%d][%d] = %LE",i+1,j+1,g[i][j]);
        }
    }
    fclose(fpt);
    fpt = myopen("griewank_func_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -180.0;
    return;
}

void initialize_f8()
{
    int i, j;
    int index;
    FILE *fpt;
    if (nreal==2)    fpt = myopen("ackley_M_D2.txt","r");
    if (nreal==10)    fpt = myopen("ackley_M_D10.txt","r");
    if (nreal==30)    fpt = myopen("ackley_M_D30.txt","r");
    if (nreal==50)    fpt = myopen("ackley_M_D50.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nreal; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&g[i][j]);
//            printf("\n M[%d][%d] = %LE",i+1,j+1,g[i][j]);
        }
    }
    fclose(fpt);
    fpt = myopen("ackley_func_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
    }
    fclose(fpt);
    index = nreal/2;
    for (i=1; i<=index; i++)
    {
        o[0][2*i-2] = -32.0;
    }
    bias[0] = -140.0;
    return;
}

void initialize_f9()
{
    int i, j;
    FILE *fpt;
    fpt = myopen("rastrigin_func_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -330.0;
    return;
}

void initialize_f10()
{
    int i, j;
    FILE *fpt;
    if (nreal==2)    fpt = myopen("rastrigin_M_D2.txt","r");
    if (nreal==10)    fpt = myopen("rastrigin_M_D10.txt","r");
    if (nreal==30)    fpt = myopen("rastrigin_M_D30.txt","r");
    if (nreal==50)    fpt = myopen("rastrigin_M_D50.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nreal; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&g[i][j]);
//            printf("\n M[%d][%d] = %LE",i+1,j+1,g[i][j]);
        }
    }
    fclose(fpt);
    fpt = myopen("rastrigin_func_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -330.0;
    return;
}

void initialize_f11()
{
    int i, j;
    FILE *fpt;
    if (nreal==2)    fpt = myopen("weierstrass_M_D2.txt","r");
    if (nreal==10)    fpt = myopen("weierstrass_M_D10.txt","r");
    if (nreal==30)    fpt = myopen("weierstrass_M_D30.txt","r");
    if (nreal==50)    fpt = myopen("weierstrass_M_D50.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nreal; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&g[i][j]);
//            printf("\n M[%d][%d] = %LE",i+1,j+1,g[i][j]);
        }
    }
    fclose(fpt);
    fpt = myopen("weierstrass_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = 90.0;
    return;
}

void initialize_f12()
{
    int i, j;
    FILE *fpt;
    char c;
    Af12 = (long double **)malloc(nreal*sizeof(long double));
    Bf12 = (long double **)malloc(nreal*sizeof(long double));
    alphaf12 = (long double *)malloc(nreal*sizeof(long double));
    for (i=0; i<nreal; i++)
    {
        Af12[i] = (long double *)malloc(nreal*sizeof(long double));
        Bf12[i] = (long double *)malloc(nreal*sizeof(long double));
    }
    fpt = myopen("schwefel_213_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    /* Reading A */
    for (i=0; i<nreal; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&Af12[i][j]);
//            printf("\n Af12[%d][%d] = %LE",i+1,j+1,Af12[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
    }
    if (i!=100)
    {
        for (i=nreal; i<100; i++)
        {
            do
            {
                fscanf(fpt,"%c",&c);
            }
            while(c!='\n');
        }
    }
    /* Reading B */
    for (i=0; i<nreal; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&Bf12[i][j]);
//            printf("\n B[%d][%d] = %LE",i+1,j+1,B[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
    }
    if (i!=100)
    {
        for (i=nreal; i<100; i++)
        {
            do
            {
                fscanf(fpt,"%c",&c);
            }
            while(c!='\n');
        }
    }
    /* Reading alpha */
    for (i=0; i<nreal; i++)
    {
        fscanf(fpt,"%Lf",&alphaf12[i]);
//        printf("\n alpha[%d] = %LE",i+1,alpha[i]);
    }
    fclose(fpt);
    bias[0] = -460.0;
    return;
}

void initialize_f13()
{
    int i, j;
    FILE *fpt;
    fpt = myopen("EF8F2_func_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
            o[i][j] -= 1.0;
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -130.0;
    return;
}

void initialize_f14()
{
    int i, j;
    FILE *fpt;
    if (nreal==2)    fpt = myopen("E_ScafferF6_M_D2.txt","r");
    if (nreal==10)    fpt = myopen("E_ScafferF6_M_D10.txt","r");
    if (nreal==30)    fpt = myopen("E_ScafferF6_M_D30.txt","r");
    if (nreal==50)    fpt = myopen("E_ScafferF6_M_D50.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nreal; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&g[i][j]);
//            printf("\n M[%d][%d] = %LE",i+1,j+1,g[i][j]);
        }
    }
    fclose(fpt);
    fpt = myopen("E_ScafferF6_func_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -300.0;
    return;
}

void initialize_f15()
{
    int i, j;
    FILE *fpt;
    char c;
    fpt = myopen("hybrid_func1_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
//        printf("\n");
    }
    fclose(fpt);
    lambda[0] = 1.0;
    lambda[1] = 1.0;
    lambda[2] = 10.0;
    lambda[3] = 10.0;
    lambda[4] = 1.0/12.0;
    lambda[5] = 1.0/12.0;
    lambda[6] = 5.0/32.0;
    lambda[7] = 5.0/32.0;
    lambda[8] = 1.0/20.0;
    lambda[9] = 1.0/20.0;
    global_bias = 120.0;
    return;
}

void initialize_f16()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = myopen("hybrid_func1_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
//        printf("\n");
    }
    fclose(fpt);
    if (nreal==2)    fpt = myopen("hybrid_func1_M_D2.txt","r");
    if (nreal==10)    fpt = myopen("hybrid_func1_M_D10.txt","r");
    if (nreal==30)    fpt = myopen("hybrid_func1_M_D30.txt","r");
    if (nreal==50)    fpt = myopen("hybrid_func1_M_D50.txt","r");
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            for (k=0; k<nreal; k++)
            {
                fscanf(fpt,"%Lf",&l[i][j][k]);
//                printf("\n M[%d][%d][%d] = %LE",i+1,j+1,k+1,l[i][j][k]);
            }
            do
            {
                fscanf(fpt,"%c",&c);
            }
            while (c!='\n');
        }
//        printf("\n");
    }
    lambda[0] = 1.0;
    lambda[1] = 1.0;
    lambda[2] = 10.0;
    lambda[3] = 10.0;
    lambda[4] = 1.0/12.0;
    lambda[5] = 1.0/12.0;
    lambda[6] = 5.0/32.0;
    lambda[7] = 5.0/32.0;
    lambda[8] = 1.0/20.0;
    lambda[9] = 1.0/20.0;
    global_bias = 120.0;
    return;
}

void initialize_f17()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = myopen("hybrid_func1_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
//        printf("\n");
    }
    fclose(fpt);
    if (nreal==2)    fpt = myopen("hybrid_func1_M_D2.txt","r");
    if (nreal==10)    fpt = myopen("hybrid_func1_M_D10.txt","r");
    if (nreal==30)    fpt = myopen("hybrid_func1_M_D30.txt","r");
    if (nreal==50)    fpt = myopen("hybrid_func1_M_D50.txt","r");
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            for (k=0; k<nreal; k++)
            {
                fscanf(fpt,"%Lf",&l[i][j][k]);
//                printf("\n M[%d][%d][%d] = %LE",i+1,j+1,k+1,l[i][j][k]);
            }
            do
            {
                fscanf(fpt,"%c",&c);
            }
            while (c!='\n');
        }
//        printf("\n");
    }
    lambda[0] = 1.0;
    lambda[1] = 1.0;
    lambda[2] = 10.0;
    lambda[3] = 10.0;
    lambda[4] = 1.0/12.0;
    lambda[5] = 1.0/12.0;
    lambda[6] = 5.0/32.0;
    lambda[7] = 5.0/32.0;
    lambda[8] = 1.0/20.0;
    lambda[9] = 1.0/20.0;
    global_bias = 120.0;
    return;
}

void initialize_f18()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = myopen("hybrid_func2_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
//        printf("\n");
    }
    fclose(fpt);

/**
 * Daniel: Arreglado errror
 */
    for (j = 0; j < nreal; j++) {
	o[9][j] = 0.0;
    }

    if (nreal==2)    fpt = myopen("hybrid_func2_M_D2.txt","r");
    if (nreal==10)    fpt = myopen("hybrid_func2_M_D10.txt","r");
    if (nreal==30)    fpt = myopen("hybrid_func2_M_D30.txt","r");
    if (nreal==50)    fpt = myopen("hybrid_func2_M_D50.txt","r");
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            for (k=0; k<nreal; k++)
            {
                fscanf(fpt,"%Lf",&l[i][j][k]);
//                printf("\n M[%d][%d][%d] = %LE",i+1,j+1,k+1,l[i][j][k]);
            }
            do
            {
                fscanf(fpt,"%c",&c);
            }
            while (c!='\n');
        }
//        printf("\n");
    }
    for (i=0; i<nreal; i++)
    {
        o[nfunc-1][i] = 0.0;
    }
    sigma[0] = 1.0;
    sigma[1] = 2.0;
    sigma[2] = 1.5;
    sigma[3] = 1.5;
    sigma[4] = 1.0;
    sigma[5] = 1.0;
    sigma[6] = 1.5;
    sigma[7] = 1.5;
    sigma[8] = 2.0;
    sigma[9] = 2.0;
    lambda[0] = 5.0/16.0;
    lambda[1] = 5.0/32.0;
    lambda[2] = 2.0;
    lambda[3] = 1.0;
    lambda[4] = 1.0/10.0;
    lambda[5] = 1.0/20.0;
    lambda[6] = 20.0;
    lambda[7] = 10.0;
    lambda[8] = 1.0/6.0;
    lambda[9] = 1.0/12.0;
    global_bias = 10.0;
    return;
}

void initialize_f19()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = myopen("hybrid_func2_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
//        printf("\n");
    }
    fclose(fpt);

/**
 * Daniel: Arreglado errror
 */
    for (j = 0; j < nreal; j++) {
	o[9][j] = 0.0;
    }

    if (nreal==2)    fpt = myopen("hybrid_func2_M_D2.txt","r");
    if (nreal==10)    fpt = myopen("hybrid_func2_M_D10.txt","r");
    if (nreal==30)    fpt = myopen("hybrid_func2_M_D30.txt","r");
    if (nreal==50)    fpt = myopen("hybrid_func2_M_D50.txt","r");
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            for (k=0; k<nreal; k++)
            {
                fscanf(fpt,"%Lf",&l[i][j][k]);
//                printf("\n M[%d][%d][%d] = %LE",i+1,j+1,k+1,l[i][j][k]);
            }
            do
            {
                fscanf(fpt,"%c",&c);
            }
            while (c!='\n');
        }
//        printf("\n");
    }
    for (i=0; i<nreal; i++)
    {
        o[nfunc-1][i] = 0.0;
    }
    sigma[0] = 0.1;
    sigma[1] = 2.0;
    sigma[2] = 1.5;
    sigma[3] = 1.5;
    sigma[4] = 1.0;
    sigma[5] = 1.0;
    sigma[6] = 1.5;
    sigma[7] = 1.5;
    sigma[8] = 2.0;
    sigma[9] = 2.0;
    lambda[0] = 0.5/32.0;
    lambda[1] = 5.0/32.0;
    lambda[2] = 2.0;
    lambda[3] = 1.0;
    lambda[4] = 1.0/10.0;
    lambda[5] = 1.0/20.0;
    lambda[6] = 20.0;
    lambda[7] = 10.0;
    lambda[8] = 1.0/6.0;
    lambda[9] = 1.0/12.0;
    global_bias = 10.0;
    return;
}

void initialize_f20()
{
    int i, j, k;
    int index;
    FILE *fpt;
    char c;
    fpt = myopen("hybrid_func2_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
//        printf("\n");
    }
    fclose(fpt);

/**
 * Daniel: Arreglado errror
 */
    for (j = 0; j < nreal; j++) {
	o[9][j] = 0.0;
    }

    index = nreal/2;
    for (i=1; i<=index; i++)
    {
        o[0][2*i-1] = 5.0;
    }
    if (nreal==2)    fpt = myopen("hybrid_func2_M_D2.txt","r");
    if (nreal==10)    fpt = myopen("hybrid_func2_M_D10.txt","r");
    if (nreal==30)    fpt = myopen("hybrid_func2_M_D30.txt","r");
    if (nreal==50)    fpt = myopen("hybrid_func2_M_D50.txt","r");
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            for (k=0; k<nreal; k++)
            {
                fscanf(fpt,"%Lf",&l[i][j][k]);
//                printf("\n M[%d][%d][%d] = %LE",i+1,j+1,k+1,l[i][j][k]);
            }
            do
            {
                fscanf(fpt,"%c",&c);
            }
            while (c!='\n');
        }
//        printf("\n");
    }
    for (i=0; i<nreal; i++)
    {
        o[nfunc-1][i] = 0.0;
    }
    sigma[0] = 1.0;
    sigma[1] = 2.0;
    sigma[2] = 1.5;
    sigma[3] = 1.5;
    sigma[4] = 1.0;
    sigma[5] = 1.0;
    sigma[6] = 1.5;
    sigma[7] = 1.5;
    sigma[8] = 2.0;
    sigma[9] = 2.0;
    lambda[0] = 5.0/16.0;
    lambda[1] = 5.0/32.0;
    lambda[2] = 2.0;
    lambda[3] = 1.0;
    lambda[4] = 1.0/10.0;
    lambda[5] = 1.0/20.0;
    lambda[6] = 20.0;
    lambda[7] = 10.0;
    lambda[8] = 1.0/6.0;
    lambda[9] = 1.0/12.0;
    global_bias = 10.0;
    return;
}

void initialize_f21()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = myopen("hybrid_func3_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
//        printf("\n");
    }
    fclose(fpt);
    if (nreal==2)    fpt = myopen("hybrid_func3_M_D2.txt","r");
    if (nreal==10)    fpt = myopen("hybrid_func3_M_D10.txt","r");
    if (nreal==30)    fpt = myopen("hybrid_func3_M_D30.txt","r");
    if (nreal==50)    fpt = myopen("hybrid_func3_M_D50.txt","r");
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            for (k=0; k<nreal; k++)
            {
                fscanf(fpt,"%Lf",&l[i][j][k]);
//                printf("\n M[%d][%d][%d] = %LE",i+1,j+1,k+1,l[i][j][k]);
            }
            do
            {
                fscanf(fpt,"%c",&c);
            }
            while (c!='\n');
        }
//        printf("\n");
    }
    sigma[0] = 1.0;
    sigma[1] = 1.0;
    sigma[2] = 1.0;
    sigma[3] = 1.0;
    sigma[4] = 1.0;
    sigma[5] = 2.0;
    sigma[6] = 2.0;
    sigma[7] = 2.0;
    sigma[8] = 2.0;
    sigma[9] = 2.0;
    lambda[0] = 1.0/4.0;
    lambda[1] = 1.0/20.0;
    lambda[2] = 5.0;
    lambda[3] = 1.0;
    lambda[4] = 5.0;
    lambda[5] = 1.0;
    lambda[6] = 50.0;
    lambda[7] = 10.0;
    lambda[8] = 1.0/8.0;
    lambda[9] = 1.0/40.0;
    global_bias = 360.0;
    return;
}

void initialize_f22()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = myopen("hybrid_func3_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
//        printf("\n");
    }
    fclose(fpt);
    if (nreal==2)    fpt = myopen("hybrid_func3_HM_D2.txt","r");
    if (nreal==10)    fpt = myopen("hybrid_func3_HM_D10.txt","r");
    if (nreal==30)    fpt = myopen("hybrid_func3_HM_D30.txt","r");
    if (nreal==50)    fpt = myopen("hybrid_func3_HM_D50.txt","r");
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            for (k=0; k<nreal; k++)
            {
                fscanf(fpt,"%Lf",&l[i][j][k]);
              //  printf("\n M[%d][%d][%d] = %LE",i+1,j+1,k+1,l[i][j][k]);
            }
            do
            {
                fscanf(fpt,"%c",&c);
            }
            while (c!='\n');
        }
//        printf("\n");
    }
    sigma[0] = 1.0;
    sigma[1] = 1.0;
    sigma[2] = 1.0;
    sigma[3] = 1.0;
    sigma[4] = 1.0;
    sigma[5] = 2.0;
    sigma[6] = 2.0;
    sigma[7] = 2.0;
    sigma[8] = 2.0;
    sigma[9] = 2.0;
    lambda[0] = 1.0/4.0;
    lambda[1] = 1.0/20.0;
    lambda[2] = 5.0;
    lambda[3] = 1.0;
    lambda[4] = 5.0;
    lambda[5] = 1.0;
    lambda[6] = 50.0;
    lambda[7] = 10.0;
    lambda[8] = 1.0/8.0;
    lambda[9] = 1.0/40.0;
    global_bias = 360.0;
    return;
}

void initialize_f23()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = myopen("hybrid_func3_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
//        printf("\n");
    }
    fclose(fpt);
    if (nreal==2)    fpt = myopen("hybrid_func3_M_D2.txt","r");
    if (nreal==10)    fpt = myopen("hybrid_func3_M_D10.txt","r");
    if (nreal==30)    fpt = myopen("hybrid_func3_M_D30.txt","r");
    if (nreal==50)    fpt = myopen("hybrid_func3_M_D50.txt","r");
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            for (k=0; k<nreal; k++)
            {
                fscanf(fpt,"%Lf",&l[i][j][k]);
//                printf("\n M[%d][%d][%d] = %LE",i+1,j+1,k+1,l[i][j][k]);
            }
            do
            {
                fscanf(fpt,"%c",&c);
                /*printf("\n got here \n");*/
            }
            while (c!='\n');
        }
//        printf("\n");
    }
    sigma[0] = 1.0;
    sigma[1] = 1.0;
    sigma[2] = 1.0;
    sigma[3] = 1.0;
    sigma[4] = 1.0;
    sigma[5] = 2.0;
    sigma[6] = 2.0;
    sigma[7] = 2.0;
    sigma[8] = 2.0;
    sigma[9] = 2.0;
    lambda[0] = 1.0/4.0;
    lambda[1] = 1.0/20.0;
    lambda[2] = 5.0;
    lambda[3] = 1.0;
    lambda[4] = 5.0;
    lambda[5] = 1.0;
    lambda[6] = 50.0;
    lambda[7] = 10.0;
    lambda[8] = 1.0/8.0;
    lambda[9] = 1.0/40.0;
    global_bias = 360.0;
    return;
}

void initialize_f24()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = myopen("hybrid_func4_data.txt","r");
    if (fpt==NULL)
    {
        fprintf(stderr,"\n Error: Cannot open input file for reading \n");
        exit(0);
    }
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            fscanf(fpt,"%Lf",&o[i][j]);
//            printf("\n O[%d][%d] = %LE",i+1,j+1,o[i][j]);
        }
        do
        {
            fscanf(fpt,"%c",&c);
        }
        while (c!='\n');
//        printf("\n");
    }
    fclose(fpt);
    if (nreal==2)    fpt = myopen("hybrid_func4_M_D2.txt","r");
    if (nreal==10)    fpt = myopen("hybrid_func4_M_D10.txt","r");
    if (nreal==30)    fpt = myopen("hybrid_func4_M_D30.txt","r");
    if (nreal==50)    fpt = myopen("hybrid_func4_M_D50.txt","r");
    for (i=0; i<nfunc; i++)
    {
        for (j=0; j<nreal; j++)
        {
            for (k=0; k<nreal; k++)
            {
                fscanf(fpt,"%Lf",&l[i][j][k]);
//                printf("\n M[%d][%d][%d] = %LE",i+1,j+1,k+1,l[i][j][k]);
            }
            do
            {
                fscanf(fpt,"%c",&c);
            }
            while (c!='\n');
        }
//        printf("\n");
    }
    for (i=0; i<10; i++)
    {
        sigma[i] = 2.0;
    }
    lambda[0] = 10.0;
    lambda[1] = 1.0/4.0;
    lambda[2] = 1.0;
    lambda[3] = 5.0/32.0;
    lambda[4] = 1.0;
    lambda[5] = 1.0/20.0;
    lambda[6] = 1.0/10.0;
    lambda[7] = 1.0;
    lambda[8] = 1.0/20.0;
    lambda[9] = 1.0/20.0;
    global_bias = 260.0;
    return;
}

void initialize_f25()
{
    initialize_f24();
}

void initialize(void) {
   int num = nfunc;

   if (num == 1) {
      initialize_f1();
   }
   else if (num == 2) {
      initialize_f2();
   }
   else if (num == 3) {
      initialize_f3();
   }
  else if (num == 4) {
      initialize_f4();
  }
  else if (num == 5) {
      initialize_f5();
   }
 else if (num == 6) {
      initialize_f6();
   }
   else if (num == 7) {
      initialize_f7();
   }
   else if (num == 8) {
      initialize_f8();
   }
  else if (num == 9) {
      initialize_f9();
   }
   else if (num == 10) {
      initialize_f10();
   }
   else if (num == 11) {
      initialize_f11();
   }
   else if (num == 12) {
      initialize_f12();
   }
   else if (num == 13) {
      initialize_f13();
   }
  else if (num == 14) {
      initialize_f14();
  }
  else if (num == 15) {
      initialize_f15();
      calc_benchmark_norm_f15();

   }
 else if (num == 16) {
      initialize_f16();
      calc_benchmark_norm_f16();
   }
   else if (num == 17) {
      initialize_f17();
      calc_benchmark_norm_f17();
   }
   else if (num == 18) {
      initialize_f18();
      calc_benchmark_norm_f18();
   }
   else if (num == 19) {
      initialize_f19();
      calc_benchmark_norm_f19();
   }
   else if (num == 20) {
      initialize_f20();
      calc_benchmark_norm_f20();
   }
   else if (num == 21) {
      initialize_f21();
      calc_benchmark_norm_f21();
   }
   else if (num == 22) {
      initialize_f22();
      calc_benchmark_norm_f22();
   }
   else if (num == 23) {
      initialize_f23();
      calc_benchmark_norm_f23();
   }
  else if (num == 24) {
      initialize_f24();
      calc_benchmark_norm_f24();
  }
  else if (num == 25) {
      initialize_f25();
      calc_benchmark_norm_f25();
   }
else {
   printf("Error: num %d no válido\n", num);
   exit(1);
}

}
