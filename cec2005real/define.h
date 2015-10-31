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

#ifndef _DEFINE_H

#define _DEFINE_H 1

/// @defgroup realea_common Real Evolutionary Algorithms Common (Core classes)

#include <iostream>
#include "real.h"


namespace realea {

class IEval {
   public:
	virtual tFitness eval(const tChromosomeReal &sol)=0;
	virtual ~IEval(void) {}
};

class IFinish {
   public:
    virtual bool isFinish(void)=0;
    virtual ~IFinish(void) {}
};

}

#endif
