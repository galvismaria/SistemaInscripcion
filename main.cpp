#include "Inscripcion.h"


int main(){

	Inscripcion *ins = new Inscripcion();
	ins->menuPrincipal();
	ins->~Inscripcion();
	return 0;
}

