#include "Cola.h"

Cola::Cola(){
	
	inicio = fin = NULL;
	elementos = 0;
	
}

Cola::Cola( Cola *cola ){
	
	if ( !cola->estaVacia() ){
		
		Nodo *temp = inicio;
		
		while ( temp ){
			
			encolar( new Estudiante( temp->getEstudiante() ) );
			temp = temp->getSiguiente();
			
		}
		
	}
	
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
	int n = 0;
	
	while ( aux ){
		
		n++;
		aux->setPosicion( n );
		aux = aux->getSiguiente();
		
	}
	
}

void Cola::actualizarEstadoInscripcion( bool estado ){
	
	Nodo *aux = inicio;
	
	while ( aux ){
		
		aux->getEstudiante()->setEstado( estado );
		aux= aux->getSiguiente();
		
	}
	
}

void Cola::imprimir(){
	
	if ( !estaVacia() ){
		
		Nodo *aux;
	
		aux = inicio;
	
		while ( aux ){
		
			aux->getEstudiante()->mostrarInfo();
			cout << "\n";
			aux = aux->getSiguiente();
		
		}
		
	}
	
	else{
		
		cout << "Cola vacia";
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
	
	else {
		
		cout << "\nNo hay materias\n";
		system("pause");
		
	}
	
}

Cola::~Cola(){
	;
}
