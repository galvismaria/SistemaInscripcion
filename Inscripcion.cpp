#include "Inscripcion.h"

Inscripcion::Inscripcion(){
	
	estudiantes = new Cola();
	cursos = new Lista();
	
}

void Inscripcion::ingresarEstudiantes(Estudiante *estudiante){
	
	estudiantes->encolar(estudiante);
	
}

void Inscripcion::ingresarCurso( Curso *curso ){
	
	cursos->insertar(curso);
	
}


void Inscripcion::asignarCandidatos(){
	
	Estudiante *temp = new Estudiante();
	
	int materias[MAX_MATERIAS];

	while ( !estudiantes->estaVacia() ){
		
		temp = estudiantes->desencolar();
		
		temp->obtenerMaterias(materias);
		
		for ( int i = 0 ; i < temp->getNMaterias() ; i++ ){
			
			cursos->primero();
			
			while ( cursos->hayActual() ){
				
				if ( materias[i] == cursos->ValorActual()->getID() ){
					
					cursos->ValorActual()->ingresarCandidato( new Estudiante(temp) );
					
				}
				
				cursos->siguiente();
			
				
			}
			
		}
		
	}
	
	
}

void Inscripcion::inscribirEstudiantes(){
	
	cursos->primero();
	
	while ( cursos->hayActual() ){
		
		cursos->ValorActual()->mostrarListaCandidatos();
		cursos->ValorActual()->generarListaAsignados();
		cursos->ValorActual()->mostrarListaAsignados();
		cursos->siguiente();
		
	}
	
}

void Inscripcion::listaCursos(){
	
	if ( !cursos->listaVacia() ){
		
		cursos->Mostrar();
		
	}
	
}
