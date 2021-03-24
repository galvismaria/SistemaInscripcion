#include "Curso.h"

Curso::Curso(){
	
	nombre = "\0";
	id = 0;
	cupos = 0;
	listaAsignados = NULL;
	listaEspera = NULL;
	
}

Curso::Curso(string nombre, int id, int cupos){
	
	this->nombre = nombre;
	this->id = id;
	this->cupos = cupos;
	
}

