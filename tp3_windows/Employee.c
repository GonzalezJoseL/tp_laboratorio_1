#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
//#include "Controller.h"

int idAutoIncremental=1001; // NO PUEDE ESTAR SETEADO PQ CUANDO GUARDE EL ARCHIVO YA PODRIA EXISTIR UN 1000

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee=employee_new();
    if(pEmployee!=NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {

        employee_setId(pEmployee,atoi(idStr));
        employee_setNombre(pEmployee,nombreStr);
        employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr));
        employee_setSueldo(pEmployee,atoi(sueldoStr));

    }
    return pEmployee;
}
int employee_delete(Employee* this)
{
    int retorno=-1;
    if(this != NULL)
    {
        free(this);
        retorno=0;
    }
    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    if (this != NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id=this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno=0;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=-1;
	if(this != NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=-1;
	if(this != NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;
	if(this != NULL)
	{
		this->sueldo=sueldo;
		retorno=0;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=-1;
	if(this != NULL)
	{
		*sueldo=this->sueldo;
		retorno=0;
	}
	return retorno;
}

int employee_autoId()
{
	return idAutoIncremental++;
}

void employee_print(Employee* this)
{
	int id, horasTrabajadas, sueldo;
	char nombre[200];

	if (
	employee_getId(this, &id) == 0 &&
	employee_getNombre(this, nombre) == 0 &&
    employee_getHorasTrabajadas(this, &horasTrabajadas) == 0 &&
    employee_getSueldo(this, &sueldo) == 0)

	{
    printf("ID: %3d 		NOMBRE: %-10s		HORAS TRABAJADAS: %d			SUELDO: %d \n",id,nombre,horasTrabajadas,sueldo);
	}
}

int employee_sortbyname (void* pEmpleadoA, void* pEmpleadoB)
{
	int retorno=0;
	char nombreA[300];
	char nombreB[300];
	Employee* pEmpleadoAuxA;
	Employee* pEmpleadoAuxB;


	pEmpleadoAuxA=(Employee*)pEmpleadoA;
	pEmpleadoAuxB=(Employee*)pEmpleadoB;

	employee_getNombre(pEmpleadoAuxA,nombreA);
	employee_getNombre(pEmpleadoAuxB,nombreB);

	retorno=strcmp(nombreA,nombreB);

	return retorno;
}



