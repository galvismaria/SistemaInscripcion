#include "Estudiante.h"

Estudiante::Estudiante(){
	nombre = "\0";
	carrera = "\0";
	cedula = 0;
	indice = 0;
	nivel = 0;
	ucAprobados = 0;
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

float Estudiante::getIndice(){
	return indice;
}
