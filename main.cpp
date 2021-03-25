#include "Inscripcion.h"


int main(){

	Estudiante *e = new Estudiante("Maria", "Ing", 26753655, 7, 3, 30);
	e->setMateria(5, false, 0);
	e->setMateria(7, false, 0);
	
	Cola *cola = new Cola();
	cola->encolar(e);
	cola->imprimirMateriasEstudiante("Maria");
	

}
