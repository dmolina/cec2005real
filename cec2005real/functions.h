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

#ifndef _FUNCTIONS
#define _FUNCTIONS

#include "../common/define.h"

double sphere(const tGen *,int);
double step(const tGen *x, int dim); 
double step2(const tGen *x, int dim); 
double branin(const tGen *,int);
double b2(const tGen *,int);
double ackley(const tGen *x, int n);
double easom(const tGen *,int);
double goldstein_price(const tGen *,int);
double shubert(const tGen *,int);
double beale(const tGen *,int);
double booth(const tGen *,int);
double matyas(const tGen *,int);
double sixhumpcamelback(const tGen *x, int n);
double schwefel(const tGen *,int);
double schwefel_226(const tGen *x, int n);
double rosenbrock(const tGen *,int);
double zakharov(const tGen *,int);
double rastrigin(const tGen *,int);
double rastrigin_funcR(const tGen *, int); 
double rastrigin_funcS(const tGen *, int); 
double griewank(const tGen *,int);
double Trid(const tGen *, int);
double dejoung(const tGen *, int);
double Hartman34(const tGen *, int);
double Hartman64(const tGen *, int);
double colville(const tGen *, int);
double Perm(const tGen *, int);
double Perm_0(const tGen *, int);
double PowerSum(const tGen *, int);
double sum_squares(const tGen *, int);
double powell(const tGen *, int);
double levy(const tGen *, int);
double shekel5(const tGen *, int);
double shekel7(const tGen *, int);
double shekel10(const tGen *, int);
double dixon_price(const tGen *, int);
double fms(const tGen *,int);
double sle(const tGen *,int);
double cheb9(const tGen *, int);
double schwefel_12(const tGen *, int);
double ef10(const tGen *, int);
double bohachevsky(const tGen *, int);
double watson(const tGen *, int);
double bump(const tGen *x, int n); 
double fcigtab(const tGen *x, int ndim);
double ruido2(const tGen *x, int ndim);
double maximo_x(const tGen *x, int ndim);
double suma_producto(const tGen *x, int ndim);



double f_3(const tGen *,int);
double f_4(const tGen *,int);
double f_5(const tGen *,int);
double f_6(const tGen *,int);
double f_8(const tGen *,int);
double f_10(const tGen *,int);
double f_11(const tGen *,int);
double f_12(const tGen *,int);
double f_13(const tGen *,int);
double f_14(const tGen *,int);
double f_15(const tGen *,int);
double fschaffer(const tGen *, int); 
double f8f2(const tGen *, int); 
double fschwefelmult(const tGen *x, int n);

double objfn(const tGen *x, int nvar);
double salomon(const tGen *x, int nvar); 
double whitely(const tGen *x, int nvar); 
double pn1(const tGen *x, int nvar);
double pn2(const tGen *x, int nvar);
double foxhole(const tGen *xs, int nvar);

#endif 
