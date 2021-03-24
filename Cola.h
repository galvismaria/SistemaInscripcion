#ifndef COLA
#define COLA

#include "Nodo.h"
#include "Estudiante.h"

class Cola{
	
	private:

		Nodo *inicio;
		Nodo *fin;
		int elementos;
		
	public:
		
		Cola();
		Nodo *getInicio();
		Nodo *getFin();
		int getElementos();
		bool estaVacia();
		void encolarAtras(Estudiante *estudiante);
		void encolarAdelante(Estudiante *estudiante);
		void encolarLuegoDe(Estudiante *estudiante, Nodo *lugar);
		Estudiante* desencolar();
		void encolarPorIndice(Estudiante *estudiante);
		void encolarPorNivel(Estudiante *estudiante);
		void encolarPorCreditos(Estudiante *estudiante);
		void asignarPosiciones();
		void ordenarPrioridad(int caso);
		void imprimir();
		
};

#endif
