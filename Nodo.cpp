#include "Nodo.h"

Nodo::Nodo(){
	estudiante = NULL;
	siguiente = NULL;
	posicion = 0;
}

Nodo::~Nodo(){
	;
}

Nodo::Nodo(Estudiante *estudiante, Nodo *siguiente, int posicion, int prioridad){
	this->estudiante = estudiante;
	this->siguiente = siguiente;
	this.posicion = posicion;
	this.prioridad = prioridad;
}

Nodo::Nodo(Estudiante *estudiante, Nodo *siguiente){
	this->estudiante = estudiante;
	this->siguiente = siguiente;
	this.posicion = 0;
}

void Nodo::setEstudiante(Estudiante *estudiante){
	this->estudiante = estudiante;
}

void Nodo::setSiguiente(Nodo *siguiente){
	this->siguiente = siguiente;
}

void Nodo::setPosicion(int posicion){
	this.posicion = posicion;
}

void Nodo::setPrioridad(int prioridad){
	this.prioridad = prioridad;
}
