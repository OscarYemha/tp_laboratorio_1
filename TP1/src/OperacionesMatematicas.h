/*
 * OperacionesAlgebraicas.h
 *
 *  Created on: 6 abr. 2021
 *      Author: Yemha, Oscar Ismael
 */

#ifndef OPERACIONESMATEMATICAS_H_
#define OPERACIONESMATEMATICAS_H_

/**
 * @fn int SumarDosNumeros(int, int)
 * @brief Calcula la suma de dos números recibidos por parámetro
 *
 * @param int numeroUno
 * @param int numeroDos
 * @param int resultado
 * @return El resultado de la suma de numeroUno más numeroDos, un dato de tipo int.
 */
int SumarDosNumeros(int,int);


/**
 * @fn int RestarDosNumeros(int, int)
 * @brief Calcula el resultado de la resta de dos números recibidos por parámetro.
 *
 * @param int numeroUno
 * @param int numeroDos
 * @param int resultado
 * @return El resultado de la resta de numeroUno menos numeroDos, un dato de tipo int.
 */
int RestarDosNumeros(int,int);

/**
 * @fn int MultiplicarDosNumeros(int, int)
 * @brief Calcula la multiplicación de dos números recibidos por parámetro.
 *
 * @param int numeroUno
 * @param int numeroDos
 * @param int resultado
 * @return El resultado de la multiplicación de numeroUno por numeroDos, un dato de tipo int.
 */
int MultiplicarDosNumeros(int, int);

/**
 * @fn float DividirDosNumeros(int, int)
 * @brief Calcula la división de dos números recibidos por parámetro.
 *
 * @param int numeroUno
 * @param int numeroDos
 * @param float resultado
 * @return El resultado de la división de numeroUno sobre numeroDos, un dato de tipo float. En el caso de que
 * 		   el número recibido por parámetro sea menor a cero, retorna a resultado con el valor igual a cero.
 */
float DividirDosNumeros(int, int);

/**
 * @fn long long int FactorialDeUnNumero(int)
 * @brief Calcula el factorial de un número recibido por parámetro.
 *
 * @param int numero;
 * @param long long int resultado
 * @return El resultado del factorial de un número, un dato de tipo long long int. En el caso de que
 * 		   el número recibido por parámetro sea menor a cero, retorna a resultado con el valor igual a cero.
 *
 */
long long int FactorialDeUnNumero(int);

#endif /* OPERACIONESMATEMATICAS_H_ */
