#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int utn_getInt(int* resultado, char mensaje[], int tam, int reintentos, int min, int max)
{
    int retorno=-1;
    char buffer[tam];
    int aux;

	if(resultado != NULL && mensaje != NULL && tam > 0 && min <= max && reintentos >=0)
    {
		do
		{
		printf("%s",mensaje);
		fflush(stdin);
		fgets(buffer,tam,stdin);
		buffer[strlen(buffer)-1]='\0';

		if(EsUnNumero(buffer)==1)
          {
			aux=atoi(buffer);

			if (aux >= min && aux <= max)
				{
				*resultado=aux;
                    retorno=0;
                    break;
				}
				else
				{
					printf("Error. El numero ingresado debe estar entre %d y %d \n",min,max);
					reintentos--;
				}

          }
		else
		{
			printf("Error. No ingreso un numero \n");
			reintentos--;
		}

		}while(reintentos>=0);

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

int utn_getFloat(float* resultado, char mensaje[], int tam, int reintentos, float min, float max)
{
    int retorno=-1;
    char buffer[tam];
    float aux;

    if(resultado != NULL && mensaje != NULL && tam > 0 && min <= max && reintentos >=0)
        {
    		do
    		{
    		printf("%s",mensaje);
    		fflush(stdin);
    		fgets(buffer,tam,stdin);
    		buffer[strlen(buffer)-1]='\0';

    		if(EsUnFloat(buffer)==1)
              {
    			aux=atof(buffer);

    			if (aux >= min && aux <= max)
    				{
    				*resultado=aux;
                        retorno=0;
                        break;
    				}
    				else
    				{
    					printf("Error. El numero ingresado debe estar entre %f y %f \n",min,max);
    					reintentos--;
    				}

              }
    		else
    		{
    			printf("Error. No ingreso un numero \n");
    			reintentos--;
    		}

    		}while(reintentos>=0);

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

int utn_getNombre(char resultado[], char mensaje[], int tam, int reintentos)
{
    int retorno=-1;
    char buffer[tam];

	if(resultado != NULL && mensaje != NULL && tam > 0)
    {

		do
		{
		  printf("%s",mensaje);
		   fflush(stdin);
		   fgets(buffer,tam,stdin);

		  while (buffer[0] == '\n') //si ingreso solo enter
		  		   {
		  			   printf("Error, no ingreso una palabra \n");
		  			   printf("%s",mensaje);
		  			   fflush(stdin);
		  			   fgets(buffer,tam,stdin);
		  		   }

		  buffer[strlen(buffer)-1]='\0'; // borro el enter

		   if(EsUnaLetra(buffer)==1)
           {
					   strcpy(resultado,buffer);
			   	   	   retorno=0;
			   	   	   	break;
           }
		   else
		   {
			   printf("Error\n");
			   reintentos--;
		   }
		}while(reintentos>=0);
   }
    return retorno;
}


int EsUnaLetra(char buffer[])
{
		    int retorno=1;
		    int i;

		    for(i=0;buffer[i]!='\0';i++)
		    {
		        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] == ' '))
		        {

		            retorno=0;

		        }
		    }
		    return retorno;
}

/*
 * int utn_getString (char resultado[], char mensaje[], int tam)

{
	int retorno=-1;
	char buffer[tam];
	if(resultado != NULL && mensaje != NULL && tam > 0)
	{


		     printf("%s",mensaje);
		     fflush(stdin);
		     fgets(buffer,tam,stdin);
		     buffer[strlen(buffer)-1]='\0';
		     strncpy(resultado,buffer,tam);
		     retorno=0;
	}
	return retorno;
}
 *
 */

