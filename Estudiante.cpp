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

Estudiante::Estudiante( string nombre, string carrera, int cedula, float indice, int nivel, int creditos ){
	
	this->nombre = nombre;
	this->carrera = carrera;
	this->cedula = cedula;
	this->indice = indice;
	this->nivel = nivel;
	this->creditos = creditos;
	this->inscrito = false;
	this->nMaterias = 0;
	
}

Estudiante::Estudiante( Estudiante *estudiante ){
	
	this->nombre = estudiante->nombre;
	this->carrera = estudiante->carrera;
	this->cedula = estudiante->cedula;
	this->indice = estudiante->indice;
	this->nivel = estudiante->nivel;
	this->creditos = estudiante->creditos;
	this->inscrito = estudiante->inscrito;
	this->nMaterias = estudiante->nMaterias;
	
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

void Estudiante::setEstado( bool inscrito ){
	
	this->inscrito = inscrito;
	
}

void Estudiante::setNMaterias( int nMaterias ){
	
	this->nMaterias = nMaterias;
	
}

void Estudiante::setMateria( int id, bool asignado, int lugar ){
	
	for ( int i = 0 ; i < nMaterias ; i++ ){
		
		if ( this->materias[i].id == id ){
			
			this->materias[i].asignado = asignado;
			this->materias[i].lugar = lugar;
			return;
			
		}
		
	}
	
	this->materias[nMaterias].id = id;
	this->materias[nMaterias].asignado = asignado;
	this->materias[nMaterias].lugar = lugar;
	nMaterias++;
	
}

string Estudiante::getNombre(){
	
	return nombre;
	
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

int Estudiante::getNMaterias(){
	
	return nMaterias;
	
}

bool Estudiante::estaInscrito(){
	
	return inscrito;
	
}

void Estudiante::obtenerMaterias( int arr[] ){
	
	for ( int i = 0 ; i < nMaterias ; i++ ){
		
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
	
	cout << "Nombre: " << this->nombre << " \n";
	cout << "Indice academico: " << this->indice << " \n";
	cout << "Nivel: " << this->nivel << " \n";
	cout << "Creditos aprobados: " << this->creditos << " \n";
	
}

string Estudiante::listaMaterias( int id ){
	
	char *MATERIAS[] = { "Simulacion informatica",
							"Arquitectira del computador", 
							"Sistema de bases de datos",
							"Redes de computadoras",
							"Sistemas distribuidos",
							"Sistemas de operacion",
							"Informatica industrial",
							"Innovacion y desarrollo",
							"Ingenieria del software",
							"Lenguajes de compiladores"
							 };
	
	string str(MATERIAS[id-1]);
	
	return str;
	
};

void Estudiante::mostrarMaterias(){
	
	cout << "Nombre: " << this->nombre << " \n";
	
	for ( int i = 0 ; i < nMaterias ; i++ ){
		
		cout << "\nMateria: " << listaMaterias( materias[i].id ) << "\n";
		cout << "Estatus: ";
		if ( materias[i].asignado )
			cout << "Inscrito" << "\n";
		if ( !materias[i].asignado )
			cout << "En espera" << "\n";
		cout << "Puesto: " << materias[i].lugar << " \n";
		
	}
	
}

Estudiante::~Estudiante(){
	;
}
