#ifndef NODO
#define NODO

#include "Estudiante.h"

/*

		Clase que implementa un Nodo que almacena un estudiante.
		Esta clase se utiliza para la clase Cola.

*/

class Nodo{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Estudiante *estudiante;					// Objeto que representa a un estiudiante
		Nodo *siguiente;						// Nodo que apunta al siguiente nodo
		int posicion;							// Entero que representa el lugar que se ocupa en la cola
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
		
		Nodo();															// Constructor sin parámetros -> Crea un nodo vacío
		Nodo(Estudiante *estudiante, Nodo *siguiente, int posicion);	// Constructor con parámetros -> Crea un nodo con un estidante, un apuntador al siguiente elemento y la posicion que ocupa
		Nodo(Estudiante *estudiante, Nodo *siguiente);					// Constructor con parámetros -> Crea un nodo con un estidante y un apuntador al siguiente elemento	
		Nodo(Estudiante *estudiante);									// Constructor con parámetros -> Crea un nodo con un estidante
		
		/* ----- Setters ----- */
		
		void setEstudiante(Estudiante *estudiante);
		void setSiguiente(Nodo *siguiente);
		void setPosicion(int posicion);
		
		/* ----- Getters ----- */
		
		Nodo* getSiguiente();
		Estudiante* getEstudiante();
		int getPosicion();
		
		/* ----- Destructor ----- */
		
		~Nodo();														// Destructor
	
};

#endif
