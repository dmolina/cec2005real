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

/* Declaration for random number related variables and routines */

# ifndef _RAND_H
# define _RAND_H

# define SIMPLE_SPRNG
//# include "sprng/include/sprng.h"
# define SEED 01234567

#include "random.h"

/* Function declarations for the random number generator */
void randomize();
long double randomperc();
int rnd (int low, int high);
long double rndreal (long double low, long double high);
void initrandomnormaldeviate();
long double noise (long double mu, long double sigma);
long double randomnormaldeviate();

# endif
