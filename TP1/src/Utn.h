/*
 * utn.h
 *
 *  Created on: 7 abr. 2021
 *      Author: oscar
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * @fn float GetFloat(char[])
 * @brief Recibe un mensaje por parámetro y lo muestra por consola. Espera el ingreso
 * 		  de un dato de tipo float
 *
 * @param float numero
 * @return Retorna un dato de tipo float
 */
float GetFloat(char[]);

/**
 * @fn int GetInt(char[])
 * @brief Recibe un mensaje por parámetro y lo muestra por consola. Espera el ingreso
 * 		  de un dato de tipo int
 *
 * @param int numero
 * @return Retorna un dato de tipo int
 */
int GetInt(char[]);

/**
 * @fn char GetChar(char[])
 * @brief Recibe un mensaje por parámetro y lo muestra por consola. Espera el ingreso
 * 		  de un dato de tipo char
 *
 * @param char caracter
 * @return Retorna un dato de tipo char
 */
char GetChar(char[]);

/**
 * @fn int CompruebaDivisionPorCero(int)
 * @brief Recibe un dato de tipo int por parámetro y comprueba si es, o no, cero.
 *
 * @param int numero
 * @param int resultado
 * @return Si el número ingresado por parámetro es cero, retorna el resultado con un valor igual a cero.
 * 		   Si el número ingresado por parámetro es distinto de cero, retorna el resultado
 * 		   con un valor igual a uno.
 */
int CompruebaDivisionPorCero(int);


#endif /* UTN_H_ */
