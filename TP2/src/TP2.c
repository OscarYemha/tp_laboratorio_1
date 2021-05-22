/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "UTN.h"
#define QTYEMPLOYEES 1000

int main(void) {

	setbuf(stdout, NULL);
	Employee employeesList[QTYEMPLOYEES];
	int answer;
	int option;
	int index;
	int checkAdd;
	int idRemoveEmployee;
	int checkOperation;
	int answerEdit;
	int optionEdit;
	int answerShowReport;
	int optionShowReport;
	int order;

	initEmployees(employeesList, QTYEMPLOYEES);


	do
	{
		answer = utn_getNumero(&option, "Bienvenido. Ingrese una opción:\n"
										"1.ALTAS\n"
										"2.MODIFICAR\n"
										"3.BAJAS\n"
										"4.INFORMAR\n"
										"5.SALIR\n",
										"Opción incorrecta. ",
										1, 5, 3);

		if(answer != -1)
		{
			switch(option)
			{
				case 1:
					index = findFreePlace(employeesList, QTYEMPLOYEES);
					checkAdd = addEmployee(employeesList, QTYEMPLOYEES, index);
					checkCreatedEmployee(checkAdd);
				break;
				case 2:
					do
					{
						answerEdit = utn_getNumero(&optionEdit, "Ingrese una opción:\n"
															"1.MODIFICAR NOMBRE\n"
															"2.MODIFICAR APELLIDO\n"
															"3.MODIFICAR SALARIO\n"
															"4.MODIFICAR SECTOR\n"
															"5.VOLVER\n",
															"Opción incorrecta. ",
															1, 5, 3);
						if(answerEdit != -1)
						{
							switch(optionEdit)
							{
								case 1:
									checkOperation = editEmployeeName(employeesList, QTYEMPLOYEES);
									checkOperationEmployee(checkOperation);
								break;
								case 2:
									checkOperation = editEmployeeLastName(employeesList, QTYEMPLOYEES);
									checkOperationEmployee(checkOperation);
								break;
								case 3:
									checkOperation = editEmployeeSalary(employeesList, QTYEMPLOYEES);
									checkOperationEmployee(checkOperation);
								break;
								case 4:
									checkOperation = editEmployeeSector(employeesList, QTYEMPLOYEES);
									checkOperationEmployee(checkOperation);
								break;
							}
						}
					}while(optionEdit != 5);

				break;
				case 3:
					idRemoveEmployee = findEmployeeById(employeesList, QTYEMPLOYEES);
					checkOperation = removeEmployee(employeesList, QTYEMPLOYEES, idRemoveEmployee);
					checkOperationEmployee(checkOperation);
				break;
				case 4:
					do
					{
						answerShowReport = utn_getNumero(&optionShowReport, "Ingrese una opción:\n"
																			"1.Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
																			"2.Total y promedio de los salarios, cantidad de Empleados que superan el promedio\n"
																			"3.VOLVER\n",
																			"Opción incorrecta. ",
																			1, 3, 3);
						if(answerShowReport != -1)
						{
							switch(optionShowReport)
							{
								case 1:
									order = getOrder();
									sortEmployees(employeesList, QTYEMPLOYEES, order);
									printEmployees(employeesList, QTYEMPLOYEES);
								break;
								case 2:
									printSalary(employeesList, QTYEMPLOYEES);
									employeesSalaryMoreThanAverage(employeesList, QTYEMPLOYEES);
								break;
							}
						}
					}while(optionShowReport != 3);
				break;
			}
		}

	}while(option != 5);

	printf("¡Gracias por utilizar este programa!\n");

	return EXIT_SUCCESS;
}
