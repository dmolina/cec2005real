/**
 * Copyright 2008, Daniel Molina Cabrera <danimolina@gmail.com>
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
 * @file This file contains the definition of real chromosomes
 */
#ifndef _REALEA_REAL_H

#define _REALEA_REAL_H 1

#include <vector>

using namespace std;

#ifndef _tGen
typedef double tReal;
typedef tReal tGen;
#define _tGen

#endif


#ifndef _TFITNESS
typedef long double tFitness;
#define _TFITNESS 1
#endif 


namespace realea {

typedef vector<tReal> tChromosomeReal;

}

#endif
