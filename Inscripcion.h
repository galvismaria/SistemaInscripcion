#ifndef INSCRIPCION
#define INSCRIPCION

#include "Cola.h"
#include "Lista.h"
#include "Global.h"


using namespace std;

class Inscripcion{
	
	private:
		
		Cola *estudiantes;
		Lista *cursos;
		
		
	public:
		Inscripcion();
		void ingresarEstudiantes(Estudiante *estudiante);
		void ingresarCurso(Curso *curso);
		void asignarCandidatos();
		void inscribirEstudiantes();
		void listaCursos();
	
};

#endif
