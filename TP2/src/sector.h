

#ifndef SECTOR_H_
#define SECTOR_H_
#define S 3

typedef struct
{
	int id;
	char descripcion[90];

}eSector;

/**
 * @fn int DescripcionDelSector(eSector[], int, int, char[])
 * @brief  Funcion que retorna la descripcion de un sector cuando le paso un ID
 *
 * @param El array de sectores
 * @param El tamaño del array de sectores
 * @param El ID que recibe la funcion
 * @param Variable auxiliar donde guardo la descripcion del sector
 * @return La descripcion del sector correspondiente al id de sector
 */
int DescripcionDelSector(eSector lista[], int tam, int codigo, char descripcion[]);
/**
 * @fn void MostrarSector(eSector)
 * @brief Funcion que muestra un sector
 *
 * @param el sector
 */
void MostrarSector(eSector lista);
/**
 * @fn void ListadoSectores(eSector[], int)
 * @brief Funcion que muestra el listado de sectores
 *
 * @param El array de sectores
 * @param El tamaño de del array de sectores
 */
void ListadoSectores (eSector lista[], int tam);


#endif /* SECTOR_H_ */

