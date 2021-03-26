#include "Lista.h"

Lista::Lista(){
	
    principio = actual = NULL;
    
}

bool Lista::listaVacia(){
	
    return principio == NULL;
    
}

bool Lista::hayActual(){
	
	return actual != NULL;
	
}

void Lista::insertar( Curso *info ){
	
	Nodo* temp;

    if ( listaVacia() ){
    	
        principio = new Nodo();
        principio->siguiente = NULL;
        principio->info = info;
        
    } else{
    	
        ultimo();
        actual->siguiente = new Nodo();
        actual->siguiente = actual->siguiente;
        actual->siguiente->info = info;
        
    }
	
}

void Lista::siguiente(){
	
    if ( actual )
    
        actual = actual->siguiente;
        
}

bool Lista::haySiguiente(){
	
	return ( actual->siguiente == NULL) ;
	
}

void Lista::primero(){
	
    actual = principio;
    
}

void Lista::ultimo(){
	
    primero();
    
    if ( !listaVacia() ){
        	
        while ( actual->siguiente ){
        	
        	siguiente();
        	
		}
        	
	}
                
}

Curso* Lista::valorActual(){
	
    return actual->info;
    
}

void Lista::imprimirResultadoID( int id ){
	
	Nodo *aux;
	
	aux = principio;
	
	while ( aux ){
			
		if ( aux->info->getID() == id ){
				
			aux->info->mostrarResultados();
				
		}
		
		aux = aux->siguiente;
		
	}
		
}

void Lista::imprimir(){
	
	Nodo *aux;
	
	aux = principio;
	
	while ( aux ){
			
		cout <<"\n\t"<< aux->info->listaMaterias( aux->info->getID() ) << " (" << aux->info->getID() <<")\n"; 
		
		aux = aux->siguiente;
		
	}
		
}

Lista::~Lista(){
	
    Nodo* aux;

    while ( principio ){
    	
        aux = principio;
        principio = principio->siguiente;
        delete aux;
        
    }

    actual = NULL;
}
