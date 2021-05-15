
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn.h"
#include "sector.h"

int NuevoId=0;

int AsignarId ()
{
	return NuevoId+=1;
}

int IniciarEmpleados (Employee listaEmpleados[],int tam)
{
	int i;
	int error=-1;

	if (listaEmpleados != NULL && tam > 0)

	{
		for (i=0;i<tam;i++)
		{
			listaEmpleados[i].isEmpty=VACIO;
		}
		error=0;
	}


	return error;
}

int BuscarEmpleadoPorID(Employee listaEmpleados[], int tam,int id)
{
	int indice=-1;
	int i;
	if (listaEmpleados != NULL && tam > 0)

	{
		for (i=0;i<tam;i++)
		{
			if (listaEmpleados[i].id==id)
			{
				indice=i;
				break;
			}
		}

	}
	return indice;
}



int CargarEmpleados (Employee listaEmpleados[], int tam, int id, char name[], char lastName[], float salary, int sector,int index)

{
	int error=-1;

	if (listaEmpleados != NULL && tam >0 && name != NULL && lastName != NULL && salary > 0 && sector > 0)
	{




		listaEmpleados[index].id=id;
		strcpy(listaEmpleados[index].name,name);
		strcpy(listaEmpleados[index].lastName,lastName);
		listaEmpleados[index].salary=salary;

		listaEmpleados[index].isEmpty=OCUPADO;
		listaEmpleados[index].sector=sector;


		error=0;


	}

	return error;
}



int PedirDatos (Employee listaEmpleados[], int tam, int* id, char name[], char lastName[], float* salary, int* sector,int* index, eSector listaS[],int tamS)

{

	int retorno=-1;

	if (listaEmpleados != NULL && tam >0 && id != NULL && name != NULL && lastName != NULL && salary != NULL && sector!= NULL)

		{

			*index=BuscarLibre(listaEmpleados,tam);

				{
					if (*index==-1)
					{
						printf("No se encontro un lugar vacio. La lista de empleados esta llena \n");
					}
					else
					{
						*id=AsignarId();


						utn_getNombre(name,"Por favor ingresar un nombre :", 30);
						utn_getNombre(lastName,"Por favor ingresar un apellido :",30);
						utn_getFloat(salary,"Por favor ingresar un salario :", 9);
						ListadoSectores(listaS,tamS);
						utn_getInt(sector,"Por favor ingresar un sector :", 9);



						retorno=0;

					}
				}

		}

	return retorno;
}

int BuscarLibre (Employee listaEmpleados[],int tam)
{

	int i;
	int index=-1;

		if (listaEmpleados != NULL && tam > 0)

		{
			for (i=0;i<tam;i++)
			{
				if(listaEmpleados[i].isEmpty==VACIO)
				{
					index=i;
					break;
				}
			}

		}


		return index;

}


int BajaEmpleado(Employee* listaEmpleados, int tam, eSector listaS[], int tamS)
{
	int retorno=-1;
	int indiceEmpleado;
	char confirmacion;
	int id;
	if (listaEmpleados != NULL && tam > 0)
	{
		ListadoEmpleados(listaEmpleados,tam,listaS,tamS);
		utn_getInt(&id,"Por favor ingresar el ID del usuario a dar BAJA",1001);
		indiceEmpleado=BuscarEmpleadoPorID(listaEmpleados,tam,id);

		if (indiceEmpleado<0)
		{
			printf("El id no le corresponde a ningun empleado \n");
			utn_getInt(&id,"Por favor ingresar el ID del usuario a modificar",1001);
		}
		else
		{

			MostrarEmpleado(listaEmpleados[indiceEmpleado],listaS,tamS);


			printf("Esta seguro que desea realizar la BAJA? s/n \n:");
			scanf("%c",&confirmacion);

			if (confirmacion != 's' && confirmacion != 'n')
			{
				printf("Por favor ingresar la letra 's' para confirmar la baja o la letra 'n' para no realizar la baja \n");
				scanf("%c",&confirmacion);
			}
			else
			{
				if (confirmacion=='s')
				{
					listaEmpleados[indiceEmpleado].isEmpty=VACIO;
					retorno=0;
					printf("El empleado se dio de baja con exito \n");
				}
				else
				{
					printf("El empleado NO se dio de baja \n");
				}
			}
		}



	}
	return retorno;
}

void MostrarEmpleado (Employee ListaEmpleados, eSector listaS[], int tamS)
{
	char nombre[25];

	if (listaS != NULL && tamS > 0)
	{
		DescripcionDelSector(listaS,tamS,ListaEmpleados.sector,nombre);

		printf("%d	%10s	%10s	%.2f	%10s\n",ListaEmpleados.id,ListaEmpleados.name,ListaEmpleados.lastName,ListaEmpleados.salary,nombre);

	}

	}

int ListadoEmpleados (Employee ListaEmpleados[], int tamE, eSector listaS[], int tamS)
{
	int i;
	int retorno=0;

	printf("LISTADO\nID	     NOMBRE	    APELLIDO	SALARIO	   SECTOR	\n");

	for (i=0;i<tamE;i++)
	{
		if (ListaEmpleados[i].isEmpty==OCUPADO)
		{
				MostrarEmpleado(ListaEmpleados[i],listaS,tamS);
		}
	}
	return retorno;
}


int ModificarEmpleado(Employee listaEmpleados[], int tam, eSector listaS[], int tamS)
{
	int retorno=-1;
	int id;
	int indiceEmpleado;
	char salida='n';

	if (listaEmpleados != NULL && tam >0)
	{
		ListadoEmpleados(listaEmpleados,tam,listaS,tamS);
		utn_getInt(&id,"Por favor ingresar el ID del usuario a modificar",1001);
		indiceEmpleado=BuscarEmpleadoPorID(listaEmpleados,tam,id);

		if (indiceEmpleado==-1)
		{
			printf("El id no le corresponde a ningun empleado \n");
			utn_getInt(&id,"Por favor ingresar el ID del usuario a modificar",1001);
		}
		else
		{

			MostrarEmpleado(listaEmpleados[indiceEmpleado],listaS,tamS);
			do
			{


				switch(MenuModificaciones())
				{
				case 1:
					printf("El nombre es %s\n",listaEmpleados[indiceEmpleado].name);
					utn_getNombre(listaEmpleados[indiceEmpleado].name,"Por favor ingresar nuevo nombre", 30);
					break;
				case 2:
					printf("El apellido es %s\n",listaEmpleados[indiceEmpleado].lastName);
					utn_getNombre(listaEmpleados[indiceEmpleado].lastName,"Por favor ingresar nuevo nombre", 30);
					break;
				case 3:
					printf("El salario es %f\n",listaEmpleados[indiceEmpleado].salary);
					utn_getFloat(&listaEmpleados[indiceEmpleado].salary,"Por favor ingresar nuevo salario",30);
					break;
				case 4:
					printf("El sector es %d\n",listaEmpleados[indiceEmpleado].sector);
					utn_getInt(&listaEmpleados[indiceEmpleado].sector,"Por favor ingresar nuevo sector", 30);
					break;
				case 0:
					printf("Esta seguro que desea salir? presione s para volver al menu principal\n");
					fflush(stdin);
					scanf("%c",&salida);

					break;
				default:
					printf("Por favor ingresar una opcion valida\n");
					break;
				}
			}while(salida!='s');
			retorno=0;
		}
	}

	return retorno;
}





int Menu ()
{
	int opcion;

	printf("------------MENU------------ \n");
	printf("1. ALTAS\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. INFORMAR\n");
	printf("0. SALIR\n");

	utn_getInt(&opcion,"\n",10);
	return opcion;
}

int MenuModificaciones ()
{
	int opcion;



	printf("Que desea modificar?\n");
	printf("1. Nombre\n");
	printf("2. Apellido\n");
	printf("3. Salario\n");
	printf("4. Sector\n");
	printf("0. SALIR\n");


	scanf("%d",&opcion);

	return opcion;
}

int Ordenamiento (Employee listaEmpleado[], int tam)
{
int retorno=-1;
   int i, j;
   Employee pivot;

   if(listaEmpleado!=NULL && tam>=0)
   {
       for (i= 1;i<tam;i++)
       {
    	   pivot=listaEmpleado[i];
           j=i-1;
           while ((j >= 0) && strcmp(pivot.lastName,listaEmpleado[j].lastName)<0 &&pivot.sector==listaEmpleado[j].sector)
           {
        	   listaEmpleado[j + 1]=listaEmpleado[j];
               j--;
           }
           listaEmpleado[j+1]=pivot;
       }
       retorno=0;
   }
   return retorno;
}

void TotalPromedioSalarios (Employee listaEmpleado[], int tamE)
{
	int i;
	int acumuladorDeSalarios=0;
	int contandorS=0;
	float promedioS;
	int mayorAlSalarioPromedio=0;
	for
	(i=0;i<tamE;i++)
	{

		if (listaEmpleado[i].isEmpty==OCUPADO)
		{
			acumuladorDeSalarios=listaEmpleado[i].salary+acumuladorDeSalarios;
			contandorS++;
		}
	}
	promedioS=(float)acumuladorDeSalarios/contandorS;
	for
		(i=0;i<tamE;i++)
		{
			if (listaEmpleado[i].isEmpty==OCUPADO)
			{
				if (listaEmpleado[i].salary>promedioS)
				{
					mayorAlSalarioPromedio++;
				}
			}
		}
	printf("El TOTAL de salarios es: %d\nEl PROMEDIO de salarios es: %.2f \nLa cantidad de empleados con salario MAYOR al PROMEDIO son: %d\n",
			acumuladorDeSalarios,promedioS,mayorAlSalarioPromedio);
}

int MenuInformes()

{
	int opcion;

	printf("Por favor eliga una opcion\n");
	printf("1. LISTADO\n");
	printf("2. ORDENAMIENTO\n");
	printf("3. MAYOR Y PROMEDIOS\n");
	printf("0. SALIR\n");

	utn_getInt(&opcion,"\n",3);
	return opcion;
}
