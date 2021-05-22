/*
 Yemha, Oscar Ismael

 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
2
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "OperacionesMatematicas.h"
#include "Utn.h"


int main(void) {

	int opcion;
	int banderaPrimerOperando;
	int banderaSegundoOperando;
	int banderaOperacionesRealizadas;
	int primerOperando;
	int segundoOperando;
	int resultadoSuma;
	int resultadoResta;
	int compruebaDivision;
	float resultadoDivision;
	int resultadoMultiplicacion;
	long long int resultadoFactorialA;
	long long int resultadoFactorialB;
	setbuf(stdout,NULL);

	banderaPrimerOperando = 0;
	banderaSegundoOperando = 0;
	banderaOperacionesRealizadas = 0;


	do{
		system("clear");
		if(banderaPrimerOperando == 0)
		{
			printf("1. Ingresar 1er operando (A = x)\n");
		}
		else
		{
			printf("1. Ingresar 1er operando (A = %d)\n", primerOperando);
		}

		if(banderaSegundoOperando == 0)
		{
			printf("2. Ingresar 2do segundo operando (B = y)\n");
		}
		else
		{
			printf("2. Ingresar 2do segundo operando (B = %d)\n", segundoOperando);
		}
		printf("3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\nElija una opción: ");

		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				printf("Ingrese el 1er operando: ");
				scanf("%d", &primerOperando);
				banderaPrimerOperando = 1;
			break;
			case 2:
				printf("Ingrese el 2do operando: ");
				scanf("%d", &segundoOperando);
				banderaSegundoOperando = 1;
			break;
			case 3:
				if(banderaPrimerOperando == 0 || banderaSegundoOperando == 0)
				{
					printf("Para realizar los cálculos deben ingresarse los dos operandos\nPresione enter para continuar:");
					__fpurge(stdin);
					getchar();
				}
				else
				{
					banderaOperacionesRealizadas = 1;
					printf("a) Calcular la suma ((%d)+(%d))\n", primerOperando, segundoOperando);
					printf("b) Calcular la resta ((%d)-(%d))\n", primerOperando, segundoOperando);
					printf("c) Calcular la división ((%d)/(%d))\n", primerOperando, segundoOperando);
					printf("d) Calcular la multiplicación ((%d)*(%d))\n", primerOperando, segundoOperando);
					printf("e) Calcular el factorial ((!%d) y (!%d))\n", primerOperando, segundoOperando);
					printf("Presione enter para continuar: ");
					__fpurge(stdin);
					getchar();
				}
			break;
			case 4:
				if(banderaOperacionesRealizadas == 0)
				{
					printf("Para informar los resultados primero debe calcularlos.\nPresione enter para continuar: ");
					__fpurge(stdin);
					getchar();
				}
				else
				{
					resultadoSuma = SumarDosNumeros(primerOperando, segundoOperando);
					printf("El resultado de (%d)+(%d) es: %d\n", primerOperando, segundoOperando, resultadoSuma);

					resultadoResta = RestarDosNumeros(primerOperando, segundoOperando);
					printf("El resultado de (%d)-(%d) es: %d\n", primerOperando, segundoOperando, resultadoResta);

					compruebaDivision = CompruebaDivisionPorCero(segundoOperando);
					if(compruebaDivision == 0)
					{
						printf("No se puede dividir un número por 0\n");
					}
					else
					{
						resultadoDivision = DividirDosNumeros(primerOperando, segundoOperando);
						printf("El resultado de (%d)/(%d) es: %.2f\n", primerOperando, segundoOperando, resultadoDivision);
					}

					resultadoMultiplicacion = MultiplicarDosNumeros(primerOperando, segundoOperando);
					printf("El resultado de (%d)*(%d) es: %d\n", primerOperando, segundoOperando, resultadoMultiplicacion);

					resultadoFactorialA = FactorialDeUnNumero(primerOperando);
					resultadoFactorialB = FactorialDeUnNumero(segundoOperando);
					if(resultadoFactorialA == 0)
					{
						printf("No se puede realizar el factorial de un número negativo.\n");
					}
					else
					{
						if(resultadoFactorialA < 0)
						{
							printf("No se puede realizar el factorial de %d porque excede la capacidad de esta calculadora.\n", primerOperando);
						}
						else
						{
							printf("El factorial de %d es: %lld\n", primerOperando, resultadoFactorialA);
						}
					}
					if(resultadoFactorialB == 0)
					{
						printf("No se puede realizar el factorial de un número negativo.\n");
					}
					else
					{
						if(resultadoFactorialB < 0)
						{
							printf("No se puede realizar el factorial de %d porque excede la capacidad de esta calculadora.\n", segundoOperando);
						}
						else
						{
							printf("El factorial de %d es: %lld\n", segundoOperando, resultadoFactorialB);
						}
					}

					printf("Presione enter para continuar: ");
					__fpurge(stdin);
					getchar();
				}
			break;
			default:
			break;
		}

	}while(opcion != 5);

	printf("Gracias por utilizar este programa. ¡Hasta la próxima!");

	return EXIT_SUCCESS;
}
