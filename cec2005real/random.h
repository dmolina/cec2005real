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

#ifndef _IRANDOM_H

#define _IRANDOM_H

/**
 * @class IRealRandom
 *
 * This class generates a new real value randomly
 * It is used by class Random to create all individuals
 */
class IRealRandom {
       /**
	* @return A random double between 0 and 1 
	*/
public:
       virtual double rand(void)=0;
};


/**
 * @class Random
 *
 * @ingroup realea_common

 * @brief This class generates number randomly.
 *
 */
class Random {
   public:
       /**
	* Constructor. It requires a simple number generator
	*
	* @param random real random generator
	*/
	Random(IRealRandom *random);
	/**
	 * Destructor. Release the IRealRandom object
	 */
	~Random(void); 

       /**
	* @return A random double between 0 and 1 
	*/
       double rand(void) {
	   return this->random->rand();
       }


       /**
	* Generates randomly a integer between low and high
	*
	* @param low lowest value
	* @param high higher value
	* 
	* @return an integer in [low, high] randomly generated
	*/
       int randint(unsigned low, unsigned high) {
	  double random;

	  random = Random::rand();
	  return ( (int) (low + (high-low+1)*random) );
       }

       /**
	* Generates randomly a double between low and high
	*
	* @param low lowest value
	* @param high higher value
	* 
	* @return a double in [low, high] randomly generated
	*/
       double randreal(double low, double high) {
	  return (low + (high-low)*Random::rand());
       }


       /**
	* Generate a double number following a normal distribution with 
	* center in 0 and std as its standard desviation
	*
	* @param std Standard Deviation
	* @return a double in the range [0,1]
	*/
	virtual double normal(double desv);

	/**
	 * return a position value of a vector positions
	 *
	 * @param sample array of positions
	 * @param pmax maximum size of sample, it is modified
	 *
	 * @return a position randomly chosen
	 */
	int getSample(int *sample, int *pmax); 
	private:
	IRealRandom *random; /** < Generator of new number */
};

typedef Random* RandomPtr;

#endif
