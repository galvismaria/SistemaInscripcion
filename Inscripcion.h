#ifndef INSCRIPCION
#define INSCRIPCION

#include "Cola.h"
#include "Lista.h"


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
		
		/* ----- Getters ----- */
	
		Cola *getEstudiantes();
		Lista *getCursos();
		
		/* ----- Procedimientos ----- */
		
		void ingresarEstudiantes(Estudiante *estudiante);
		void ingresarCurso(Curso *curso);
		void asignarCandidatos();
		void inscribirEstudiantes();
		void cargarCursos();
		void cargarEstudiantes();
		void cargarInscripciones();
		void cargarMateriasEstudiante( int cedula, int materias[], int n );
		void procesoInscripcion();
		void mostrarEstudiantes();
		void mostrarCursos();
		void mostrarCandidatos();
		void listaCursos();
		void buscarEstudiante();
		void menuPrincipal();
		void salir();
		
		/* ----- Destructor ----- */
		
		~Inscripcion();
	
};

#endif
