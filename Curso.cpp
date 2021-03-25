#include "Curso.h"

Curso::Curso(){
	
	id = 0;
	cupos = 0;
	prioridad = 0;
	listaAsignados = new Cola();
	listaEspera = new Cola();
	candidatos = new Cola();
	
}

Curso::Curso(int id, int cupos, int prioridad){
	
	this->id = id;
	this->cupos = cupos;
	this->prioridad = prioridad;
	listaAsignados = new Cola();
	listaEspera = new Cola();
	candidatos = new Cola();
	
}

int Curso::getID(){
	
	return id;
	
}

bool Curso::hayCandidatos(){
	
	if ( !candidatos->estaVacia() ){
		
		return true;
		
	}
	
	else{
		
		return false;
		
	}
	
}

bool Curso::hayAsignados(){
	
	if ( !listaAsignados->estaVacia() ){
		
		return true;
		
	}
	
	else{
		
		return false;
		
	}
	
}

void Curso::generarListaAsignados(){
	
	if ( !candidatos->estaVacia() ){
		
		candidatos->ordenarPrioridad( prioridad );
	
		while ( listaAsignados->getElementos() < this->cupos && !candidatos->estaVacia()  ){
		
			listaAsignados->encolar ( candidatos->desencolar() );
			listaAsignados->actualizarEstadoInscripcion( true );
			listaAsignados->asignarPosiciones();
		
		}
		
		while ( !candidatos->estaVacia() ){
		
			listaEspera->encolar ( candidatos->desencolar() );
			listaAsignados->actualizarEstadoInscripcion( false );
			listaEspera->asignarPosiciones();
		
		}
	
		asignarMaterias();
		
	}
	
}

void Curso::asignarMaterias(){
	
	if ( !listaAsignados->estaVacia() ){
		
		Nodo *recorr = listaAsignados->getInicio();
		Estudiante *aux = new Estudiante();
		
		while ( recorr ){
			
			recorr->getEstudiante()->setMateria( this->id, true, recorr->getPosicion() );
			recorr = recorr->getSiguiente();
			
		}
		
	}
	
	if ( !listaEspera->estaVacia() ){
		
		Nodo *recorr = listaEspera->getInicio();
		Estudiante *aux = new Estudiante();
		
		while ( recorr ){
			
			recorr->getEstudiante()->setMateria( this->id, false, recorr->getPosicion() );
			recorr = recorr->getSiguiente();
			
		}
		
	}
	
}

void Curso::ingresarCandidato( Estudiante *estudiante ){
	
	candidatos->encolar( estudiante );
	
}

string Curso::listaMaterias( int id ){
	
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
	
}

void Curso::mostrarInfo(){
	
	cout << "Nombre: " << listaMaterias( id ) << " \n";
	cout << "Cupos disponibles: " << this->cupos << " \n";
	cout << "Tipo de prioridad: ";
	
	switch ( this->prioridad ){
		
		case 1:
			
			cout << "Indice academico, nivel actual" << " \n";
			break;
		
		case 2:
			
			cout << "Nivel actual, indice academico" << " \n";
			break;
			
		case 3:
			
			cout << "Numero de creditos aprobados, indice academico" << " \n";
			break;
		
		default:
			
			break;
		
	};
	
}


void Curso::mostrarListaAsignados(){
	
	if ( !listaAsignados->estaVacia() ){
		
		cout << "ASIGNADOS: ";
		listaAsignados->imprimir();
		
	}
	
}

void Curso::mostrarListaEspera(){
	
	if ( !listaEspera->estaVacia() ){
		
		cout << "EN ESPERA: ";
		listaEspera->imprimir();
		
	}
	
}

void Curso::mostrarListaCandidatos(){
	
	if ( !candidatos->estaVacia() ){
		
		cout << "CANDIDATOS: ";
		candidatos->imprimir();
		
	}
	
}

Curso::~Curso(){
	;
}
