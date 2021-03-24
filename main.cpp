#include "Cola.h"
#include "Curso.h"

int main(){
	
	Estudiante *est1 = new Estudiante("Maria", "Ing", 12345, 10, 2, 15);
	Estudiante *est2 = new Estudiante("Jose", "Ing",  12345, 7,  4, 10);
	Estudiante *est3 = new Estudiante("Jesus", "Ing", 12345, 10, 4, 20);
	Estudiante *est4 = new Estudiante("Luis", "Ing",  12345, 7,  2, 20);
	Estudiante *est5 = new Estudiante("Ala", "Ing",   12345, 7,  3, 20);
	Cola *cola = new Cola();
	
	cola->encolarAtras(est1);
	cola->encolarAtras(est2);
	cola->encolarAtras(est3);
	cola->encolarAtras(est4);
	cola->encolarAtras(est5);
	
	
	cola->ordenarPrioridad(3);
	cola->asignarPosiciones();
	
	//cola->ordenarNivel();
	
	cola->imprimir();
}
