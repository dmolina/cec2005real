PROJECT(cec2005 CXX)

SET(CECSRC
  cec2005
  random.cc
  srandom.cc
)

SET(SRC
aux.cc
def1.cc
def2.cc
def3.cc
def4.cc
#rand.cc
random.cc
srandom.cc
#sprng/SRC/lcg64/primes.c
#sprng/SRC/lcg64/lcg64.c
#sprng/SRC/cputime.c
#sprng/SRC/lfg/lfg.c
#sprng/SRC/cmrg/primes.c
#sprng/SRC/cmrg/cmrg.c
#sprng/SRC/store.c
#sprng/SRC/drand.c
#sprng/SRC/communicate.c
#sprng/SRC/lcg/lcg.c
#sprng/SRC/lcg/primes.c
#sprng/SRC/pmlcg/pmlcg.c
#sprng/SRC/simple.c
#sprng/SRC/mlfg/mlfg.c
#sprng/SRC/fwrap_mpi.c
#sprng/SRC/memory.c
#sprng/SRC/checkid.c
#sprng/SRC/check_gen_simple.c
#sprng/SRC/makeseed.c
#sprng/SRC/timing.c
#sprng/SRC/simple_mpi.c
#sprng/SRC/check_gen_ptr.c
#sprng/SRC/check_gen.c
)
ADD_LIBRARY(cec2005 SHARED ${CECSRC})
TARGET_LINK_LIBRARIES(cec2005)
#INSTALL(TARGETS cec2005 DESTINATION lib)
#INSTALL(FILES cec2005.h DESTINATION include)
#INSTALL(DIRECTORY input_data DESTINATION include/cec2005) 

#ADD_EXECUTABLE(test test.cc)
#TARGET_LINK_LIBRARIES(test cec2005)
