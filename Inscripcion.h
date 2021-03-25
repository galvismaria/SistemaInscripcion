#ifndef INSCRIPCION
#define INSCRIPCION

#include<fstream>
#include "Cola.h"
#include "Lista.h"
#include "Global.h"


using namespace std;

class Inscripcion{
	
	private:
		
		Cola *estudiantes;
		Lista *cursos;
		fstream archivo;
		
	public:
		Inscripcion();
		void ingresarEstudiantes(Estudiante *estudiante);
		void ingresarCurso(Curso *curso);
		void asignarCandidatos();
		void inscribirEstudiantes();
		void readList();
		void ListaEstudiantes();
	
};

#endif
