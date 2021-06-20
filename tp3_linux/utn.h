

#ifndef UTN_H_
#define UTN_H_

/** \brief Muestra el menú principal de opciones
 *
 * \param void
 * \return int devuelve un entero (seleccion usuario)
 *
 */
int MenuPrincipal(void);

/** \brief Muestra un menú de opciones
 *
 * \param texto char*
 * \return int
 *
 */
int MostrarMenu(char *texto);

/** \brief Efectua la carga de una cadena de caracteres
 *
 * \param recibe el mensaje de solicitud de carga
 * \param recibe la cadena de caracteres donde se guardara el dato
 * \param recibe el tamaño de la cadena
 * \return
 *
 */

void CargarTexto(char[], char[], int);

/** \brief Carga de una variable de tipo int
 *
 * \param recibe mensaje de solicitud de carga
 * \param recibe el mensaje de error de parámetro
 * \param recibe el parámetro minimo
 * \return el entero validado
 *
 */

int GetInt(char[], char[], int);

/** \brief Consulta al usuario si desea confirmar una operación (s/n)
 *
 * \param
 * \param
 * \return la seleccion del usuario
 *
 */

char ConfirmarOperacion(void);

/** \brief efectua la carga de una variable de tipo int
 *
 * \param recibe mensaje de solicitud de carga
 * \param recibe el mensaje de error de parámetro
 * \param recibe el parámetro mínimo
 * \param recibe el parámetro máximo
 * \return el entero validado
 *
 */

int CargarEntero(char mensaje[], char error[], int minimo, int maximo);

#endif /* UTN_H_ */
