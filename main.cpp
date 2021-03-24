#include "Cola.h"
#include "Curso.h"
#include "Global.h"

int main(){
	
	Estudiante *est1 = new Estudiante("Maria", "Ing", 12345, 10, 2, 15);
	Estudiante *est2 = new Estudiante("Jose", "Ing",  12345, 7,  4, 10);
	Estudiante *est3 = new Estudiante("Jesus", "Ing", 12345, 10, 4, 20);
	Estudiante *est4 = new Estudiante("Luis", "Ing",  12345, 7,  2, 20);
	Estudiante *est5 = new Estudiante("Ala", "Ing",   12345, 7,  3, 20);
	Cola *cola = new Cola();
	
	cola->encolar(est1);
	cola->encolar(est2);
	cola->encolar(est3);
	cola->encolar(est4);
	cola->encolar(est5);
	
	Curso *curso = new Curso("Matematicas", 1, 3);
	Curso *otroCurso = new Curso("Informatica", 2, 2);
	
	curso->generarListaAsignados(cola, 1);
	
	cola->encolar(est1);
	cola->encolar(est2);
	cola->encolar(est3);
	cola->encolar(est4);
	cola->encolar(est5);
	
	otroCurso->generarListaAsignados(cola, 2);
	
	
	curso->mostrarListaAsignados();
	curso->mostrarListaEspera();
	otroCurso->mostrarListaAsignados();
	otroCurso->mostrarListaEspera();
	est5->mostrarMaterias();
}
