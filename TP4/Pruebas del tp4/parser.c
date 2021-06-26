#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* pEmpleado;
	char id[1000], nombre[1000], horasTrabajadas[1000], sueldo[1000];

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
		do
		{
			if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo)==4)
			{
				pEmpleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				if (pEmpleado != NULL)
				{
					ll_add(pArrayListEmployee,pEmpleado);
					retorno=0;
				}
			}
			else
			{
				retorno=-2;
				break;
			}
		}while (!feof(pFile));
	}
    return retorno;
}



int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee *pEmpleado;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			pEmpleado=employee_new();
			if(fread(pEmpleado,sizeof(Employee),1,pFile)==1)
			{
				ll_add(pArrayListEmployee, pEmpleado);
			}
			retorno=0;
		}while(!feof(pFile));
	}
	return retorno;
}



