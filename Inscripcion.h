#ifndef INSCRIPCION
#define INSCRIPCION

#include "Cola.h"
#include "Lista.h"
#include "Global.h"


using namespace std;

class Inscripcion{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Cola *estudiantes;
		Lista *cursos;
		fstream archivo;
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
		
		Inscripcion();
		
		/* ----- Procedimientos ----- */
		
		void ingresarEstudiantes(Estudiante *estudiante);
		void ingresarCurso(Curso *curso);
		void asignarCandidatos();
		void inscribirEstudiantes();
		void cargarCursos();
		void cargarEstudiantes();
		void mostrarEstudiantes();
		
		/* ----- Destructor ----- */
		
		~Inscripcion();
	
};

#endif
