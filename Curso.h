#ifndef CURSO
#define CURSO

#include <string>
#include <iostream>

#include "Cola.h"
#include "Estudiante.h"

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

	
};

#endif
