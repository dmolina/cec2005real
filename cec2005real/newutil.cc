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

#include "newutil.h"

MyReturnMatrix sqrt(const MyMatrix &mat) {
    Real *v_mat = mat.Store();
    int n = mat.Storage();
    Matrix result(mat.Nrows(),mat.Ncols());
    Real v_result[n];
 
    std::transform(v_mat, v_mat+n, v_result, sqrt_double);
    result <<v_result;
    result.Release();
    return result;
}

double log_double(double x) {
    return log(x);
}


MyReturnMatrix log(const MyMatrix &mat) {
    Real *v_mat = mat.Store();
    int n = mat.Storage();
    Matrix result(mat.Nrows(),mat.Ncols());
    Real v_result[n];
 
    std::transform(v_mat, v_mat+n, v_result, log_double);
    result <<v_result;
    result.Release();
    return result;
}

MyReturnMatrix pow(const ColumnVector &mat, double exp) {
    int n=mat.Nrows();
    ColumnVector result(n);
    int i;

    for (i = 0; i < n; i++) {
	result[i] = pow(mat[i], exp);
    }
 
    result.Release();
    return result;
}

MyReturnMatrix pow2_m(const MyMatrix &mat) {
    Real *v_mat = mat.Store();
    int n = mat.Storage();
    Matrix result(mat.Nrows(),mat.Ncols());
    Real v_result[n];
 
    std::transform(v_mat, v_mat+n, v_result, pow2_double);
    result <<v_result;
    result.Release();
    return result;
}



Real mean(const ColumnVector &mat) {
    int i, n=mat.Nrows();
    Real sum;

    if (n == 0) {
	return 0;
    }

    for (i = 0, sum = 0; i < n; i++) {
	sum += mat[i]; 
    }

    return sum/n;
}

Real median(const ColumnVector &mat) {
    int n=mat.Nrows();

    if ( (n % 2) == 1) {
	return mat[n/2];
    }
    else {
	return (mat[n/2-1]+mat[n/2])/2;
    }
}

Real median(const RowVector &mat) {
    int n=mat.Ncols();

    if ( (n % 2) == 1) {
	return mat[n/2];
    }
    else {
	return (mat[n/2-1]+mat[n/2])/2;
    }
}


static Matrix *mat_sort;

void set_sort_matrix(Matrix *mat) {
    mat_sort = mat;
}

bool sort_index_matrix(int i, int j) {
    Real val1, val2;

    val1 = (*mat_sort)[0][i-1];
    val2 = (*mat_sort)[0][j-1];

    if (val1 < val2) {
	return true;
    }
    else {
	return false;
    }
}


MyReturnMatrix myprctile(RowVector &inar, int *perc, int nperc) {
    int N = inar.Ncols();
    // Indices para escoger los n mejores
    int arindex[N];
    RowVector result(nperc);
    int i;

    range(1, N, arindex);

    mat_sort = &inar;
    sort(arindex, arindex+N, sort_index_matrix);

    for (i = 0; i < nperc; i++) {
	int p = perc[i];

	if (p <= 100*(0.5/N)) {
	    result[i] = inar[arindex[0]-1];
	}
	else if (p >= 100*((N-0.5)/N)) {
	    result[i] = inar[arindex[N-1]-1];
	}
	else {
	   int pos = N*p/100;
	   result[i] = inar[arindex[pos]-1];
	}
    }

    return result;
}



Real mean_diag(const DiagonalMatrix &mat) {
    int i, n=mat.Nrows();
    Real sum;

    if (n == 0) {
	return 0;
    }

    for (i = 0, sum = 0; i < n; i++) {
	sum += mat[i]; 
    }

    return sum/n;
}

double pow2(double x) {
    return x*x;
}

double pow2_double(double x) {
    return pow2(x);
}

double sqrt_double(double x) {
    return sqrt(x);
}


void copyRow(queue<Real> num, RowVector &row) {
    Real val;
    int i=0;

    do {
	val = num.front();
	num.pop();
	row[i] = val;
	i += 1;
    } while (num.size() > 0);
}

MyReturnMatrix DotVectors(ColumnVector &A, const ColumnVector &B) {
    int N = A.Nrows();
    ColumnVector col(N);
    int i;

    for (i = 0; i < N; i++) {
	col[i] = A[i]*B[i];
    }
    
    col.Release();
    return col;
}

MyReturnMatrix DivVectors(ColumnVector &A, const ColumnVector &B) {
    int N = A.Nrows();
    ColumnVector col(N);
    int i;

    for (i = 0; i < N; i++) {
	col[i] = A[i]/B[i];
    }
    
    col.Release();
    return col;
}


void copyColumn(DiagonalMatrix diag, ColumnVector &row) {
    int n = diag.Nrows();
    int i;

    for (i = 0; i < n; i++) {
	row[i] = diag[i];
    }
}

void copyFromColumn(ColumnVector &row, DiagonalMatrix &diag) {
    int n = row.Nrows();
    int i;

    for (i = 0; i < n; i++) {
	diag[i] = row[i];
    }
}

Real min_positive(queue<Real> num) {
    Real result, val;
    int init=1;

    result = -1;

    do {
	val = num.front();
	num.pop();

	if (val > 0 && (val < result || init) ) {
	    result = val;
	    init = 0;
	}

    } while (num.size() > 0);

    if (init == 1) {
	throw string("Error, min_positive no encontró valor != 0");
    }
    else {
	return result;
    }
}

void range(int min, int max, int *Rang) {
    int i, value;
    int num=max-min+1;

    for (i =0, value=min; i < num; i++) {
	Rang[i] = value;
	value += 1;
    }
   
}

void getColumns(Matrix &m, int *cols, int num, Matrix &result) {
    int i, value;

    for (i = 0; i < num; i++) {
        value=cols[i];
	result.Column(i+1) = m.Column(value);
    }
}

double norm(const MyMatrix &mat) {
    DiagonalMatrix D;

    SVD(mat,D);
    return D.Maximum();
}

MyReturnMatrix eye(int N) {
    MyMatrix A(N,N);
    IdentityMatrix I(N);
    A << I;
    A.Release();
    return A;
}

MyReturnMatrix pow2(ColumnVector &weights) {
    int N = weights.Nrows();
    ColumnVector col(N);
    int i;

    for (i = 0; i < N; i++) {
	col[i] = pow2(weights[i]);
    }
    
    col.Release();
    return col;
}

MyReturnMatrix pow2(RowVector &weights) {
    int N = weights.Nrows();
    ColumnVector col(N);
    int i;

    for (i = 0; i < N; i++) {
	col[i] = pow2(weights[i]);
    }
    
    col.Release();
    return col;
}


Real min(ColumnVector &mat) {
    return mat.Minimum();
}

Real max(ColumnVector &mat) {
    return mat.Maximum();
}

