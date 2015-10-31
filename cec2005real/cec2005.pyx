#!python
#cython: language_level=2, boundscheck=False
from os import path
from pkg_resources import resource_filename
from libc.stdlib cimport malloc, free
import cython
from libcpp cimport bool

cdef extern from "cec2005.h":
    bool isBound_cec2005()
    void init_cec2005(int nfun, int dim)
    double eval_cec2005(const double *x, int ndim)
    double eval_cec2005(const long double *x, int ndim)
    void getInfo_cec2005(int fun, char *name, double *min, double *max, double *optime)
    void set_directory(char *dir)

cpdef set_function(int fun, int dim):
    init_cec2005(fun, dim)

cdef int m_fun
cdef int m_dim

def _cec2005_eval_func(double[::1] x):
    cdef int dim
    cdef double fitness
    cdef double * sol

    dim = x.shape[0]

    sol = <double *> malloc(dim * cython.sizeof(double))

    if sol is NULL:
        raise MemoryError()

    for i in xrange(dim):
        sol[i] = x[i]

    fitness = eval_cec2005(sol, dim)
    free(sol)
    return fitness

cpdef get_num_functions(self):
    return 25

cpdef _get_info(int fun, int dim):
    """
    Return the lower bound of the function
    """
    cdef double optimum
    cdef double minvalue, maxvalue
    cdef char* name = <char *> malloc(300)
    optimum = 0
    getInfo_cec2005(fun, name, &minvalue, &maxvalue, &optimum)

    return {'lower': minvalue, 'upper': maxvalue, 'threshold': 1e-8,
           'best': optimum, 'dimension': dim}

cdef class Function:
    cdef int fun
    cdef int dim
    
    def __init__(self, int fun, int dim):
        self.fun = fun
        self.dim = dim
        """
        Evaluate the solution
        """
        cdef bytes dir_name = resource_filename("cec2005real", "cdatafiles").encode()
        set_directory(dir_name)
        init_cec2005(fun, dim)
    

    cpdef info(self):
        return _get_info(self.fun, self.dim)
    
    cpdef get_dim(self):
        return self.dim

##     def __dealloc(self):
##         free_func()

    cpdef get_eval_function(self):
        return _cec2005_eval_func
