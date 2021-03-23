#ifndef NODO
#define NODO

#include "Estudiante.h"

class Nodo{
	
	private:
		
		Estudiante *estudiante;
		Nodo *siguiente;
		int posicion;
		
	public:
		
		Nodo();
		~Nodo();
		Nodo(Estudiante *estudiante, Nodo *siguiente, int posicion);
		Nodo(Estudiante *estudiante, Nodo *siguiente);
		Nodo(Estudiante *estudiante);
		void setEstudiante(Estudiante *estudiante);
		void setSiguiente(Nodo *siguiente);
		void setPosicion(int posicion);
		Nodo* getSiguiente();
		Estudiante* getEstudiante();
	
};

#endif
