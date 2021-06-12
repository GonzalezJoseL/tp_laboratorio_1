#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
//#include "Controller.h"
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"r");
        if (pFile!=NULL)
        {
      	     retorno=parser_EmployeeFromText(pFile,pArrayListEmployee);
        }
    }
    fclose(pFile);
    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {

        pFile=fopen(path,"rb");
        if (pFile!=NULL)
        {

            retorno=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        }
    }
    fclose(pFile);
    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
    int id;
    char nombre[128];
    int horas;
    int sueldo;


    if( pArrayListEmployee != NULL)
    {
        id=employee_autoId();

        Employee* pEmployee=employee_new();

        utn_getNombre(nombre,"Ingresar nombre",30,4);
        utn_getInt(&horas,"Ingrese la cantidad de horas trabajadas:\n", 20,4,1,9000);
        utn_getInt(&sueldo,"Ingrese el sueldo:\n",20,4,1,999999);


        employee_setId(pEmployee,id);
        employee_setHorasTrabajadas(pEmployee,horas);
        employee_setNombre(pEmployee,nombre);
        employee_setSueldo(pEmployee,sueldo);


        ll_add(pArrayListEmployee,pEmployee);

        retorno=0;
    }

    return retorno;
}

int controller_searchId (LinkedList* pArrayListEmployee,int id)
{
	int retorno=-1;
	Employee* pEmpleado;
	int i;
	int idAux;
	int len;
	len=ll_len(pArrayListEmployee);

	if (pArrayListEmployee != NULL)
	{
		for (i=0;i<len;i++)
		{
			pEmpleado=ll_get(pArrayListEmployee,i);
			if (pEmpleado != NULL)
			{
				employee_getId(pEmpleado,&idAux);
				if (idAux==id)
				{
					retorno=i;
					break;
				}
			}
		}
	}
	return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int idAux, indiceE, opcion;
	char continuar='n';
	Employee* pEmpleado;
    if (pArrayListEmployee != NULL)
    {
    	utn_getInt(&idAux,"Por favor, ingresar el ID del empleado a MODIFICAR",9,5,1,9999);
    	indiceE=controller_searchId(pArrayListEmployee,idAux);
    	if (indiceE!=-1)
    	{
    		pEmpleado=ll_get(pArrayListEmployee,indiceE);
    		printf("\n");
    		employee_print(pEmpleado);
    		do
    		{
    			utn_getInt(&opcion,"-----MODIFICACIONES-----\n1. NOMBRE\n2. HORAS TRABAJADAS\n3. SUELDO\n4. SALIR\n\n",5,5,1,4);
    			switch (opcion)
    			{
    				retorno=0;
    			case 1:
    				utn_getNombre(pEmpleado->nombre,"Ingresar nuevo nombre: ",999,5);
    				printf("El nuevo nombre es : %s\n-",pEmpleado->nombre);
    				break;
    			case 2:
    				utn_getInt(&pEmpleado->horasTrabajadas,"Ingrese nueva cantidad de horas trabajadas:\n", 20,4,1,900);
    				printf("La nueva cantidad de horas trabajadas son : %d\n-",pEmpleado->horasTrabajadas);
    				break;
    			case 3:
    				utn_getInt(&pEmpleado->sueldo,"Ingrese nuevo sueldo:\n",20,4,1,999999);
    				printf("El nuevo sueldo es : %d\n-",pEmpleado->sueldo);
    				break;
    			case 4:
    				continuar='s';
    				break;
    			default:
    				printf("Error");
    			}
    		}while(continuar != 's');
    	}
    	else
    	{
    		printf("El id no le corresponde a ningun empleado\n");
    	}
    }
    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int indiceE, idAux;
	char confirmacion;
	Employee* pEmpleado;
	if (pArrayListEmployee != NULL)
	{
		utn_getInt(&idAux,"Por favor, ingresar el ID del empleado a dar de BAJA",9,5,1,9999);
		indiceE=controller_searchId(pArrayListEmployee,idAux);
		if (indiceE!=-1)
		{
			pEmpleado=ll_get(pArrayListEmployee,indiceE);
    		printf("\n");
    		employee_print(pEmpleado);
    		printf("Esta seguro que desea realizar la BAJA? s/n \n:");
    		scanf("%c",&confirmacion);

    		if (confirmacion != 's' && confirmacion != 'n')
			{
				printf("Por favor ingresar la letra s para confirmar la baja O la letra n para no realizar la baja \n");
				scanf("%c",&confirmacion);
			}
    		else
    		{
    			retorno=0;
    			if (confirmacion=='s')
    			{
    				ll_remove(pArrayListEmployee,indiceE);
    				free(pEmpleado);
    			}
    			else
    			{
    				printf("El empleado NO se dio de baja\n");
    			}
    		}
		}
		else
		{
			printf("El id no le corresponde a ningun empleado\n");
		}
	}
	return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    Employee* pEmpleado;
    if (pArrayListEmployee != NULL)
    {
    	for (i=0;i<ll_len(pArrayListEmployee);i++) // SACAR EL LEN DEL FOR
    	{
    		pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

    		if (pEmpleado != NULL)
    		{
    			employee_print(pEmpleado);
    		}
    	}
    	retorno=0;
    }
    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	if(pArrayListEmployee != NULL)
	{
		retorno=ll_sort(pArrayListEmployee,employee_sortbyname,1);
	}
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int len, i;
	Employee* pEmpleado;
	FILE* pFILE;
	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFILE=fopen(path,"w");
		if (pFILE != NULL)
		{
			fprintf(pFILE,"id,nombre,horastrabajadas,sueldo\n");
			retorno=0;
			len=ll_len(pArrayListEmployee);
			for (i=0;i<len;i++)
			{
				pEmpleado=ll_get(pArrayListEmployee,i);
				fprintf(pFILE,"%d,%s,%d,%d\n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);
			}
			fclose(pFILE);
			printf("El archivo fue guardado con exito\n");
		}
	}

	return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int len, i=0;
    Employee* pEmpleado;
    FILE* pFILE;

    if (path != NULL && pArrayListEmployee != NULL)
    {
    	pFILE=fopen(path,"wb");
    	if (pFILE != NULL)
    	{
    		retorno=0;
    		len=ll_len(pArrayListEmployee);
    		for (i=0;i<len;i++)
    		{
    			pEmpleado=ll_get(pArrayListEmployee,i);
    			fwrite(pEmpleado,sizeof(Employee),1,pFILE);
    		}
    		fclose(pFILE);
    		printf("El archivo fue guardado con exito\n");
    	}
    }
	return retorno;
}
