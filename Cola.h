#ifndef COLA
#define COLA

#include "Nodo.h"

class Cola{
	
	private:

		Nodo *inicio;
		Nodo *fin;
		
	public:
		
		Cola();
		bool estaVacia();
		void encolar(Estudiante *estudiante);
		void encolarPorIndice(Estudiante *estudiante);
		void encolarPorNivel(Estudiante *estudiante);
		void encolarPorCreditos(Estudiante *estudiante);
		void ordenarIndice();
		void imprimir();
		
};

#endif
