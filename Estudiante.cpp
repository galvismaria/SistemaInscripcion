#include "Estudiante.h"

Estudiante::Estudiante(){
	nombre = "\0";
	carrera = "\0";
	cedula = 0;
	indice = 0;
	nivel = 0;
	creditos = 0;
	inscrito = false;
	this->nMaterias = 0;
	
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
	this->inscrito = false;
	this->nMaterias = 0;
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

void Estudiante::setEstado(bool inscrito){
	this->inscrito = inscrito;
}

void Estudiante::setNMaterias(int nMaterias){
	this->nMaterias = nMaterias;
}

void Estudiante::setMateria(string nombre, bool asignado, int lugar){
	
	this->materiasInscritas[nMaterias].nombre = nombre;
	this->materiasInscritas[nMaterias].asignado = asignado;
	this->materiasInscritas[nMaterias].lugar = lugar;
	nMaterias++;
	
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

bool Estudiante::estaInscrito(){
	return inscrito;
}

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

void Estudiante::mostrarEstatus(){
	
	cout << "Nombre: " << this->nombre << " \n";
	cout << "�ndice acad�mico: " << this->indice << " \n";
	cout << "Nivel: " << this->nivel << " \n";
	cout << "Unidades de cr�dito : " << this->creditos << " \n";
	
}

void Estudiante::mostrarMaterias(){
	
	for ( int i = 0 ; i < nMaterias ; i++ ){
		
		cout << "Materia: " << materiasInscritas[i].nombre << " \n";
		cout << "Estatus: ";
		if ( materiasInscritas[i].asignado )
			cout << "Inscrito" << "\n";
		if ( !materiasInscritas[i].asignado )
			cout << "En espera" << "\n";
		cout << "Puesto: " << materiasInscritas[i].lugar << " \n";
		
	}
	
}