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

#include "random.h"
#include <iostream>
#include <math.h>
#include <cassert>
#include "global.h"

using namespace std;

Random::Random(IRealRandom *random) {
	assert(random != NULL);
	this->random = random;
}

Random::~Random(void) {
	delete this->random;
}

double Random::normal(double desv) {
  double u1, u2;
  double result;
  
  do {
    u1=Random::rand();
  } while (u1 == 0);

  u2=Random::rand();
  result = desv * sqrt (-2*log(u1)) * sin (2*PI*u2);
  
  return result;
}
