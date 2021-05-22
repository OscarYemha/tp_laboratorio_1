/*
 * ArrayEmployees.h
 *
 *  Created on: 15 may. 2021
 *      Author: oscar
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

void initEmployees(Employee employeesList[], int qtyEmployees);
int findFreePlace(Employee employeesList[], int qtyEmployees);
int createEmployeeId(Employee employeesList[], int qtyEmployees);
int addEmployee(Employee employeesList[], int qtyEmployees, int index);
int createEmployee(Employee employeesList[], int qtyEmployees, int index);
void checkCreatedEmployee(int checkAdd);
int checkEmptyList(Employee employeesLists[], int qtyEmployees);
int findEmployeeById(Employee employeesList[], int qtyEmployees);
void printEmployees(Employee employeesList[], int qtyEmployees);
void printAnEmployee(Employee employeesList);
int removeEmployee(Employee employeesList[], int qtyEmployees, int id);
void checkOperationEmployee(int checkOperation);
int editEmployeeName(Employee employeesList[], int qtyEmployees);
int editEmployeeLastName(Employee employeesList[], int qtyEmployees);
int editEmployeeSalary(Employee employeesList[], int qtyEmployees);
int editEmployeeSector(Employee employeesList[], int qtyEmployees);
float salarySum(Employee employeesList[], int qtyEmployees);
float salaryAverage(Employee employeesList[], int qtyEmployees);
void employeesSalaryMoreThanAverage(Employee employeesList[], int qtyEmployees);
void printSalary(Employee employeesList[], int qtyEmployees);
int getOrder(void);
int sortEmployees(Employee employeesList[], int qtyEmployees, int order);


#endif /* ARRAYEMPLOYEES_H_ */
