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

#ifndef _CEC2005_H 

#define _CEC2005_H 1

#define _MAIN 1

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include "global.h"
#include "sub.h"
#include "define.h"

using namespace std;

#ifndef _tGen
typedef long double tGen;
#define _tGen
#endif

/**
 * Este método permite indicar si debe de comprobar los límites
 * 
 * @return booleano que indsica si se debe de comprobar o no
 */
bool isBound_cec2005(void);

/**
 * Este método permite iniciar el modo de funcionamiento de las funciones del CEC2005
 *
 * @param nfun función a evaluar
 * @param dim dimensión
 */
void init_cec2005(int nfun, int dim);

/**
 * Función de evaluación 
 *
 * @param x solución a evaluar (iniciada en la posición 0)
 * @param ndim Longitud de la dimensión (se ignora)
 */
double eval_cec2005(const long double *x, int ndim);
double eval_cec2005(const double *x, int ndim);


/**
 * Permite liberar recursos cuando ya no se vaa a realizar más evaluaciones
 *
 */
void finish_cec2005(void); 

/**
 * ste método permite obtener información sobre la función
 * @param fun identificador de la función
 * @param name Nombre de la función.
 * @param min valor mínimo del rango
 * @param max valor máximo del rango
 * @param optime valor optimo a comprobar
 */
void getInfo_cec2005(int fun, char *name, double *min, double *max, double *optime);

void set_directory(char*dir);

#endif
