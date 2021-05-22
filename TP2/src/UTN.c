/*
 * UTN.c
 *
 *  Created on: 15 may. 2021
 *      Author: oscar
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"



int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno;


    retorno = -1;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%d", &bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos --;
            }
        }while(reintentos >= 0);
    }

    return retorno;
}

