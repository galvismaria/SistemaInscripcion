#include "Nodo.h"

Nodo::Nodo(){
	
	estudiante = NULL;
	siguiente = NULL;
	posicion = 0;
	
}

Nodo::Nodo( Estudiante *estudiante, Nodo *siguiente, int posicion ){
	
	this->estudiante = estudiante;
	this->siguiente = siguiente;
	this->posicion = posicion;
	
}

Nodo::Nodo( Estudiante *estudiante, Nodo *siguiente ){
	
	this->estudiante = estudiante;
	this->siguiente = siguiente;
	this->posicion = 0;
	
}

Nodo::Nodo( Estudiante *estudiante ){
	
	this->estudiante = estudiante;
	this->siguiente = NULL;
	this->posicion = 0;
	
}

void Nodo::setEstudiante( Estudiante *estudiante ){
	
	this->estudiante = estudiante;
	
}

void Nodo::setSiguiente( Nodo *siguiente ){
	
	this->siguiente = siguiente;
	
}

void Nodo::setPosicion( int posicion ){
	
	this->posicion = posicion;
	
}

Nodo* Nodo::getSiguiente(){
	
	return siguiente;
	
}

Estudiante* Nodo::getEstudiante(){
	
	return estudiante;
	
}

int Nodo::getPosicion(){
	
	return posicion;
	
}

Nodo::~Nodo(){
	
	;
	
}
