#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




int utn_getInt(int* resultado, char mensaje[], int tam)
{
    int retorno=-1;
    char buffer[tam];

	if(resultado != NULL && mensaje != NULL && tam > 0)
    {

		printf("%s",mensaje);
		fflush(stdin);
		fgets(buffer,tam,stdin);
		buffer[strlen(buffer)-1]='\0';


		if(EsUnNumero(buffer)==1)
          {


                   *resultado=atoi(buffer);
                    retorno=0;


          }


      }

    return retorno;
}

int EsUnNumero(char buffer[])
{
    int retorno=1;
    int i;
    for(i=0;buffer[i]!='\0';i++)
    {



        if(buffer[i]<'0' || buffer[i]>'9')
        {



            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_getFloat(float* resultado, char mensaje[], int tam)
{
    int retorno=-1;
    char buffer[tam];

	if(resultado != NULL && mensaje != NULL && tam > 0)
    {


		printf("%s",mensaje);
		fflush(stdin);
		fgets(buffer,tam,stdin);
		buffer[strlen(buffer)-1]='\0';

       if(EsUnFloat(buffer)==1)
          {
                 *resultado=atof(buffer);
                    retorno=0;

          }

   }
    return retorno;
}

int EsUnFloat(char buffer[])
{
    int retorno=1;
    int i;
    for(i=0;buffer[i]!='\0';i++)
    {
        if((buffer[i]<'0' || buffer[i]>'9') && (buffer[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_getNombre(char resultado[], char mensaje[], int tam)
{
    int retorno=-1;
    char buffer[tam];

	if(resultado != NULL && mensaje != NULL && tam > 0)
    {
		 printf("%s",mensaje);
		fflush(stdin);
		 fgets(buffer,tam,stdin);
		 buffer[strlen(buffer)-1]='\0';


       if(EsUnaLetra(buffer)==1)
          {

                    retorno=0;
                    strncpy(resultado,buffer,tam);
          }

   }
    return retorno;
}


int EsUnaLetra(char buffer[])
{
		    int retorno=1;
		    int i;
		    for(i=0;buffer[i]!='\0';i++)
		    {
		        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] != ' '))
		        {
		            retorno=0;
		            break;
		        }
		    }
		    return retorno;
}
