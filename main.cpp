#include "Cola.h"
#include "Curso.h"
#include "Lista.h"
#include "Inscripcion.h"
#include "Global.h"

int main(){

	Inscripcion *ins = new Inscripcion();
	
	ins->cargarCursos();
	ins->cargarEstudiantes();
	ins->mostrarEstudiantes();

}
