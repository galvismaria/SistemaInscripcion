#include "Estudiante.h"

Estudiante::Estudiante(){
	
	nombre = "\0";
	carrera = "\0";
	cedula = 0;
	indice = 0;
	nivel = 0;
	creditos = 0;
	
}

Estudiante::Estudiante( string nombre, string carrera, int cedula, float indice, int nivel, int creditos ){
	
	this->nombre = nombre;
	this->carrera = carrera;
	this->cedula = cedula;
	this->indice = indice;
	this->nivel = nivel;
	this->creditos = creditos;
	
	for ( int i = 0 ; i < MAX_MATERIAS ; i++ ){
		
		this->materias[i].id = 0;
		this->materias[i].lugar = 0;
		this->materias[i].asignado = false;
		
	}
	
}

Estudiante::Estudiante( Estudiante *estudiante ){
	
	this->nombre = estudiante->nombre;
	this->carrera = estudiante->carrera;
	this->cedula = estudiante->cedula;
	this->indice = estudiante->indice;
	this->nivel = estudiante->nivel;
	this->creditos = estudiante->creditos;
	
	for ( int i = 0 ; i < MAX_MATERIAS ; i++ ){
		
		this->materias[i] = estudiante->materias[i];
		
	}
	
	
}

void Estudiante::setNombre( string nombre ){
	
	this->nombre = nombre;
	
}

void Estudiante::setCarrera( string carrera ){
	
	this->carrera = carrera;
	
}

void Estudiante::setIndice( float indice ){
	
	this->indice = indice;
	
}

void Estudiante::setNivel( int nivel ){
	
	this->nivel = nivel;
	
}

void Estudiante::setCreditos( int creditos ){
	
	this->creditos = creditos;
	
}

void Estudiante::setMateria( int id, bool asignado, int lugar ){
	
	for ( int i = 0 ; i < MAX_MATERIAS ; i++ ){
		
		if ( ( this->materias[i].id == id ) && id > 0){
			
			this->materias[i].asignado = asignado;
			this->materias[i].lugar = lugar;
			return;
			
		}
		
	}
	
	for ( int i = 0 ; i < MAX_MATERIAS ; i++ ){
		
		if ( this->materias[i].id == 0 ){
			
			this->materias[i].id = id;
			this->materias[i].asignado = asignado;
			this->materias[i].lugar = lugar;
			return;
			
		}
		
	}
	
}

void Estudiante::setMaterias( Estudiante *estudiante ){
	
	for ( int i = 0 ; i < MAX_MATERIAS ; i++ ){
		
		for ( int j = 0 ; j < MAX_MATERIAS ; j++ ){
			
			if ( ( this->materias[i].id  == estudiante->materias[j].id ) && estudiante->materias[j].lugar > 0 ){
			
				this->materias[i].asignado = estudiante->materias[j].asignado;
				this->materias[i].lugar = estudiante->materias[j].lugar;
			
			}
			
		}
		
	}
	
}

string Estudiante::getNombre(){
	
	return nombre;
	
}

string Estudiante::getCarrera(){
	
	string tempCarrera = this->carrera;
	
	replace( tempCarrera.begin(), tempCarrera.end(), '-', ' ');
	
	return tempCarrera;
	
}

int Estudiante::getCedula(){
	
	return cedula;
	
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

int Estudiante::getInfo(){
	
	return cedula;
	
}

void Estudiante::obtenerMaterias( int arr[] ){
	
	for ( int i = 0 ; i < MAX_MATERIAS ; i++ ){
		
		arr[i] = materias[i].id;
		
	}
	
}

bool Estudiante::tienePrioridad( Estudiante *estudiante, int caso ){
	
	switch( caso ){
		
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

void Estudiante::mostrarInfo(){
	
	cout << "\tNombre:\t" << this->nombre << " \n";
	cout << "\tCedula:\t" << this->cedula << " \n";
	cout << "\tCarrera: " << this->getCarrera() << " \n";
	cout << "\tIndice:\t" << this->indice << " \n";
	cout << "\tNivel:\t" << this->nivel << " \n";
	cout << "\tUC:\t" << this->creditos << " \n";
	
}

void Estudiante::mostrarDetalleMateria( int id ){
	
	for ( int i = 0 ; i < MAX_MATERIAS ; i++ ){
		
		if ( (id != 0) && materias[i].id ==id ){
			
			cout << "\tEstatus: ";
			
			if ( materias[i].asignado )
				cout << "Inscrito" << "\n";
				
			if ( !materias[i].asignado )
				cout << "En espera" << "\n";
				
			cout << "\tPuesto: " << materias[i].lugar << " \n";
			
		}
		
	}
	
}

Estudiante::~Estudiante(){
	
	;
	
}
