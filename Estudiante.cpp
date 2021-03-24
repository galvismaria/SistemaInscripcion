#include "Estudiante.h"

Estudiante::Estudiante(){
	nombre = "\0";
	carrera = "\0";
	cedula = 0;
	indice = 0;
	nivel = 0;
	creditos = 0;
}

Estudiante::~Estudiante(){
	;
}

Estudiante::Estudiante(string nombre, string carrera, int cedula, float indice, int nivel, int creditos){
	this->nombre = nombre;
	this->carrera = carrera;
	this->cedula = cedula;
	this->indice = indice;
	this->nivel = nivel;
	this->creditos = creditos;
}

void Estudiante::setNombre(string nombre){
	this->nombre = nombre;
}

void Estudiante::setCarrera(string carrera){
	this->carrera = carrera;
}

void Estudiante::setIndice(float indice){
	this->indice = indice;
}

void Estudiante::setNivel(int nivel){
	this->nivel = nivel;
}

void Estudiante::setCreditos(int creditos){
	this->creditos = creditos;
}

void Estudiante::setEstado(bool estado){
	this->estado = estado;
}

string Estudiante::getNombre(){
	return nombre;
}

float Estudiante::getIndice(){
	return indice;
}

int Estudiante::getNivel(){
	return nivel;
}

int Estudiante::getCreditos(){
	return creditos;
}

//bool Estudiante::operator <(const Estudiante &estudiante){
//	
//	return ( ( this->indice < estudiante.indice) || ( ( this->indice == estudiante.indice ) && ( this->nivel <= estudiante.nivel) ) );
//	
//}

bool Estudiante::tienePrioridad(Estudiante *estudiante, int caso){
	
	switch(caso){
		
		case 1:
			if ( this->indice > estudiante->indice )
				return true;
			else if ( ( this->indice == estudiante->indice ) && ( this->nivel >= estudiante->nivel ) )
				return true;
			else
				return false;
		
		case 2:
			if ( this->nivel > estudiante->nivel )
				return true;
			else if ( ( this->nivel == estudiante->nivel ) && ( this->indice >= estudiante->indice ) )
				return true;
			else
				return false;
		
		case 3:
			if ( this->creditos > estudiante->creditos )
				return true;
			else if ( ( this->creditos == estudiante->creditos ) && ( this->indice >= estudiante->indice ) )
				return true;
			else
				return false;
				
		default:
			return false;
		
	}
	
} 
