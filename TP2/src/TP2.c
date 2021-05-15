
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayEmployees.h"
#include "sector.h"
#include "utn.h"


int main(void)

{

	setbuf(stdout,NULL);


	int id;
	char name[99];
	char lastName[99];
	float salary;
	int auxsector;
	int index;
	char opcionInformes='n';
	int flagAlta;

	char continuar = 'n';


	Employee miEmpleado[T];
	eSector miSector[S]={{1,"Pesados"},{2,"Logistica"},{3,"Papeles"}};
	IniciarEmpleados(miEmpleado,T);


	do
	{
		switch(Menu())
		{
		case 1:

			if ( PedirDatos(miEmpleado, T, &id, name, lastName, &salary, &auxsector, &index,miSector,S) ==0 && CargarEmpleados(miEmpleado,T,id,name,lastName,salary,auxsector,index)==0)


			{
				printf("El alta fue realizada \n");
				flagAlta=1;
			}
			else
			{
				printf("Error. El alta no pudo ser realizada \n");
			}
			break;
		case 2:
			if (flagAlta!=1)
			{
				printf("Error, primero debe realizar un Alta \n");
			}
			else
			{
				ModificarEmpleado(miEmpleado,T,miSector,4);
			}
			break;
		case 3:
			if (flagAlta!=1)
			{
				printf("Error, primero debe realizar un Alta \n");
			}
			else
			{

				BajaEmpleado(miEmpleado,T,miSector,4);
			}	break;
		case 4:
			if (flagAlta!=1)
			{
				printf("Error, primero debe realizar un Alta \n");
			}
			else
			{
				do
				{
					switch (MenuInformes())
					{
					case 1:
						ListadoEmpleados (miEmpleado,T,miSector,S);
						break;
					case 2:
						Ordenamiento(miEmpleado,T);
						break;
					case 3:
						TotalPromedioSalarios(miEmpleado,T);
						break;
					case 0:
						printf("Para volver al MENU principal presionar 's'");
						scanf("%c",&opcionInformes);
						break;
					default:
						printf("Ingresar una opcion valida\n");
						break;
					}
				}while(opcionInformes!='s');
			}

			break;
		case 0:
			printf("Esta seguro que desea salir?: presionar 's' para SALIR \n");
			fflush(stdin);
			scanf("%c", &continuar);
			break;
		default:
			printf("Por favor ingresar una opcion valida");
			break;
		}
	}while(continuar!='s');


	return 0;
}
