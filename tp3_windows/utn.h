

#ifndef UTN_H_
#define UTN_H_

/**
 * @fn int utn_getInt(int*, char[], int, int, int, int)
 * @brief Funcion que toma un/unos entero/s del usuario
 *
 * @param resultado de la funcion (variable donde guardo la misma)
 * @param mensaje a mostrar por consola
 * @param tamaño del array
 * @param numero de reintentos para el usuario
 * @param minimo numero a ingresar
 * @param maximo numero a ingresar
 * @return retorna -1 en caso de error o 0 en caso de exito
 */
int utn_getInt(int* resultado, char mensaje[], int tam, int reintentos, int min, int max);
/**
 * @fn int EsUnNumero(char[])
 * @brief Funcion que valida que el buffer sea numerico
 *
 * @param buffer ingresado
 * @return 1 en caso de que sea numero y 0 en caso de error
 */
int EsUnNumero(char buffer[]);
/**
 * @fn int utn_getFloat(float*, char[], int, int, float, float)
 * @brief Funcion que toma un/unos flotante/s del usuario
 *
 * @param resultado de la funcion (variable donde guardo la misma)
 * @param mensaje a mostrar por consola
 * @param tamaño del array
 * @param numero de reintentos para el usuario
 * @param minimo numero a ingresar
 * @param maximo numero a ingresar
 * @return retorna -1 en caso de error o 0 en caso de exito
 */
int utn_getFloat(float* resultado, char mensaje[], int tam, int reintentos, float min, float max);
/**
 * @fn int EsUnFloat(char[])
 * @brief Funcion que valida que el buffer sea flotante
 *
 * @param buffer ingresado
 * @return 1 en caso de que sea numero y 0 en caso de error
 */
int EsUnFloat(char buffer[]);
/**
 * @fn int utn_getNombre(char[], char[], int, int)
 * @brief Funcion que toma una cadena de caracteres del usuario
 *
 * @param resultado de la funcion (variable donde guardo la misma)
 * @param mensaje a mostrar por consola
 * @param tamaño del array
 * @param numero de reintentos para el usuario
 * @return retorna -1 en caso de error o 0 en caso de exito
 */
int utn_getNombre(char resultado[], char mensaje[], int tam, int reintentos);
/**
 * @fn int EsUnaLetra(char[])
 * @brief Funcion que valida que el buffer sea de letras
 *
 * @param buffer ingresado
 * @return 1 en caso de que sea numero y 0 en caso de error
 */
int EsUnaLetra(char buffer[]);



#endif /* UTN_H_ */
