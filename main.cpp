#include "Inscripcion.h"


int main(){

	Inscripcion *ins = new Inscripcion();
	ins->cargarCursos();
	ins->cargarEstudiantes();
	ins->cargarInscripciones();
	ins->asignarCandidatos();
	ins->mostrarCandidatos();
	

}
