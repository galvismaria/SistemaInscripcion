#ifndef COLA
#define COLA

#include "Nodo.h"
#include "Estudiante.h"
#include "Global.h"

class Cola{
	
	private:
		
		/* ----- ATRIBUTOS ----- */

		Nodo *inicio;
		Nodo *fin;
		int elementos;
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
		
		Cola();
		
		/* ----- Setters ----- */
		
		;
		
		/* ----- Getters ----- */
		
		Nodo *getInicio();
		Nodo *getFin();
		int getElementos();
		
		/* ----- Procedimientos ----- */
		
		bool estaVacia();
		void encolar(Estudiante *estudiante);
		Estudiante* desencolar();
		void asignarPosiciones();
		void ordenarPrioridad(int caso);
		void actualizarEstadoInscripcion(bool estado);
		void imprimir();
		
		/* ----- Destructor ----- */
		
		~Cola();
		
};

#endif
