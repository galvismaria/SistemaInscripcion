#include "Cola.h"

Cola::Cola(){
	
	inicio = fin = NULL;
	
}

bool Cola::estaVacia(){
	
	if ( !inicio && !fin )
		return true;
		
	return false;
	
}

void Cola::encolar(Estudiante *estudiante){
     
    Nodo *nuevo = new Nodo(estudiante);
    
    if( inicio == NULL){
    	inicio = nuevo;
	}
	
	else{
		fin->setSiguiente(nuevo);
	}
	
	fin = nuevo;
     
}

//void Cola::ordenarIndice(){
//	
//	Nodo *aux1, *aux2, *aux3;
//	
//	aux1 = inicio;
//	
//	while ( aux1->getSiguiente() ){
//		
//		aux2 = aux1->getSiguiente();
//		
//		while ( aux2 ){
//			
//			if ( aux1->getEstudiante()->getIndice() > aux2->getEstudiante()->getIndice() ){
//				
//				aux3 = aux1;
//				
//				aux1 = aux2;
//				
//				aux2 = aux3;
//				
//			}
//			
//			aux2 = aux2->getSiguiente();
//			
//		}
//		
//		aux1 = aux1->getSiguiente();
//		
//	}
//	
//}

void Cola::encolarPorIndice( Estudiante *estudiante ){
	
	Nodo* temp;

    if (estaVacia() || inicio->getEstudiante()->getIndice() < estudiante->getIndice() ){

        inicio = new Nodo ( estudiante, inicio );
        
    } else{

        temp = inicio;
        
        while (temp->getSiguiente() && temp->getSiguiente()->getEstudiante()->getIndice() >= estudiante->getIndice() ){
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



void Cola::imprimir(){
	
	Nodo *aux;
	
	aux = inicio;
	
	while ( aux ){
		
		cout << " -> " << aux->getEstudiante()->getIndice();
		aux = aux->getSiguiente();
		
	}
	
	cout << "\n";
	
}
