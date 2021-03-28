#ifndef COLA
#define COLA

#include "Nodo.h"

using namespace std;

/*

		Clase que implementa una cola con prioridad.
		
		En esta estructura de datos, los elementos se atienden en el orden indicado por una prioridad asociada a cada uno.
		Debido a los requerimientos del sistema, existen tres diferentes opciones de prioridad.

*/

class Cola{
	
	private:
		
		/* ----- ATRIBUTOS ----- */

		Nodo *inicio;									// Nodo que apunta al inicio de la cola									
		Nodo *fin;										// Nodo que apunta al final de la cola
		int elementos;									// Nodo que representa la cantidad de elementos que se encuentran en la cola
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
		
		Cola();											// Constructor sin parámetros -> Crea una cola vacia
		
		/* ----- Getters ----- */
		
		Nodo *getInicio();								// Devuelve el nodo que apunta al inicio de la cola
		Nodo *getFin();									// Devuelve el nodo que apunta al final de la cola
		int getElementos();								// Devuelve la cantidad de elementos que tiene la cola
		
		/* ----- Procedimientos ----- */
		
		bool estaVacia();								// Devuelve true si la cola está vacía, y false en caso contrario
		
		void encolar(Estudiante *estudiante);			// Inserta un elemento al final de la cola
		
		void ordenarPrioridad(int caso);				// Ordena la cola según la prioridad que se indique. Las opciones de prioridad son:
		
														// 		-> (1) Ordenar la cola según el índice académico (mientras mayor índice, mayor prioridad)
														//			y en los casos donde el índice sea igual, se le dará prioridad a quien tenga mayor nivel.
														// 		-> (2) Ordenar la cola según el nivel (mientras mayor nivel, mayor prioridad)
														//			y en los casos donde el nivel sea igual, se le dará prioridad a quien tenga mayor índice.
														// 		-> (1) Ordenar la cola según la cantidad de créditos aprobados (mientras más creditos, más prioridad)
														//			y en los casos donde la cantidad de créditos sea igual, se le dará prioridad a quien tenga mayor índice.
						
		Estudiante* desencolar();						// Saca el elemento que esté en la cabeza de la cola
		
		void asignarPosiciones();						// Recorre la cola y asigna a cada nodo la posición que ocupa en la cola
		
		void imprimir();								// Imprime la información del estudiante que se encuentra en cada nodo
		
		/* ----- Destructor ----- */
		
		~Cola();										// Destructor
		
};

#endif
