/*
 * ArrayEmployees.c
 *
 *  Created on: 15 may. 2021
 *      Author: oscar
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#define FALSE 0
#define TRUE 1


/** \brief Inicializa en 0 (TRUE) a todos los empleados
 *
 * \param Employee employeesList[] array de empleados
 * \param qtyEmployees int largo del array
 * \return void
 */
void initEmployees(Employee employeesList[], int qtyEmployees)
{
	int i;

	for(i=0; i<qtyEmployees; i++)
	{
		employeesList[i].isEmpty = TRUE;
	}
}


/** \brief busca lugar para crear un empleado
 *
 * \param  Employee employeesList[]
 * \param int qtyEmployees
 * \return int devuelve la posicion donde crearlo
 */

int findFreePlace(Employee employeesList[], int qtyEmployees)
{
	int i;
	int index;

	index = -1;

	for(i=0; i<qtyEmployees; i++)
		{
			if(employeesList[i].isEmpty == TRUE)
			{
				index = i;
				break;
			}
		}
	return index;
}

/** \brief Crea automaticamente una id para la estructura Employee
 *
 * \param Employee employeesList[] array de empleados
 * \param qtyEmployees int largo del array
 * \return int devuelve número de id
 */
int createEmployeeId(Employee employeesList[], int qtyEmployees)
{
	int i;
	int id = 1;

	for (i = 0; i < qtyEmployees; i++) {
		if (employeesList[i].isEmpty == FALSE) {
			id ++;
		}
	}
	return id;
}


int addEmployee(Employee employeesList[], int qtyEmployees, int index)
{
	int retorno;

	retorno = -1;

	if(index == -1)
	{
		printf("No hay lugares libres para cargar más empleados.\n");
	}
	else
	{
		retorno = createEmployee(employeesList, qtyEmployees, index);
	}

	return retorno;
}

/** \brief Llena los campos de la estructura Employee
 *
 * \param Employee employeesList[] array de empleados
 * \param qtyEmployees int largo del array
 * \param index int lugar del array empleados donde se guardará el nuevo empleado
 * \return int para chequear que se cargó el empleado
 */
int createEmployee(Employee employeesList[], int qtyEmployees, int index)
{
	int rtn;


	printf("Ingrese el nombre: ");
	__fpurge(stdin);
	fgets(employeesList[index].name, 51, stdin);

	printf("Ingrese el apellido: ");
	__fpurge(stdin);
	fgets(employeesList[index].lastName, 51, stdin);

	printf("Ingrese el salario: ");
	scanf("%f", &employeesList[index].salary);

	printf("Ingrese el sector: 1 para Sistemas, 2 para Soporte, 3 para Administración :");
	scanf("%d", &employeesList[index].sector);

	employeesList[index].id = createEmployeeId(employeesList, qtyEmployees);

	employeesList[index].isEmpty = FALSE;
	rtn = 1;

	return rtn;
}

/** \brief Chequea e informa si se creó o no el empleado
 *
 * \param int cheackAdd

 * \return void
 */
void checkCreatedEmployee(int checkAdd)
{
	if(checkAdd == -1)
	{
		printf("Empleado no creado.\nPresione Enter para continuar");
		__fpurge(stdin);
		getchar();
	}
	else
	{
		printf("Empleado creado.\nPresione Enter para continuar");
		__fpurge(stdin);
		getchar();
	}
}

/** \brief Chequea si hay un lugar vacío
 *
 * \param Employee employeesList[] array de empleados
 * \param int qtyEmployees
 * \return int
 */
int checkEmptyList(Employee employeesLists[], int qtyEmployees)
{
	int i;
	int retorno;

	retorno = 0;

	for(i=0;i<qtyEmployees; i++)
	{
		if(employeesLists[i].isEmpty == FALSE)
		{
			retorno = 1;
			break;
		}
	}

	return retorno;
}

/** \brief chequea que haya empleados cargados y si los hay pide el id de un empleado,
 * lo busca, imprime sus datos y devuelve su id.
 *
 *\param list[] Employee array de empleados
 * \param len int largo del array
 * \return int devuelve el id si el empleado existe, sino devuelve 0
 *
 */
int findEmployeeById(Employee employeesList[], int qtyEmployees)
{
	int rtn;
	int dato;
	int id;

	rtn = 0;

	dato = checkEmptyList(employeesList, qtyEmployees);

	if(dato == 0)
	{
		printf("No hay empleados dados de alta.\nPresione Enter para continuar");
		__fpurge(stdin);
		getchar();
	}
	else
	{
		sortEmployees(employeesList, qtyEmployees, -1);
		printEmployees(employeesList, qtyEmployees);
		printf("Ingrese el ID del empleado: ");
		scanf("%d", &id);
		rtn = id;
	}


	return rtn;
}

/** \brief Imprime listado de empleados
 *
 * \param Employee employeesList[] array de empleados
 * \param int qtyEmployees largo del array
 * \return void
 */
void printEmployees(Employee employeesList[], int qtyEmployees)
{
	int i;

	printf("ID Apellido Nombre Salario Sector\n");
	for(i=0;i<qtyEmployees;i++)
	{
		if(employeesList[i].isEmpty == FALSE)
		{
			printAnEmployee(employeesList[i]);
		}
	}
}

/** \brief Imprime los datos de un empleado
 *
 * \param Employee employeesList array de empleados
 * \return void
 */
void printAnEmployee(Employee employeesList)
{
	printf("%4d %10s %10s %4.2f %4d\n", employeesList.id,
							   	   	    employeesList.lastName,
										employeesList.name,
										employeesList.salary,
										employeesList.sector);
}

/** \brief Remueve un empleado por id (baja logica)
 *
 * \param employeesList[] Employee array empleados
 * \param qtyEmployees int largo del array
 * \return int -2 si no existe, 1 si se realizó, 0 si se canceló, -1 si no se encontró
 */
int removeEmployee(Employee employeesList[], int qtyEmployees, int id)
{
	int i;
	int rtn;
	char option;

	rtn = -2;

	if(id != 0)
	{
		for(i=0;i<qtyEmployees;i++)
		{
			if(employeesList[i].id == id)
			{
				printf("¿Desea eliminar? S/N ");
				__fpurge(stdin);
				scanf("%c", &option);
				option = tolower(option);
				if(option == 's')
				{
					employeesList[i].isEmpty = TRUE;
					rtn = 1;
					break;
				}
				else
				{
					rtn = 0;
					break;
				}
			}
			else
			{
				rtn = -1;
				break;
			}
		}
	}

	return rtn;
}

/** \brief chequea la operacion realizada
 *
 * \param int checkOperation
 * \return void
 */
void checkOperationEmployee(int checkOperation)
{
	if(checkOperation == 1)
	{
		printf("Operación realizada.\nPresione Enter para continuar");
		__fpurge(stdin);
		getchar();
	}
	else
	{
		if(checkOperation == 0)
		{
			printf("Operación cancelada.\nPresione Enter para continuar");
			__fpurge(stdin);
			getchar();

		}

		if(checkOperation == -1)
		{
			printf("ID no encontrado.\nPresione Enter para continuar");
			__fpurge(stdin);
			getchar();
		}
	}
}

/** \brief edita nombre de un empleado
 *
 * \param Employee employeesList[]
 * \param int qtyEmployees
 * \return int
 */
int editEmployeeName(Employee employeesList[], int qtyEmployees)
{
	int id;
	int i;
	char option;
	int rtn;

	rtn = -2;

	id = findEmployeeById(employeesList, qtyEmployees);

	if(id != 0)
	{
		for (i = 0; i < qtyEmployees; i++)
		{
			if (employeesList[i].isEmpty == FALSE && id == employeesList[i].id)
			{
				printf("¿Desea realizar la operación? S/N: ");
				__fpurge(stdin);
				scanf("%c", &option);
				option = tolower(option);
				if(option == 's')
				{
					printf("Ingrese el nuevo nombre: ");
					__fpurge(stdin);
					fgets(employeesList[i].name, 51, stdin);
					rtn = 1;
					break;
				}
				else
				{
					rtn = 0;
					break;
				}

			}
			else
			{
				rtn = -1;
				break;
			}

		}
	}
	return rtn;
}

/** \brief edita apellido de un empleado
 *
 * \param Employee employeesList[]
 * \param int qtyEmployees
 * \return int
 */
int editEmployeeLastName(Employee employeesList[], int qtyEmployees)
{
	int id;
	int i;
	char option;
	int rtn;

	rtn = -2;

	id = findEmployeeById(employeesList, qtyEmployees);

	if(id != 0)
	{
		for (i = 0; i < qtyEmployees; i++)
		{
			if (employeesList[i].isEmpty == FALSE && id == employeesList[i].id)
			{
				printf("¿Desea realizar la operación? S/N: ");
				__fpurge(stdin);
				scanf("%c", &option);
				option = tolower(option);
				if(option == 's')
				{
					printf("Ingrese el nuevo apellido: ");
					__fpurge(stdin);
					fgets(employeesList[i].lastName, 51, stdin);
					rtn = 1;
					break;
				}
				else
				{
					rtn = 0;
					break;
				}
			}
			else
			{
				rtn = -1;
				break;
			}
		}
	}
	return rtn;
}

/** \brief edita salario de un empleado
 *
 * \param Employee employeesList[]
 * \param int qtyEmployees
 * \return int
 */
int editEmployeeSalary(Employee employeesList[], int qtyEmployees)
{
	int id;
	int i;
	char option;
	int rtn;

	rtn = -2;

	id = findEmployeeById(employeesList, qtyEmployees);

	if(id != 0)
	{
		for (i = 0; i < qtyEmployees; i++) {
			if (employeesList[i].isEmpty == FALSE && id == employeesList[i].id)
			{
				printf("¿Desea realizar la operación? S/N: ");
				__fpurge(stdin);
				scanf("%c", &option);
				option = tolower(option);
				if(option == 's')
				{
					printf("Ingrese el nuevo salario: ");
					scanf("%f", &employeesList[i].salary);
					break;
				}
				else
				{
					rtn = 0;
					break;
				}
			}
			else
			{
				rtn = -1;
				break;
			}
		}
	}
	return rtn;
}

/** \brief edita sector de un empleado
 *
 * \param Employee employeesList[]
 * \param int qtyEmployees
 * \return int
 */
int editEmployeeSector(Employee employeesList[], int qtyEmployees)
{
	int id;
	int i;
	char option;
	int rtn;

	rtn = -2;

	id = findEmployeeById(employeesList, qtyEmployees);
	if(id != 0)
	{
		for (i = 0; i<qtyEmployees; i++) {
			if (employeesList[i].isEmpty == FALSE && id == employeesList[i].id)
			{
				printf("¿Desea realizar la operación? S/N: ");
				__fpurge(stdin);
				scanf("%c", &option);
				option = tolower(option);
				if(option == 's')
				{
					printf("Ingrese el nuevo sector: 1 para Sistemas, 2 para Soporte, 3 para Administración: ");
					scanf("%d", &employeesList[i].sector);
					rtn = 1;
					break;
				}
				else
				{
					rtn = 0;
					break;
				}
			}
			else
			{
				rtn = -1;
				break;
			}
		}
	}
	return rtn;
}

/** \brief suma el total de los salarios de los empleados
 *
 * \param Employee employeesList[]
 * \param int qtyEmployees
 * \return float devuelve el monto total
 */
float salarySum(Employee employeesList[], int qtyEmployees)
{
	float aux;
	int i;

	aux = 0;

	for (i=0; i<qtyEmployees; i++) {
		if (employeesList[i].isEmpty == FALSE){
			aux += employeesList[i].salary;
		}
	}
	return aux;
}

/** \brief promedia los salarios de todos los empleados
 *
 * \param  Employee employeesList[]  array de empleados
 * \param int qtyEmployees largo del array
 * \return float devuelve el promedio
 */
float salaryAverage(Employee employeesList[], int qtyEmployees)
{
	int i;
	int count;
	float average;

	count = 0;
	average = 0;

	for (i=0; i<qtyEmployees; i++)
	{
		if (employeesList[i].isEmpty == FALSE)
		{
			count++;
		}
	}

	if(count == 0)
	{
		count = 1;
	}

	average = salarySum(employeesList, qtyEmployees) / count;

	return average;
}

/** \brief lista los empleados con un salario mayor al promedio e informa la cantidad
 *
 * \param Employee employeesList[]  array de empleados
 * \param int qtyEmployees largo del array
 * \return void
 */
void employeesSalaryMoreThanAverage(Employee employeesList[], int qtyEmployees)
{
	int i;
	int count;
	float aux;

	count = 0;
	aux = 0;

	aux = salaryAverage(employeesList, qtyEmployees);

	for (i=0; i<qtyEmployees; i++)
	{
		if (employeesList[i].isEmpty == FALSE && employeesList[i].salary > aux)
		{
			count++;
		}
	}
	printf("La cantidad de empleados que superan el salario promedio es de: %d\n",	count);
}

/** \brief informa al usuario valores de los salarios
 *
 * \param Employee employeesList[] array de empleados
 * \param len int largo del array
 * \return void
 */
void printSalary(Employee employeesList[], int qtyEmployees)
{
	float salariesSum;
	float salariesAverage;

	salariesSum = 0;
	salariesAverage = 0;

	salariesSum = salarySum(employeesList, qtyEmployees);
	salariesAverage = salaryAverage(employeesList, qtyEmployees);

	printf("\nEl total de salarios es de: $%.2f", salariesSum);
	printf("\nEl promedio de los salarios es de: $%.2f\n",	salariesAverage);
}

/** \brief Pregunta y obtiene criterio de ordenamiento
 *
 * \param void
 * \return int
 */
int getOrder(void)
{
	int order;

	order = -1;

	printf("Ingrese el criterio de ordenamiento: 1 para ascendente, 2 para descendente: ");
	scanf("%d", &order);

	return order;
}

/** \brief Ordena empleados por nombre y sector según criterio
 *
 * \param Employee employeesList[] array empleados
 * \param qtyEmployees int largo del array
 * \param order para definir criterio
 * \return int
 */
int sortEmployees(Employee employeesList[], int qtyEmployees, int order) {
	int i;
	int j;
	Employee aux;


	if (employeesList != NULL && qtyEmployees > 0)
	{
		for (i=0; i<qtyEmployees - 1; i++)
		{
			for (j=i+1; j<qtyEmployees; j++)
			{
				switch(order)
				{
				case 1:
					if (strcmp(employeesList[i].lastName, employeesList[j].lastName) > 0)
					{
						aux = employeesList[i];
						employeesList[i] = employeesList[j];
						employeesList[j] = aux;
					}
					else
					{
						if (strcmp(employeesList[i].lastName, employeesList[j].lastName) == 0)
						{
							if (employeesList[i].sector > employeesList[j].sector)
							{
								aux = employeesList[i];
								employeesList[i] = employeesList[j];
								employeesList[j] = aux;
							}
						}
					}
				break;
				case 2:
					if (strcmp(employeesList[j].lastName, employeesList[i].lastName) > 0)
					{
						aux = employeesList[i];
						employeesList[i] = employeesList[j];
						employeesList[j] = aux;
					}
					else
					{
						if (strcmp(employeesList[i].lastName, employeesList[j].lastName) == 0)
						{
							if (employeesList[j].sector > employeesList[i].sector)
							{
								aux = employeesList[i];
								employeesList[i] = employeesList[j];
								employeesList[j] = aux;
							}
						}
					}
				break;
				case -1:
					if(employeesList[i].id > employeesList[j].id)
					{
						aux = employeesList[i];
						employeesList[i] = employeesList[j];
						employeesList[j] = aux;
					}
				break;
				}
			}
		}
	}
	return 0;
}
