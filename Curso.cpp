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

void Curso::generarListaAsignados(){
	
	candidatos->ordenarPrioridad(prioridad);
	
	while ( listaAsignados->getElementos() < this->cupos && !candidatos->estaVacia()  ){
		
		listaAsignados->encolar ( candidatos->desencolar() );
		listaAsignados->actualizarEstadoInscripcion(true);
		listaAsignados->asignarPosiciones();
		
	}
		
	while ( !candidatos->estaVacia() ){
		
		listaEspera->encolar ( candidatos->desencolar() );
		listaAsignados->actualizarEstadoInscripcion(false);
		listaEspera->asignarPosiciones();
		
	}
	
	asignarMaterias();
	
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

void Curso::ingresarCandidato(Estudiante *estudiante){
	
	candidatos->encolar(estudiante);
	
}

void Curso::mostrarListaAsignados(){
	
	if ( !listaAsignados->estaVacia() ){
		
		cout << "Asignados: ";
		listaAsignados->imprimir();
		
	}
	
}

void Curso::mostrarListaEspera(){
	
	if ( !listaEspera->estaVacia() ){
		
		cout << " En espera: ";
		listaEspera->imprimir();
		
	}
	
}

void Curso::mostrarListaCandidatos(){
	
	if ( !candidatos->estaVacia() ){
		
		cout << " Candidatos: ";
		candidatos->imprimir();
		
	}
	
}
