

#include "sector.h"
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define VACIO 0
#define OCUPADO 1
#define T 1000


typedef struct

{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;
/**
 * @fn int AsignarId()
 * @brief Funcion que retorna un id automaticamente
 *
 * @return el id correspondiente al empleado
 */
int AsignarId ();
/**
 * @fn int IniciarEmpleados(Employee[], int)
 * @brief Funcion que incializa el campo isEmpty en 0 en el array de empleados
 *
 * @param El array de empleados
 * @param El tamaño del array
 * @return Retorna -1 en caso de error, o 0 en caso de exito
 */
int IniciarEmpleados (Employee listaEmpleados[],int tam);
/**
 * @fn int BuscarEmpleadoPorID(Employee[], int, int)
 * @brief Funcion que busca un empleado en el array de empleados cuando le paso un id
 *
 * @param El array de empleados
 * @param El tamaño del array
 * @param El ID recibido
 * @return Retorna -1 en caso de error, o 0 en caso de exito
 */
int BuscarEmpleadoPorID(Employee listaEmpleados[], int tam,int id);
/**
 * @fn int CargarEmpleados(Employee[], int, int, char[], char[], float, int, int)
 * @brief Funcion que carga los datos que recibe a un empleado del array
 *
 * @param El array de empleados
 * @param El tamaño del array
 * @param El ID recibido
 * @param El nombre recibido
 * @param El apellido recibido
 * @param El salario recibido
 * @param El sector recibido
 * @param El indice del empleado al que le cargamos los datos recibidos
 * @return Retorna -1 en caso de error, o 0 en caso de exito
 */
int CargarEmpleados (Employee listaEmpleados[], int tam, int id, char name[], char lastName[], float salary, int sector,int index);
/**
 * @fn int PedirDatos(Employee[], int, int*, char[], char[], float*, int*, int*, eSector[], int)
 * @brief Funcion que pide datos para luego ser cargados por la funcion de carga
 *
 * @param El array de empleados
 * @param El tamaño del array de empleados
 * @param Variable auxiliar con puntero donde guardar la informacion del ID ingresado
 * @param Variable auxiliar con puntero donde guardar la informacion del nombre ingresado
 * @param Variable auxiliar con puntero donde guardar la informacion del apellido ingresado
 * @param Variable auxiliar con puntero donde guardar la informacion del salario ingresado
 * @param Variable auxiliar con puntero donde guardar la informacion del sector ingresado
 * @param Variable auxiliar con puntero donde guardar la informacion del indice de empleado
 * @param El array de sectores
 * @param El tamaño del array de sectores
 * @return Retorna -1 en caso de error, o 0 en caso de exito
 */
int PedirDatos (Employee listaEmpleados[], int tam, int* id, char name[], char lastName[], float* salary, int* sector,int* index, eSector listaS[],int tamS);
/**
 * @fn int BuscarLibre(Employee[], int)
 * @brief Funcion que busca en el array de empleados un campo isEmpty vacio
 *
 * @param El array de empleados
 * @param tamaño del array de empleados
 * @return Retorna -1 en caso de error, o 0 en caso de de exito
 */
int BuscarLibre (Employee listaEmpleados[],int tam);
/**
 * @fn int BajaEmpleado(Employee*, int, eSector[], int)
 * @brief Funcion que da de baja un empleado
 *
 * @param El array de empleados
 * @param El tamaño del array de empleados
 * @param El array de sectores
 * @param El tamaño del array de sectores
 * @return Retorna -1 en caso de error, o 0 en caso de de exito
 */
int BajaEmpleado(Employee* listaEmpleados, int tam, eSector listaS[], int tamS);
/**
 * @fn void MostrarEmpleado(Employee, eSector[], int)
 * @brief Funcion que muestra un empleado con su sector
 *
 * @param El array de empleados
 * @param El array de sectores
 * @param El tamaño del array de sectores
 */
void MostrarEmpleado (Employee ListaEmpleados, eSector listaS[], int tamS);
/**
 * @fn int ListadoEmpleados(Employee[], int, eSector[], int)
 * @brief Funcion que muestra el listado de empleados
 *
 * @param El array de empleados
 * @param El tamaño del array de empleados
 * @param El array de sectores
 * @param El tamaño del array de sectores
 * @return Retorna -1 en caso de error, o 0 en caso de de exito
 */
int ListadoEmpleados (Employee ListaEmpleados[], int tamE, eSector listaS[], int tamS);
/**
 * @fn int ModificarEmpleado(Employee[], int, eSector[], int)
 * @brief Funcion que permite modificar datos del empleado
 *
 * @param El array de empleados
 * @param El tamaño del array de empleados
 * @param El array de sectores
 * @param El tamaño del array de sectores
 * @return Retorna -1 en caso de error, o 0 en caso de de exito
 */
int ModificarEmpleado(Employee listaEmpleados[], int tam, eSector listaS[], int tamS);
/**
 * @fn int Menu()
 * @brief Funcion que muestra el menu principal
 *
 * @return Retorna la opcion elegida en el menu
 */
int Menu ();
/**
 * @fn int MenuModificaciones()
 * @brief Funcion que muestra el sub-menu de modificaciones
 *
 * @return Retorna la opcion elegida en el menu
 */
int MenuModificaciones ();
/**
 * @fn int Ordenamiento(Employee[], int)
 * @brief Funcion que ordena los empleados por su sector y su apellido
 *
 * @param El array de empleados
 * @param El tamaño del array de empleados
 * @return Retorna -1 en caso de error, o 0 en caso de de exito
 */
int Ordenamiento (Employee listaEmpleado[], int len);
/**
 * @fn void TotalPromedioSalarios(Employee[], int)
 * @brief Funcion que retorna el total, el promedio y los empleados con sueldo mayor al promedio
 *
 * @param El array de empleados
 * @param El tamaño del array de empleados
 */
void TotalPromedioSalarios (Employee listaEmpleado[], int tamE);
/**
 * @fn int MenuInformes()
 * @brief Funcion que muestra el sub-menu de informes
 *
 * @return Retorna la opcion elegida en el menu
 */
int MenuInformes();
#endif /* ARRAYEMPLOYEES_H_ */
