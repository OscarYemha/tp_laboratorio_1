/*
 * OperacionesMatematicas.c
 *
 *  Created on: 6 abr. 2021
 *      Author: Oscar Ismael Yemha
 */
#include "OperacionesMatematicas.h"
#include "Utn.h"


int SumarDosNumeros(int numeroUno, int numeroDos)
{
	int resultado;

	resultado = numeroUno + numeroDos;

	return resultado;
}

int RestarDosNumeros(int numeroUno, int numeroDos)
{
	int resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}

int MultiplicarDosNumeros(int numeroUno, int numeroDos)
{
	int resultado;

	resultado = numeroUno * numeroDos;

	return resultado;
}



float DividirDosNumeros(int numeroUno, int numeroDos)
{
	float resultado;

	if(numeroUno == 0)
	{
		resultado = 0;
	}
	else
	{
		resultado = (float)numeroUno/numeroDos;
	}

	return resultado;
}

long long int FactorialDeUnNumero(int numero)
{
	int i;
	long long int resultado;

	resultado = 1;

	if(numero >= 0)
	{
		if(numero == 0 || numero == 1)
		{
			resultado = 1;
		}
		else
		{
			for(i=numero; i>0; i--)
			{
				resultado *= i;
			}
		}
	}
	else
	{
		resultado = 0;
	}

	return resultado;
}
