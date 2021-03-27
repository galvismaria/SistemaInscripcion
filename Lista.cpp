#include "Lista.h"

template <typename T>
Lista<T>::Lista(){
	
    principio = actual = NULL;
    
}

template <typename T>
bool Lista<T>::listaVacia(){
	
    return principio == NULL;
    
}

template <typename T>
bool Lista<T>::hayActual(){
	
	return actual != NULL;
	
}

template <typename T>
void Lista<T>::insertar( T *info ){
	
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

template <typename T>
void Lista<T>::siguiente(){
	
    if ( actual )
    
        actual = actual->siguiente;
        
}

template <typename T>
bool Lista<T>::haySiguiente(){
	
	return ( actual->siguiente == NULL) ;
	
}

template <typename T>
void Lista<T>::primero(){
	
    actual = principio;
    
}

template <typename T>
void Lista<T>::ultimo(){
	
    primero();
    
    if ( !listaVacia() ){
        	
        while ( actual->siguiente ){
        	
        	siguiente();
        	
		}
        	
	}
                
}

template <typename T>
T* Lista<T>::valorActual(){
	
    return actual->info;
    
}

template <typename T>
void Lista<T>::imprimir(){
	
	Nodo* aux = principio;
	
	while ( aux ){
		
		aux->info->mostrarInfo();
		aux = aux->siguiente;
	}
	
}

template <typename T>
T* Lista<T>::buscar( int info ){
	
	Nodo* aux = principio;
	
	while ( aux ){
		
		if ( aux->info->getInfo() == info ){
			
			return aux->info;
			
		}
		
		aux = aux->siguiente;
	}
	
	return NULL;
	
}

template <typename T>
Lista<T>::~Lista(){
	
    Nodo* aux;

    while ( principio ){
    	
        aux = principio;
        principio = principio->siguiente;
        delete aux;
        
    }

    actual = NULL;
}

template class Lista<Curso>;
template class Lista<Estudiante>;
