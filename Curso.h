#ifndef CURSO
#define CURSO

#include "Cola.h"
#include "Estudiante.h"
#include "Global.h"

using namespace std;

class Curso{
	
	private:

		int id;
		int cupos;
		int prioridad;
		Cola *listaAsignados;
		Cola *listaEspera;
		Cola *candidatos;
		
	public:
		
		Curso();
		Curso(int id, int cupos, int prioridad);
		int getID();
		void generarListaAsignados();
		void asignarMaterias();
		void ingresarCandidato(Estudiante *estudiante);
		void mostrarListaAsignados();
		void mostrarListaEspera();
		void mostrarListaCandidatos();
		

	
};

#endif
