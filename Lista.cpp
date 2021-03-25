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

void Lista::insertar( Curso *curso ){
	
	Nodo* temp;

    if ( listaVacia() ){
    	
        principio = new Nodo();
        principio->siguiente = NULL;
        principio->curso = curso;
        
    } else{
    	
        ultimo();
        actual->siguiente = new Nodo();
        actual->siguiente = actual->siguiente;
        actual->siguiente->curso = curso;
        
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
	
    return actual->curso;
    
}

void Lista::mostrar() {
	
   Nodo* aux;

   aux = principio;
   
	while ( aux ) {
		
		cout << "ID: " << aux->curso->getID() << " ->";
    	aux = aux->siguiente;
      
   }
   
   cout << endl;
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
