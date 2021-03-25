#ifndef NODO
#define NODO

#include "Estudiante.h"

class Nodo{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Estudiante *estudiante;
		Nodo *siguiente;
		int posicion;
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
		
		Nodo();
		Nodo(Estudiante *estudiante, Nodo *siguiente, int posicion);
		Nodo(Estudiante *estudiante, Nodo *siguiente);		
		Nodo(Estudiante *estudiante);
		
		/* ----- Setters ----- */
		
		void setEstudiante(Estudiante *estudiante);
		void setSiguiente(Nodo *siguiente);
		void setPosicion(int posicion);
		
		/* ----- Getters ----- */
		
		Nodo* getSiguiente();
		Estudiante* getEstudiante();
		int getPosicion();
		
		/* ----- Destructor ----- */
		
		~Nodo();
	
};

#endif
