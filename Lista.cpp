#include "Lista.h"

Lista::Lista(){
	
    principio = actual = NULL;
    
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

bool Lista::listaVacia(){
	
    return principio == NULL;
    
}

void Lista::insertar(Curso *curso){
	
	Nodo* temp;

    if ( listaVacia() ){
    	
        principio = new Nodo();
        principio->siguiente = principio;
        principio->curso = curso;
        
    } else{
    	
        ultimo();
        actual->siguiente = new Nodo();
        actual->siguiente->siguiente = actual->siguiente;
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
    
    if (!listaVacia()){
        	
        while (actual->siguiente){
        	
        	siguiente();
        	
		}
        	
	}
                
}

Curso* Lista::ValorActual(){
	
    return actual->curso;
    
}

void Lista::Mostrar() {
	
   Nodo* aux;

   aux = principio;
   
	while (aux) {
		
		cout << aux->curso->getNombre() << "-> ";
    	aux = aux->siguiente;
      
   }
   
   cout << endl;
}

Curso* Lista::getPrincipio(){
	
	return principio->curso;
	
}
