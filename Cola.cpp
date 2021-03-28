#include "Cola.h"

Cola::Cola(){
	
	inicio = fin = NULL;
	elementos = 0;
	
}

Nodo* Cola::getInicio(){
	
	return inicio;
	
}

Nodo* Cola::getFin(){
	
	return fin;
	
}

int Cola::getElementos(){
	
	return elementos;
	
}

bool Cola::estaVacia(){
	
	if ( !inicio && !fin )
	
		return true;
		
	return false;
	
}

void Cola::encolar( Estudiante *estudiante ){
     
    Nodo *nuevo = new Nodo( estudiante );
    
    if( inicio == NULL){
    	
    	inicio = nuevo;
    	
	}
	
	else{
		
		fin->setSiguiente( nuevo );
		
	}
	
	fin = nuevo;
	elementos++;
     
}

Estudiante* Cola::desencolar(){
	
	Nodo* nAux;
	Estudiante* aux;
	
	nAux = inicio;
	
	if ( !nAux ){
		
		return NULL;
		
	}
		
	inicio = nAux->getSiguiente();
	aux = nAux->getEstudiante();
	delete nAux;
	
	if ( !inicio ){
		
		fin = NULL;
		
	}
	
	elementos--;
	return aux;
}

void Cola::ordenarPrioridad( int caso ){
	
	Nodo *actual, *next, *aux;
	aux = new Nodo();
	
	actual = inicio;
	
	while ( actual->getSiguiente() ){
		
		next = actual->getSiguiente();
		
		while ( next ){
			
			if ( next->getEstudiante()->tienePrioridad( actual->getEstudiante(), caso ) ){
				
				aux->setEstudiante( next->getEstudiante() );
				next->setEstudiante( actual->getEstudiante() );
				actual->setEstudiante( aux->getEstudiante() );
				
			}
			
			next = next->getSiguiente();
			
		}
		
		actual = actual->getSiguiente();
		
	}
	
}


void Cola::asignarPosiciones(){
	
	Nodo *aux = inicio;
	int n = 1;
	
	while ( aux ){
		
		aux->setPosicion( n );
		aux = aux->getSiguiente();
		n++;
		
	}
	
}

void Cola::imprimir(){
	
	if ( !estaVacia() ){
		
		Nodo *aux;
	
		aux = inicio;
	
		while ( aux ){
			
			cout << "\t#" << aux->getPosicion() << "\n";
			aux->getEstudiante()->mostrarInfo();
			cout << "\n";
			aux = aux->getSiguiente();
		
		}
		
	}
	
}

void Cola::imprimirMateriasEstudiante(string nombre){
	
	if ( !estaVacia() ){
		
		Nodo *aux;
	
		aux = inicio;
	
		while ( aux ){
			
			if ( aux->getEstudiante()->getNombre() == nombre ){
				
				aux->getEstudiante()->mostrarMaterias();
				break;
				
			}
			
			aux = aux->getSiguiente();
		
		}
		
	}
	
}

Cola::~Cola(){
	
	while ( inicio ){
		
		desencolar();
		
	}
	
}
