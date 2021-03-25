#include "Cola.h"
#include "Curso.h"
#include "Lista.h"
#include "Inscripcion.h"
#include "Global.h"
#include "ArchivoBinario.h"

int main(){
	
	Estudiante *est1 = new Estudiante("Maria", "Ing", 12345, 10, 4, 15);
	Estudiante *est2 = new Estudiante("Jose", "Ing",  12345, 7,  4, 10);
	Estudiante *est3 = new Estudiante("Jesus", "Ing", 12345, 9, 4, 20);
	Estudiante *est4 = new Estudiante("Luis", "Ing", 12345, 10, 1, 15);
	Estudiante *est5 = new Estudiante("Ana", "Ing",  12345, 7,  4, 10);
	Estudiante *est6 = new Estudiante("Sara", "Ing", 12345, 8, 4, 20);
	
	est1->setMateria(1,false, 0);
	est2->setMateria(1, false, 0);
	est3->setMateria(1, false, 0);
	est4->setMateria(1,false, 0);
	est5->setMateria(1, false, 0);
	est6->setMateria(1, false, 0);
	
	Lista *lista = new Lista();
	
	
	
	
	Inscripcion *ins = new Inscripcion();
	
	ins->ingresarEstudiantes(est1);
	ins->ingresarEstudiantes(est2);
	ins->ingresarEstudiantes(est3);
	ins->ingresarEstudiantes(est4);
	ins->ingresarEstudiantes(est5);
	ins->ingresarEstudiantes(est6);
	
	readFile(ins);
	
	
	
	//ins->listaCursos();
	ins->asignarCandidatos();
	ins->inscribirEstudiantes();
//	curso->ingresarCandidato(est1);
//	curso->ingresarCandidato(est2);
//	curso->ingresarCandidato(est3);
//	curso->ingresarCandidato(est4);
//	curso->ingresarCandidato(est5);
//	curso->ingresarCandidato(est6);
//	
//	curso->mostrarListaCandidatos();
//	curso->generarListaAsignados(1);
//	curso->mostrarListaAsignados();
//	curso->mostrarListaEspera();

}
