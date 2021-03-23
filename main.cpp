#include "Cola.h"

int main(){
	
	Estudiante *est1 = new Estudiante("Maria", "Ing", 12345, 5, 2, 10);
	Estudiante *est2 = new Estudiante("Jose", "Ing", 12345, 7, 3, 10);
	Estudiante *est3 = new Estudiante("Jesus", "Ing", 12345, 6, 1, 10);
	
	Cola *cola = new Cola();
	
	cola->encolarPorIndice(est1);
	cola->encolarPorIndice(est2);
	cola->encolarPorIndice(est3);

	cola->imprimir();
	
}
