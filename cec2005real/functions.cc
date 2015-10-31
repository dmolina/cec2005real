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

#define _FUNCTIONS

#include <math.h>
#include "functions.h"
#include "newutil.h"
#include "../common/define.h"
#include "../common/random.h"
#include <assert.h>
#include <cmath>

using namespace std;

double pow(const tGen x, double n) {
    return (pow(x, (const tGen) n));
}

/* Modelo Esferico */

double sphere(const tGen *x, int n)
{
	int i;
	double sum;

	sum = 0.0;
	for (i = 0; i < n; i++)
		sum += x[i] * x[i];

	return (sum);
}

double step(const tGen *x, int dim) {
    double result=0;
    int i=0;

    for (i = 0; i < dim; i++) {
	result += fabs(x[i]);
    }
    
    result += 6*dim;
    return result;
}

double step2(const tGen *x, int dim) {
    double result=0;
    int i=0;

    for (i = 0; i < dim; i++) {
	result += ceil(x[i]);
    }
    
    result += 6*dim;
    return result;
}


/* Fin de Fichero */

/* Función de Branin */
double branin(const tGen *x, int n)
{   
    double A,B,C;
    double x1, x2, s1, s2;
    x1 = x[0];
    x2 = x[1];
    A = 5.0/(4*M_PI*M_PI);
    B = 5.0/M_PI;
    C = 1-(1.0/(8*M_PI));
    
    s1 = x2-A*x1*x1+B*x1-6;
    s2 = 10*C*cos(x1)+10;

    return (s1*s1+s2);
}

/* Funciób B2 */

double b2(const tGen *x, int n) {
    double x1, x2;
    x1 = x[0];
    x2 = x[1];
    return (x1*x1+2*x2*x2-0.3*cos(3*M_PI*x1)-0.4*cos(4*M_PI*x2)+0.7);
}

double easom(const tGen *x, int n) {
    double x1, x2;
    double sum;
    x1 = x[0];
    x2 = x[1];
    sum = (x1-M_PI)*(x1-M_PI)+(x2-M_PI)*(x2-M_PI);
    
    return -cos(x1)*cos(x2)*exp(-sum);
}

/* Shubert */
double shubert(const tGen *x, int  n) {
    int j;
    double s1,s2;
    s1 = s2 = 0;

    for (j = 1; j <= 5; j++) {
	s1 += j*cos((j+1)*x[0]+j);
	s2 += j*cos((j+1)*x[1]+j);
    }

    return (s1*s2);
}

/* Funcion de Beale */
double beale(const tGen *x, int n) {
    double s1,s2,s3;
    double x1=x[0], x2=x[1];

    s1 = 1.5-x1+x1*x2;
    s2 = 2.25-x1+x1*x2*x2;
    s3 = 2.625-x1+x1*x2*x2*x2;

    return (s1*s1+s2*s2+s3*s3);
}

/* Function Booth */
double booth(const tGen *x, int n) {
    double s1,s2;
    double x1=x[0],x2=x[1];

    s1 = x1+2*x2-7;
    s2 = 2*x1+x2-5;
    return (s1*s1+s2*s2);
}

/* Function matyas */
double matyas(const tGen *x, int n) {
    double x1=x[0];
    double x2=x[1];

    return (0.26*(x1*x1+x2*x2))-(0.48*x1*x2);
}

/* Function bump */
double bump(const tGen *x, int n) {
    double cos_x;
    double num,denom;
    int i;
    double sum1 = 0;
    double sum2 = 1;
    double sum3 = 0;

    for (i = 0; i < n; i++) {
	cos_x = cos(x[i]);
	sum1 += (cos_x*cos_x*cos_x*cos_x);
    }

    for (i = 0; i < n; i++) {
	cos_x = cos(x[i]);
	sum2 *= cos_x*cos_x;
    }
    
    num = fabs(sum1-2*sum2);
    
    for (i = 0; i < n; i++) {
	sum3 += (i+1)*x[i]*x[i];
    }

    assert(sum3 > 0);
    denom = sqrt(sum3);
    return num/denom;
}

/* Function SixHumpCamelBack */
double sixhumpcamelback(const tGen *x, int n) {
    double x1=x[0];
    double x2=x[1];
    double x12=x1*x1;
    double x22=x2*x2;

    return (4*x12-2.1*x12*x12+(x12*x12*x12)/3.0+x1*x2-4*x22+4*x22*x22);
}


/* Funcion Generalizada de Rosenbrock */

double
rosenbrock(const tGen *x, int n)
{

    int    i;

    double      Sum,
                sum1, sum2;

    for (Sum = 0, i = 0; i < n-1; i++) {
	sum1 = x[i+1]-x[i]*x[i];
	sum2 = x[i]-1;
	Sum += 100*sum1*sum1+sum2*sum2;
    }

/*
	for (Sum2 = 0.0, i = 0; i < (n/2); i++) {
	   i2 = 2*i;
	   sum1 = x[i2]-pow(x[i2-1], 2);
	   sum2 = 1-x[i2-1];
	   Sum2 += 100*sum1*sum1+sum2*sum2;
	}
*/
    	return (Sum);
}

/** Fin de Fichero **/
/*  Funcion Paso  */

double
goldstein_price(const tGen *x, int n)
{
    double  suma;
    suma=(1.0 + (x[0]+x[1]+1.0)*(x[0]+x[1]+1.0)*
     (19.0-14.0*x[0]+3.0*x[0]*x[0]-14.0*x[1]+6.0*x[0]*x[1]+3.0*x[1]*x[1]))*
     (30.0 + (2.0*x[0]-3.0*x[1])*(2.0*x[0]-3.0*x[1])*
     (18.0-32.0*x[0]+12.0*x[0]*x[0]+48.0*x[1]-36.0*x[0]*x[1]+27.0*x[1]*x[1]));
    
    return (suma);
}

/* Función Zakharov */
double zakharov(const tGen *x, int D) {
   int j;
   double s1,s2,s3,inc;

   s1=s2=s3= 0;

   for (j = 1; j <= D; j++) {
      s1 += x[j-1]*x[j-1];
      inc = 0.5*j*x[j-1];
      s2 += inc*inc;
      s3 += inc*inc*inc*inc;
   }

   return (s1+s2+s3);
}

/* Funcion de Joung */
double dejoung(const tGen *x, int n) {
    return (x[0]*x[0]+x[1]*x[1]+x[2]*x[2]);
}

/* Función de Bohachevsky */
double bohachevsky(const tGen *x, int n) {
    double x1,x2;

    x1 = x[0];
    x2 = x[1];

    return (x1*x1+2*x2*x2-0.3*cos(3*M_PI*x1)*cos(4*M_PI*x2)+0.3);
}

/* Función de Watson */
double watson(const tGen *x, int n) {
    int i,j;
    double ai;
    double total,sum1,sum2;

    total = 0;

    for (i = 1; i <= 30; i++) {
        // Calculo la primera sumatoria
	sum1 = 0;
	// Inicio ai = (i-1)/29
	ai = (i-1)/29.0;

	for (j = 1; j < n; j++) {
	   sum1 += j * pow(ai, j-1) * x[ j ];
	}

	// Calculo la segunda sumatoria
	sum2 = 0;

	for (j = 1; j <= n; j++) {
	    sum2 += pow(ai, j-1) * x[ j-1 ];
	}

	total += (sum1-sum2-1)*(sum1-sum2-1);
    }

    return total + x[0]*x[0];
}

/* Función Hartman */
double Hartman34(const tGen *x, int n) {
    int i, j;
    double s1, s2;
    double c[] = {1.0,1.2,3.0,3.2};
    double a[4][3] = {
	{3.0,10.0,30.0},
	{0.1,10.0,35.0},
	{3.0,10.0,30.0},
	{0.1,10.0,35.0}
    };

    double p[4][3] = {
	{0.3689,0.1170,0.2673},
	{0.4699,0.4387,0.7470},
	{0.1091,0.8732,0.5547},
	{0.0381,0.5743,0.8828}
    };
    
    for (i = 0, s1 = 0; i < 4; i++) {
	for (s2 = 0, j = 0; j < 3; j++) {
	    s2 += a[i][j]*(x[j]-p[i][j])*(x[j]-p[i][j]);
	}

	s1 += c[i]*exp(-s2);
    }

    return s1;
}

/* Funcion colville */
double colville(const tGen *x, int n) {
    double x1=x[0],x2=x[1],x3=x[2],x4=x[3];
    double Sum=0;

    Sum += 100*(x2-x1*x1)*(x2-x1*x1)+(1-x1)*(1-x1);
    Sum += 90*(x4-x3*x3)*(x4-x3*x3)+(1-x3)*(1-x3);
    Sum += 10.1*((x2-1)*(x2-1)+(x4-1)*(x4-1));
    Sum += 19.8*(x2-1)*(x4-1);
    return Sum;
}

/* Funcion Shekel 
 * Requiere que x tenga 4 elementos
 * */
double shekel(const tGen *x, int n) {
    double value,value2;
    int i, j;
    double c[] = {0.1,0.2,0.2,0.4,0.4,0.6,0.3,0.7,0.5,0.5};
    double a[][4] = {
	 {4.0,4.0,4.0,4.0},
	 {1.0,1.0,1.0,1.0},
	 {8.0,8.0,8.0,8.0},
	 {6.0,6.0,6.0,6.0},
	 {3.0,7.0,3.0,7.0},
	 {2.0,9.0,2.0,9.0},
	 {5.0,5.0,3.0,3.0},
	 {8.0,1.0,8.0,1.0},
	 {6.0,2.0,6.0,2.0},
	 {7.0,3.6,7.0,3.6}
    };
    
    value = 0;
    
    for (i = 0; i < n; i++) {
        value2 = 0;
	
	for (j = 0; j < 4; j++) {
	   value2 += (x[j]-a[i][j])*(x[j]-a[i][j]);
	}

	value += 1.0/(value2+c[i]);
    }

    return (-value);
}

/* Funciones Shekel para varios factores */
double shekel5(const tGen *x, int n) {
    return shekel(x,5);
}

double shekel7(const tGen *x, int n) {
    return shekel(x,7);
}

double shekel10(const tGen *x, int n) {
    return shekel(x,10);
}


/* Perm function */
double Perm2(const tGen *x, int n, double beta) {
    int i, k;
    double  sum,result,coc;

    result = 0;

    for (k=1; k <= n; k++) {
        sum = 0; 
	
	for (i = 1; i <= n; i++) {
	   coc = (x[i-1]/i);
	   sum += (pow( (const tGen)i,k)+beta)*(pow(coc,k)-1);
	}

	result +=sum*sum; 
    }

    return result;
}

double Perm(const tGen *x, int n) {
   return Perm2(x, n, 0.5); 
}

/* Función Perm0 */
double Perm02(const tGen *x, int n, double beta) {
    int i, k;
    double  sum,result,coc;

    result = 0;

    for (k=1; k <= n; k++) {
        sum = 0; 
	
	for (i = 1; i <= n; i++) {
	   coc = (1.0/i);
	   sum += (i+beta)*(pow(x[i-1],k)-pow(coc,k));
	}

	result +=sum*sum; 
    }

    return result;
}

double Perm_0(const tGen *x, int n) {
   return Perm02(x, n, 10.0); 
}


/* Funcion PowerSum */
double PowerSum(const tGen *x, int n) {
   int i, k;
   double b[] ={8.0,18.0,44.0,114.0}; 
   double sum,result;

   result = 0;

   for (k = 1; k <= n; k++) {
      sum = 0;

      for (i = 0; i < n; i++) {
	sum += pow(x[i],k);
      }

      sum -= b[k-1];
      result += sum*sum;
   }

   return result;
}

/* Función Hartman */
double Hartman64(const tGen *x, int n) {
    int i, j;
    double s1, s2;
    double c[] = {1.0,1.2,3.0,3.2};
    double a[4][6] = {
	{10.0, 3.0,17.0, 3.5, 1.7, 8.0},
	{0.05,10.0,17.0, 0.1, 8.0,14.0},
	{3.0,  3.5,1.7, 10.0,17.0, 8.0},
	{17.0, 8.0,0.05, 10.0, 0.1, 14.0}
    };

    double p[4][6] = {
	 {0.1312, 0.1696, 0.5569, 0.0124, 0.8283, 0.5886},
	 {0.2329, 0.4135, 0.8307, 0.3736, 0.1004, 0.9991},
	 {0.2348, 0.1451, 0.3522, 0.2883, 0.3047, 0.6650},
	 {0.4047, 0.8828, 0.8732, 0.5743, 0.1091, 0.0381}
    };
    
    for (i = 0, s1 = 0; i < 4; i++) {
	for (s2 = 0, j = 0; j < 6; j++) {
	    s2 += a[i][j]*(x[j]-p[i][j])*(x[j]-p[i][j]);
	}

	s1 += c[i]*exp(-s2);
    }

    return s1;
}

/* Function Trid */
double Trid(const tGen *x, int n) {
    int i;
    double sum,rest;

    sum = rest = 0;
    
    for (i = 0; i < n; i++) {
       sum += (x[i]-1)*(x[i]-1);
    }

    for (i = 1; i < n; i++) {
	rest += x[i]*x[i-1];
    }

    return (sum-rest);
}


/* Funcion Cuadratica con Ruido */


double Chebychev(const tGen *tmp, int D)                  
{                                                     
    int i,j;
    double px,x=-1,result=0,dx=0;

    if ( D == 9 )
      dx=72.66066;
    if ( D == 17 )
      dx=10558.145;

    for (i=0;i<=100;i++)
      {
	px=tmp[0];
	for (j=1;j<D;j++) px=x*px+tmp[j];
	if (px<-1 || px>1) result+=(1.-px)*(1.-px);
	x+=.02;
      }

    px=tmp[0];
    for (j=1;j<D;j++) px=1.2*px+tmp[j];
    px=px-dx;
    if (px<0) result+=px*px;

    px=tmp[0];
    for (j=1;j<D;j++) px=-1.2*px+tmp[j];
    px=px-dx;
    if (px<0) result+=px*px;

    return(result);
}


double cheb9(const tGen *x, int n)
{
    double result;

    result=Chebychev(x, 9);
    return(result);                  

}

/* Funcion SHEKEL'S FOXHOLES */

double f_5(const tGen *x, int n) {
   int a[2][25] ={
	{
	  -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32,
	  -32, -16, 0, 16, 32, -32, -16, 0, 16, 32    },
	    {
	      -32, -32, -32, -32, -32, -16, -16, -16, -16, -16,0,0,0,0,0,
	      16, 16, 16, 16, 16, 32, 32, 32, 32, 32    }
   };

   double	K = 500.0;


   int i,j;

   double 		Sum = 0.0,
   Val,
   Dif;

   for (Sum = 1.0 / K, j = 0; j < 25; j++) 
     {
       for (Val = (const tGen)j + 1.0, i = 0; i < n; i++) 
	 {
	   Dif  = x[i] - (const tGen)a[i][j];
	   Val += pow(Dif, 6.0);
	 }
       Sum += 1.0 / Val;
     }

   return (1.0 / Sum);
}

/* Funcion de Schwefel 1.2 */

double
schwefel_12(const tGen *x, int n)
{

    register int 	i;

    double 		Sum,
    Val;

    for (Sum = Val = 0.0, i = 0; i < n; i++)
      {  
	Val += x[i];
	Sum += Val * Val;
      }

    return (Sum);

}

/* Funcion de Rastrigin Generalizada */
double
rastrigin(const tGen *x, int n)
{
#define OMEGA 	6.28318530717958647688
#define AMP	10.0


    register int 	i;
    double 		Sum;

    for (Sum = 0.0, i = 0; i < n; i++)
      Sum += x[i] * x[i] - AMP * cos(OMEGA * x[i]);

    Sum += (const tGen)n * AMP;

    return(Sum);
}

double rastrigin_funcR(const tGen *x, int n) {
    MyMatrix A(n,n);
    double result=0;
    Real data[n];
    int i;

    for (i = 0; i < n; i++) {
	data[i] = x[i];
    }

    A = 0.0;

    for (i = 1; i <= n; ++i) {
       ColumnVector colA = A.Column(i);
       colA[i-1]=4.0/5.0;

       if (i % 2 == 0) {
	   colA[i-2]=-3.0/5.0;
       }
       else if (i != n) {
	   colA[i] = 3.0/5.0;
       }

       A.Column(i) = colA;
    }

    ColumnVector t(n);
    t <<data;

    ColumnVector y(n);
    y = A*t;

    for (i = 0, result = 0.0; i < n; i++) {
	result += pow2(y[i])-10*cos(2*M_PI*y[i])+10;
    }
    return result;
}

double rastrigin_funcS(const tGen *x, int n) {
   double value, sum;
   int i;
   double D=n-1.0;

   for (i = 0, sum = 0; i < n; i++) {
       value = pow(10.0, i/D)*x[i];
       sum += pow2(value)-10*cos(2*M_PI*value)+10;
   }

   return sum;
}

/* Funcion de Schwefel */


double schwefel_226(const tGen *x, int n)
{
    int i;
    double h, raiz;

    h = 0;

    for (i=0; i<n; i++)
      {
	raiz=sqrt(fabs(x[i]));
	h -= x[i] * sin(raiz);
      }

    return (h);
}

double
schwefel(const tGen *x, int n)
{
    int i;
    double h, ab, raiz;

    h=(const tGen)n;
    h*=418.9829;

    for (i=0; i<n; i++)
      {
	if (x[i] > 0)
	  ab = x[i];
	else
	  ab = (-1.0) * x[i];

	raiz=sqrt(ab);

	h += x[i] * sin(raiz);
      }

    return (h);
}

/* Funcion de Griewank */

double
griewank(const tGen *x, int n)
{
    register int 	i;
    double	    D	=4000.0;

    double 		Val1,
    Val2,
    Val3,
    Sum;

    for (Val1 = 0.0, Val2 = 1.0, i = 0; i < n; i++)
      {
	Val1 += x[i] * x[i];
	Val3=sqrt((const tGen) (i + 1));
	Val2 *= cos(x[i] / Val3);
      }

    Sum = Val1 / D - Val2 + 1.0;
    return (Sum);
}

/* Funcion Sum Squares */
double sum_squares(const tGen *x, int n) {
    int i;
    double result = 0;

    for (i = 1; i <= n; i++) {
	result += i*x[i-1]*x[i-1];
    }

    return result;
}

/* Funcion Powell */
double powell(const tGen *x, int n) {
   int i, j, maxn;
   double result, sum1, sum2, sum3, sum4;

   maxn = n/4;
   result = 0;

   for (j = 1; j <= maxn; j++) {
	i = 4*j-1;
	sum1 = x[i-3]+10*x[i-2];
	sum2 = x[i-1]-x[i];
	sum3 = x[i-2]-2*x[i-1];
	sum4 = x[i-3]-x[i];
	result += sum1*sum1+5*sum2*sum2+pow(sum3, 4)+10*pow(sum4,4);
   }

   return result;
}

/* Funcion Dixon and Price */
double dixon_price(const tGen *x, int n) {
   double result;
   double sum;
   int i;

   sum = result = 0;
   result += (x[0]-1.0)*(x[0]-1.0);
   
   for (i = 1; i < n; i++) {
	sum = 2*x[i]-x[i-1];
	result += (i+1)*sum*sum;
   }
   
   return result;
}

/* Funcion Levy */

double levy(const tGen *x, int n) {
   int i;
    double result=0;
    double A,op1,op2, sum;
    
    result = sum = 0;

    A = sin(3*M_PI*x[0]);
    result += A*A;
    
    for (i = 0; i < n-2; i++)  {
	op1=(x[i]-1)*(x[i]-1);
	op2 = sin(3*M_PI*x[i+1]);
	result += op1*op1*(1+op2*op2);
    }

    op1 = (x[n-1]-1);
    op2 = sin(2*M_PI*x[n-1]);
    result += op1*(1+op2*op2);

    return result;
}


/* Funcion de Ackley */

double ackley(const tGen *x, int n)
{
    int 	i;
    double  A=20.0;
    double  B=0.2;
    double  Da=0.0;
    double 	E, Val1, 
    Val2, 
    Sum;

    Da =  2.0*3.141592654;
    E = exp(1.0);

    for (Val1 = Val2 = 0.0, i = 0; i < n; i++)
      {
	Val1 += x[i] * x[i];
	Val2 += cos(Da * x[i]);
      }


    Val1=sqrt(Val1 /(const tGen) n);

    Val2=exp(Val2 / (const tGen) n);

    Val1=exp(-B *Val1);

    Sum = 	- A * Val1 + A - Val2 + E;

    return (Sum);
}



double F10(const tGen x, tGen y)
{
    tGen z, t, salida;

    z=(x*x+y*y);
    z=pow(z, 0.25);
    t=(x*x+y*y);
    t=50.0*pow(t, 0.1);
    t=sin(t);
    t=t*t+1.0;
    salida=z*t;

    return(salida);
}

double ef10(const tGen *x, int n)
{
    int         i;
    double      suma;

    for(i=0, suma=0.0; i<n-1; i++)
      suma+=F10(x[i], x[i+1]);

    suma+=F10(x[n-1], x[0]);

    return(suma);
}

/* Funcion de Katsuura */


double
f_12(const tGen *x, int n)
{
    int         i, j, beta;

    double 	    Val1,
    Val2,
    suma,
    producto;

    static int firstflag=1;

    static double Exp2[100];

    beta=30; /* El parametro beta de la funcion es 30 */


    if (firstflag)
      {
	firstflag=0;
	for (producto=1.0, i=0; i <= beta; i++)
	  {
	    Exp2[i]=producto;
	    producto*=2.0;
	  }
      }

    for (producto=1.0, i = 0; i < n; i++)
      {
	for (suma=0.0, j=0; j <= beta; j++)
	  {
	    Val1=(const tGen)(Exp2[i+1]*x[i]);

	    Val2=fabs(Exp2[j]*x[i]-Val1);

	    suma+=Val2/Exp2[j];
	  }
	producto*=1.0+(const tGen)(i+1)*suma;
      }

    return(producto);
}

/**
 * Fcigtab
 */
double fcigtab(const tGen *x, int ndim) {
   double sum, result;
   int i;
   int begin =0;
   int end = ndim-1;

   result = x[begin]*x[begin]+1e8*x[end]*x[end];

   for (i = begin+1, sum=0; i < end; i++) {
	sum += x[i]*x[i];
   }

   result += 1e4*sum;
   return result;
}

//double ruido2(const tGen *x, int n) {
//    double result;
//    int i;
//
//    result= 0;
//
//    for (i = 0; i < n; i++) {
//	result += pow( (i+1)*x[i], 4.0);
//    }
//
//    result += Random::rand();
//    return result;
//}

double suma_producto(const tGen *x, int n) {
    double s, p;
    int i;

    s = 0.0;
    p = 1.0;

    for (i = 0; i < n; ++i) {
	s += fabs(x[i]);
	p *= fabs(x[i]);
    }

    return (s+p);
}

double maximo_x(const tGen *x, int n) {
    double max_x, f_x;
    int i;

    max_x = 0;

    for (i = 0; i < n; ++i) {
	f_x = fabs(x[i]);
	
	if (i == 0 || f_x > max_x) {
	    max_x = f_x;
	}
    }

    return max_x;
}
/* Funcion de Test Sistema ($x_i\in [-128, 127]$) */

static double MatA[10][10]={{5.0, 4.0, 5.0, 2.0, 9.0, 5.0, 4.0, 2.0, 3.0, 1.0},
     {9.0, 7.0, 1.0, 1.0, 7.0, 2.0, 2.0, 6.0, 6.0, 9.0},
     {3.0, 1.0, 8.0, 6.0, 9.0, 7.0, 4.0, 2.0, 1.0, 6.0},
     {8.0, 3.0, 7.0, 3.0, 7.0, 5.0, 3.0, 9.0, 9.0, 5.0},
     {9.0, 5.0, 1.0, 6.0, 3.0, 4.0, 2.0, 3.0, 3.0, 9.0},
     {1.0, 2.0, 3.0, 1.0, 7.0, 6.0, 6.0, 3.0, 3.0, 3.0},
     {1.0, 5.0, 7.0, 8.0, 1.0, 4.0, 7.0, 8.0, 4.0, 8.0},
     {9.0, 3.0, 8.0, 6.0, 3.0, 4.0, 7.0, 1.0, 8.0, 1.0},
     {8.0, 2.0, 8.0, 5.0, 3.0, 8.0, 7.0, 2.0, 7.0, 5.0},
     {2.0, 1.0, 2.0, 2.0, 9.0, 8.0, 7.0, 4.0, 4.0, 1.0}};

static double MatB[10]={40.0, 50.0, 47.0, 59.0, 45.0, 35.0, 53.0, 50.0, 55.0, 40.0};

double sle(const tGen *x, int n)
{
    int i, j;
    double ER, er;

    ER=0.0;
    for (i=0; i<n; i++)
      {
	er=0.0;
	for (j=0; j<n; j++) er+=(MatA[i][j] * x[j]);
	if (er>MatB[i])  ER+=er-MatB[i];
	else             ER+=MatB[i]-er;
      }

    return(ER);
}
/* Modelo Esferico */

double f_14(const tGen *x, int n)
{
    int i;
    double y[110], sum;

    sum = 0.0;
    y[0]=100.0;

    for (i = 0; i < n; i++)
      {
	sum+=(y[i]*y[i]+x[i]*x[i]);
	y[i+1]=y[i]+x[i];
      }

    return (y[n]+sum);
}

/* Frequency Modulation Sound ---> Genes()=6 y x_i \in [-6.4, 6.35] */

double y_0(const tGen a1, double w1, double a2, double w2, double a3, 
	    double w3, int t)
{
    double x, y, eta;

    eta=2.0*3.141592654/100.0;

    y=w3*(const tGen)t*eta;
    x=a3*sin(y);
    y=x+w2*(const tGen)t*eta;
    x=a2*sin(y);
    y=x+w1*(const tGen)t*eta;
    x=a1*sin(y);
    return(x);
}

double fms(const tGen *x, int n)
{
    int i;
    double yt, yt_0, sum;

    sum=0.0;
    for (i=0; i <=100; i++)
      {
	yt_0= y_0(1.0, 5.0, -1.5, 4.8, 2.0, 4.9, i); 
	yt  = y_0(x[0], x[1], x[2], x[3], x[4], x[5], i);
	sum=sum+(yt_0-yt)*(yt_0-yt);
      }

    return (sum);
}

double fschaffer(const tGen *x, int n) {
    double s, result;
    double sin_s;
    int i;

    for (i = 0, result=0; i < n-1; i++) {
	s=pow2(x[i])+pow2(x[i+1]);
	sin_s = sin(50*pow(s, 0.1));
	result += pow(s, 0.25)*(pow2(sin_s)+1);
    }

    return result;
}

double f8f2(const tGen *x, int n) {
    double sum;
    tGen aux[2];
    int i;

    for (i = 0, sum=0; i < n-1; ++i) {
	sum += griewank(&x[i], 2);
    }

    aux[0] = x[n-1];
    aux[1] = x[0];
    sum += griewank(aux, 2);
    return sum;
}

double fschwefelmult(const tGen *x, int n) {
   double sum;
   int i;

   for (i = 0, sum = 0; i < n; i++) {
	sum += x[i]*sin(sqrt(fabs(x[i])));
   }

   return -sum;
}

/* This routine calculates the value of the selected function for the 
 *
   corresponding input individual. This is directly the fnvalness. */
double objfn(const tGen *x, int nvar) {
   int j,k,nhard=1;
   int NVAR=nvar;

   double cw=0.5, cmin=0.0, A=0.05, B=0.01;

   tGen fnval=0.0, fdum=0.0, fhdum=0.0, sdum=0.0; /* Calculate a priori exact value of fmax */

   tGen af[5][NVAR], cf[5], dist[5], wf[5];

   tGen dum[5], dif[NVAR], dist2=0.0;

   /* Peaks locations */

   for (j=0; j<NVAR; j++) af[0][j]=2.0;

   for (j=0; j<NVAR; j++) af[1][j]=5.0;

   for (j=0; j<NVAR; j++) af[2][j]=7.0;

   for (j=0; j<NVAR; j++) af[3][j]=9.0;

   for (j=0; j<NVAR; j++) af[4][j]=3.5;



   /* Peaks Widths */

   wf[0]=cw;

   wf[1]=cw;

   wf[2]=cw;

   /* wf[3]=3*cw; */

   wf[3]=cw;

   wf[4]=cw;

   /* Peaks Depth */

   cf[0]=A;

   cf[1]=A;

   cf[2]=A;

   cf[3]=A;/* global min */

   cf[4]=A;



   /*for(j=0; j<NVAR; j++) x[j]=7.;*/



   for (k=0; k<4; k++)

     {

       sdum=0.0;

       for(j=0; j<nhard; j++)

	 {

	   dif[j] = x[j] - af[k][j];

	   sdum += (dif[j]*dif[j]);

	 }

       dist[k] = sqrt(sdum);

     }

   dist[4] = 0.0;



   for (k=0; k<4; k++)

     dum[k] = cf[k] * exp(-(dist[k]*dist[k])/(wf[k]*wf[k]*(nhard)));



   if (x[0]<4) cmin=af[0][0]; /* forget about 3.5 minima */

   else if (x[0]<6) cmin=af[1][0];

   else if (x[0]<8.5) cmin=af[2][0];

   else if (x[0]<10) cmin=af[3][0];



   sdum=0.0;

   for(j=0; j<NVAR; j++)

     {

       dif[j] = x[j] - cmin;

       sdum += (dif[j]*dif[j]);

     }

   dist2 = sqrt(sdum);



   fhdum = B *dist2 / sqrt( (double) NVAR);



   for (k=0; k<4; k++) fdum += dum[k];

   fnval= A - fdum + fhdum;



   /*printf("\n fnval=%e fdum=%e fhdum=%e",fnval,fdum,fhdum);

     exit(1);*/



   return(fnval);
}


double salomon(const tGen *x, int nvar) {
    double valtam = sqrt(sphere(x, nvar));

    return (-cos(2*M_PI*valtam)+0.1*valtam+1);
}

double whitely(const tGen *x, int nvar) {
    tGen y[nvar][nvar];
    int i, j;
    double sum;

    for (i = 0; i < nvar; ++i) {
	for (j = 0; j < nvar; ++j) {
	    y[i][j] = 100*pow((x[j]-x[i]*x[i]), 2)+pow(1-x[i], 2);
	}
    }

    sum = 0;

    for (i = 0; i < nvar; ++i) {
	for (j = 0; j < nvar; ++j) {
	    sum += (y[i][j]*y[i][j])/4000-cos(y[i][j])+1;
	}

    }

    return sum;
}

double pn_u(const tGen x, double a, double k, double m) {
    double result;

    if (x > a) { 
	result = k*pow((x-a), m);
    }
    else if (x >= -a && x <= a) {
	result = 0;
    }
    else {
	result = k*pow((-x-a),m);
    }

    return result;
}

double pn1(const tGen *x, int nvar) {
    tGen y[nvar];
    double sumu, sumy,result;
    int i;

    for (i = 0; i < nvar; ++i) {
	y[i] = 1+0.25*(x[i]+1);
    }
    
    sumy = 0;
    sumu = 0;

    for (i = 0; i < nvar-1; ++i) {
	sumy += (y[i]-1)*(y[i]-1)*(1+10*pow(sin(M_PI*y[i+1]),2));
    }

    for (i = 0; i < nvar; ++i) {
	sumu += pn_u(x[i],10.0,100.0,4.0);
    }

    result = M_PI/nvar*(10*pow(sin(M_PI*y[1]),2)+sumy+pow(y[nvar-1]-1, 2)) + sumu;
    return result;
}

double pn2(const tGen *x, int nvar) {
    double sumu, sumx;
    double result;
    int i;

    sumx = 0;
    sumu = 0;

    for (i = 0; i < nvar-1; ++i) {
	sumx += (x[i]-1)*(x[i]-1)*(1+pow(sin(3*M_PI*x[i+1]),2));
    }

    for (i = 0; i < nvar; ++i) {
	sumu += pn_u(x[i],5.0,100.0,4.0);
    }

    result = 0.1*(pow(sin(3*M_PI*x[1]),2)+sumx+pow(x[nvar-1]-1, 2)*(1+pow(sin(2*M_PI*x[nvar-1]),2))) + sumu;
 
    return result;
}

double foxhole(const tGen *xs, int nvar) {
    assert(nvar == 2);
    tGen x, y;
    double a[25],b[25];
    int i;

    x = xs[0]; y = xs[1];

    double sum = 0;
    for (i = 0; i < 25; ++i) {
	a[i] = 16*((i % 5)-2);
	b[i] = 16*((i/5)-2);
    }

    for (i = 0; i <= 24; ++i) {
	sum += 1/(pow(1 +i +a[i], 6) + pow(y- b[i],6)); 
    }

    return (500-1.0/(0.002+sum));
}
/* Fin de Fichero */
