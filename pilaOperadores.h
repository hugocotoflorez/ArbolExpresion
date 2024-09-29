#ifndef PILAOPERADORES_H
#define PILAOPERADORES_H

//Interfaz TAD pilaOperadores
typedef void *pilaOperadores; /*tipo opaco*/

//CONTENIDO DE CADA ELEMENTO DE LA PILA
//MODIFICAR: PARA LA PILA DE OPERADORES: char
//MODIFICAR: PARA LA PILA DE OPERANDOS: abin
typedef char tipoelemPilaOperadores;

//Funciones de creacion y destruccion
/**
 * Crea la pilaOperadores vacia.
 * @param P Puntero a la pilaOperadores. Debe estar inicializada.
 */
void crearPilaOperadores(pilaOperadores *P);

/**
 * Destruye la pilaOperadores
 * @param P puntero a la pilaOperadores
 */
void destruirPilaOperadores(pilaOperadores *P);

//Funciones de informacion
/**
 * Comprueba si la pilaOperadores esta vacia
 * @param P pilaOperadores
 */
unsigned esVaciaPilaOperadores(pilaOperadores P);

/*
 * Recupera la informacion del tope de la pilaOperadores
 * @param P pilaOperadores
 *
*/
tipoelemPilaOperadores topeOperadores(pilaOperadores P);

//Funciones de insercion/eliminacion
/**
 * Inserta un nuevo nodo en la pilaOperadores para el elemento E
 * en el tope de la pilaOperadores
 * @param P puntero a la pilaOperadores
 * @param E Informacion del nuevo nodo.
 */
void pushOperadores(pilaOperadores *P, tipoelemPilaOperadores E);

/**
 * Suprime el elemento en el tope de la pilaOperadores
 * @param P puntero a la pilaOperadores
 */
void popOperadores(pilaOperadores *P);

#endif	// PILA_H

