#include <stdio.h>
#include <stdlib.h>


#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
/****************************************************
    Menu:\n
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n
     3. Alta de empleado\n
     4. Modificar datos de empleado\n
     5. Baja de empleado\n
     6. Listar empleados\n
     7. Ordenar empleados\n
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n
     0. Salir\n
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

    char letra = 'n';
    int flagtxt=0;
    int flagbin=0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

        switch(menu())
        {
            case 1:
            	if (flagbin==0)
            	{
            		if (controller_loadFromText("data.csv",listaEmpleados)==0)
            		{
            			printf("La lista se cargo con exito");
            			flagtxt=1;
            		}
            	}
            	else
            	{
            		printf("Ya se realizo una lectura de binario\n");
            	}
                break;
            case 2:
            	if (flagtxt==0)
            	{
            		if (controller_loadFromBinary("data.bin",listaEmpleados)==0)
            		{
            			printf("La lista se cargo con exito");
            			flagbin=1;
            		}
            	}
            	else
            	{
            		printf("Ya se realizo una lectura de texto\n");
            	}
            	break;
            case 3:
            	if (flagtxt==1 || flagbin==1)
            	{
            		controller_addEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Se debe realizar primero una lectura del archivo\n");
            	}
            	break;
            case 4:
            	if (flagtxt==1 || flagbin==1)
            	{
            		controller_editEmployee(listaEmpleados);
            	}
            	else
            	{
            	     printf("Se debe realizar primero una lectura del archivo\n");
            	}
            	break;
            case 5:
            	if (flagtxt==1 || flagbin==1)
            	{
            		if(controller_removeEmployee(listaEmpleados)==0)
            		{
            			printf("El empleado fue dado de BAJA con exito\n");
            		}
            		else
            		{
            			printf("El empleado NO se dio de baja\n");
            		}
            	}
            	else
            	{
            	     printf("Se debe realizar primero una lectura del archivo\n");
            	}
            	break;
            case 6:
            	if (flagtxt==1 || flagbin==1)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            	     printf("Se debe realizar primero una lectura del archivo\n");
            	}
            	break;
            case 7:
            	if (flagtxt==1 || flagbin==1)
            	{
            		controller_sortEmployee(listaEmpleados);
            	}
            	else
            	{
            	     printf("Se debe realizar primero una lectura del archivo\n");
            	}
            	break;
            case 8:
            	if (flagtxt==1 || flagbin==1)
            	{
            		controller_saveAsText("data.csv",listaEmpleados);
            	}
            	else
            	{
            	     printf("Se debe realizar primero una lectura del archivo\n");
            	}
            	break;
            case 9:
            	if (flagtxt==1 || flagbin==1)
            	{
            		controller_saveAsBinary("data.bin",listaEmpleados);
            	}
            	else
            	{
            	     printf("Se debe realizar primero una lectura del archivo\n");
            	}
				break;
            case 0:
            	letra='s';
            	break;
        }
    }while(letra != 's');

    return 0;
}

