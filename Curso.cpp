#include "Curso.h"

Curso::Curso(){
	
	nombre = "\0";
	id = 0;
	cupos = 0;
	listaAsignados = new Cola();
	listaEspera = new Cola();
	
}

Curso::Curso(string nombre, int id, int cupos){
	
	this->nombre = nombre;
	this->id = id;
	this->cupos = cupos;
	listaAsignados = new Cola();
	listaEspera = new Cola();
	
}

void Curso::generarListaAsignados( Cola *candidatos, int caso ){
	
	Cola *temp = new Cola();
	
	while ( !candidatos->estaVacia() ){
		
		temp->encolar( candidatos->desencolar() );
		
	}
	
	temp->ordenarPrioridad(caso);
	
	while ( listaAsignados->getElementos() < this->cupos ){
		
		listaAsignados->encolar ( temp->desencolar() );
		listaAsignados->actualizarEstadoInscripcion(true);
		listaAsignados->asignarPosiciones();
		
	}
		
	while ( !temp->estaVacia() ){
		
		listaEspera->encolar ( temp->desencolar() );
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
			
			recorr->getEstudiante()->setMateria( this->nombre, true, recorr->getPosicion() );
			recorr = recorr->getSiguiente();
			
		}
		
	}
	
	if ( !listaEspera->estaVacia() ){
		
		Nodo *recorr = listaEspera->getInicio();
		Estudiante *aux = new Estudiante();
		
		while ( recorr ){
			
			recorr->getEstudiante()->setMateria( this->nombre, false, recorr->getPosicion() );
			recorr = recorr->getSiguiente();
			
		}
		
	}
	
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
