#ifndef COLA
#define COLA

#include "Nodo.h"
#include "Estudiante.h"
#include "Global.h"

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
		void encolar(Estudiante *estudiante);
		void encolarAdelante(Estudiante *estudiante);
		void encolarLuegoDe(Estudiante *estudiante, Nodo *lugar);
		Estudiante* desencolar();
		void asignarPosiciones();
		void ordenarPrioridad(int caso);
		void actualizarEstadoInscripcion(bool estado);
		void imprimir();
		
};

#endif
