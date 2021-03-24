#ifndef CURSO
#define CURSO

#include "Cola.h"
#include "Global.h"

using namespace std;

class Curso{
	
	private:
		
		string nombre;
		int id;
		int cupos;
		Cola *listaAsignados;
		Cola *listaEspera;
		
	public:
		
		Curso();
		Curso(string nombre, int id, int cupos);
		string getNombre();
		void generarListaAsignados(Cola *candidatos, int caso);
		void asignarMaterias();
		void mostrarListaAsignados();
		void mostrarListaEspera();

	
};

#endif
