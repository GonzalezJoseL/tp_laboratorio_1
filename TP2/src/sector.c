#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sector.h"


int DescripcionDelSector(eSector listaS[], int tam, int codigo, char descr[])
{
	int retorno;
	int i;


	if(listaS!=NULL && tam>0 && descr!=NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(listaS[i].id==codigo)
			{

				strcpy(descr,listaS[i].descripcion);

				retorno=0;

			}
		}
	}

	return retorno;
}
void MostrarSector(eSector lista)
{

	printf("%d	%10s \n",lista.id,lista.descripcion);

}


void ListadoSectores (eSector lista[], int tam)

{
	int i;
	if (lista != NULL && tam > 0)
	{
		printf("----------SECTORES---------- \n");
		for (i=0;i<tam;i++)
		{
			MostrarSector(lista[i]);
		}
	}
}


