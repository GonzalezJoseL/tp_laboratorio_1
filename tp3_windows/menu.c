#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"

int menu ()
{
	int opcion;
	printf("Menu:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
			"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
			"3. Alta de empleado\n"
			"4. Modificar datos de empleado\n"
			"5. Baja de empleado\n"
			"6. Listar empleados\n"
			"7. Ordenar empleados\n"
			"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
			"9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
			"10. Salir\n");

	utn_getInt(&opcion,"Opcion: ",5,6,0,9);
	return opcion;
}
