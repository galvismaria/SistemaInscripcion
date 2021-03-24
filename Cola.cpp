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

void Cola::encolarAtras(Estudiante *estudiante){
     
    Nodo *nuevo = new Nodo(estudiante);
    
    if( inicio == NULL){
    	inicio = nuevo;
    	elementos++;
	}
	
	else{
		fin->setSiguiente(nuevo);
		elementos++;
	}
	
	fin = nuevo;
	nuevo->setPosicion(elementos);
     
}

void Cola::encolarAdelante(Estudiante *estudiante){
	
	if ( inicio ){
		
		inicio = new Nodo ( estudiante, inicio );
	}
	
}

void Cola::encolarLuegoDe(Estudiante *estudiante, Nodo *lugar){
	
	Nodo *temp = inicio;
	
	if ( !lugar->getSiguiente() ){
		
		encolarAtras(estudiante);
		
	}
	
	else{
		
		while ( temp->getSiguiente() && temp->getSiguiente() != lugar){
		
			temp = temp->getSiguiente();
		
		}
	
	temp->setSiguiente( new Nodo(estudiante, temp->getSiguiente() ) );
		
	}

}

Estudiante* Cola::desencolar(){
	
	Nodo* nAux;
	Estudiante* aux;
	
	nAux = inicio;
	
	if ( !nAux )
		return NULL;
		
	inicio = nAux->getSiguiente();
	aux = nAux->getEstudiante();
	delete nAux;
	
	if ( !inicio )
		fin = NULL;
		
	return aux;
}

void Cola::encolarPorIndice( Estudiante *estudiante ){
	
	Nodo* temp;

    if (estaVacia() || inicio->getEstudiante() < estudiante ){

        inicio = new Nodo ( estudiante, inicio );
        
    } else{

        temp = inicio;
        
        while (temp->getSiguiente() && ( estudiante < temp->getSiguiente()->getEstudiante() ) ){
            temp = temp->getSiguiente();
        }
        
        temp->setSiguiente( new Nodo(estudiante, temp->getSiguiente() ) );
    }
	
}

void Cola::encolarPorNivel( Estudiante *estudiante ){
	
	Nodo* temp;

    if (estaVacia() || inicio->getEstudiante()->getNivel() < estudiante->getNivel() ){

        inicio = new Nodo ( estudiante, inicio );
        
    } else{

        temp = inicio;
        
        while (temp->getSiguiente() && temp->getSiguiente()->getEstudiante()->getNivel() >= estudiante->getNivel() ){
            temp = temp->getSiguiente();
        }
        
        temp->setSiguiente( new Nodo(estudiante, temp->getSiguiente() ) );
    }
	
}

void Cola::encolarPorCreditos( Estudiante *estudiante ){
	
	Nodo* temp;

    if (estaVacia() || inicio->getEstudiante()->getCreditos() < estudiante->getCreditos() ){

        inicio = new Nodo ( estudiante, inicio );
        
    } else{

        temp = inicio;
        
        while (temp->getSiguiente() && temp->getSiguiente()->getEstudiante()->getCreditos() >= estudiante->getCreditos() ){
        	
            temp = temp->getSiguiente();
            
        }
        
        temp->setSiguiente( new Nodo(estudiante, temp->getSiguiente() ) );
    }
	
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
	
	Nodo *aux;
	
	aux = inicio;
	elementos = 0;
	
	while ( aux ){
		
		elementos++;
		aux->setPosicion(elementos);
		aux = aux->getSiguiente();
		
	}
	
}

void Cola::imprimir(){
	
	Nodo *aux;
	
	aux = inicio;
	
	while ( aux ){
		
		cout << " -> " << aux->getEstudiante()->getNombre() << " (" << aux->getPosicion() << ") ";
		aux = aux->getSiguiente();
		
	}
	
	cout << "\n";
	
}
