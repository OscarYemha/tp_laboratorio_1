/*
 * utn.c
 *
 *  Created on: 7 abr. 2021
 *      Author: oscar
 */
#include <stdio_ext.h>
#include <stdlib.h>


float GetFloat(char mensaje[])
{
	float numero;
	printf("%s", mensaje);
	scanf("%f", &numero);
	return numero;
}

int GetInt(char mensaje[])
{
	int numero;
	printf("%s", mensaje);
	scanf("%d", &numero);
	return numero;
}

char GetChar(char mensaje[])
{
	char caracter;
	printf("%s", mensaje);
	__fpurge(stdin);
	scanf("%c", &caracter);
	return caracter;
}


int CompruebaDivisionPorCero(int numero)
{
	int resultado;

	resultado = 1;

	if(numero == 0)
	{
		resultado = 0;
	}

	return resultado;
}

