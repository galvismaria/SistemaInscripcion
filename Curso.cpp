#include "Curso.h"

Curso::Curso(){
	
	nombre = "\0";
	id = 0;
	cupos = 0;
	prioridad = 0;
	listaAsignados = new Lista<Estudiante>();
	listaEspera = new Lista<Estudiante>();
	candidatos = new Cola();
	
}

Curso::Curso(string nombre, int id, int cupos, int prioridad){
	
	this->nombre = nombre;
	this->id = id;
	this->cupos = cupos;
	this->prioridad = prioridad;
	listaAsignados = new Lista<Estudiante>();
	listaEspera = new Lista<Estudiante>();
	candidatos = new Cola();
	
}

void Curso::setID(int id){
	
	this->id = id;
	
}

void Curso::setCupos(int cupos){
	
	this->cupos = cupos;
	
}

void Curso::setPrioridad(int prioridad){
	
	this->prioridad = prioridad;
	
}

string Curso::getNombre(){
	
	return nombre;
	
}

int Curso::getID(){
	
	return id;
	
}

int Curso::getInfo(){
	
	return id;
}

int Curso::getEstudiantesInscritos(){
	
	return listaAsignados->cantElementos();
	
}

int Curso::getEstudiantesSinCupo(){
	
	return listaEspera->cantElementos();
	
}

void Curso::generarListaAsignados(){
	
	if ( !candidatos->estaVacia() ){
		
		candidatos->ordenarPrioridad( prioridad );
	
		while ( listaAsignados->cantElementos() < this->cupos && !candidatos->estaVacia()  ){
		
			listaAsignados->insertar ( candidatos->desencolar() );
			listaAsignados->asignarPosiciones();
		
		}
		
		while ( !candidatos->estaVacia() ){
		
			listaEspera->insertar ( candidatos->desencolar() );
			listaEspera->asignarPosiciones();
		
		}
	
		asignarMaterias();
		
	}
	
}

void Curso::asignarMaterias(){
	
	if ( !listaAsignados->listaVacia() ){
		
		listaAsignados->primero();
		
		while ( listaAsignados->hayActual() ){
			
			listaAsignados->valorActual()->setMateria ( this->id, true, listaAsignados->posicionActual() );
			listaAsignados->siguiente();
			
		}
		
	}
	
	if ( !listaEspera->listaVacia() ){
		
		listaEspera->primero();
		
		while ( listaEspera->hayActual() ){
			
			listaEspera->valorActual()->setMateria ( this->id, false, listaEspera->posicionActual() );
			listaEspera->siguiente();
			
		}
		
	}
	
}

void Curso::ingresarCandidato( Estudiante *estudiante ){
	
	candidatos->encolar( estudiante );
	
}

void Curso::mostrarInfo(){
	
	cout << "\tID: " << this->getID() << " \n";
	
}

void Curso::mostrarDetalles(){
	
	cout << "\tCupos: " << this->cupos << " \n";
	cout << "\tTipo de prioridad: ";
	
	switch ( this->prioridad ){
		
		case 1:
			
			cout << "Indice academico, nivel actual" << " \n";
			break;
		
		case 2:
			
			cout << "Nivel actual, indice academico" << " \n";
			break;
			
		case 3:
			
			cout << "Numero de creditos aprobados, indice academico" << " \n";
			break;
		
		default:
			
			break;
		
	};
	
	cout << "\n";
	
}


void Curso::mostrarListaAsignados(){
	
	if ( !listaAsignados->listaVacia() ){
		
		cout << "\t\t\t- Asignados -" << " \n\n";
		listaAsignados->imprimirConPosiciones();
		
	}
	
	else{
		cout << "\tNo hay estudiantes asignados\n\n";
	}
	
}

void Curso::mostrarListaEspera(){
	
	if ( !listaEspera->listaVacia() ){
		
		cout << "\t\t\t- En espera -" << " \n\n";
		listaEspera->imprimirConPosiciones();
		
	}
	
	else{
		cout << "\tNo hay estudiantes en lista de espera\n\n";
	}
	
}

void Curso::mostrarListaCandidatos(){
	
	if ( !candidatos->estaVacia() ){
		
		cout << "\t\t\t- Candidatos -" << " \n\n";
		candidatos->imprimir();
		
	}
	
	else{
		cout << "\tNo hay estudiantes candidatos\n\n";
	}
	
}

void Curso::mostrarResultados(){
	
	cout << "\t--------------------------------------------------------------------------" << " \n\n";
	cout << "\n";
	mostrarListaAsignados();
	mostrarListaEspera();
	cout << "\t--------------------------------------------------------------------------" << " \n\n";
	
}

void Curso::crearLista( Lista<Estudiante> *lista ){
	
	if ( !listaAsignados->listaVacia() ){
		
		listaAsignados->primero();
		
		while ( listaAsignados->hayActual() ){
			
			lista->insertar( new Estudiante( listaAsignados->valorActual() ) );
			listaAsignados->siguiente();
		}
		
	}
	
	if ( !listaEspera->listaVacia() ){
		
		listaEspera->primero();
		
		while ( listaEspera->hayActual() ){
			
			lista->insertar( new Estudiante( listaEspera->valorActual() ) );
			listaEspera->siguiente();
			
		}
		
	}
	
}

Curso::~Curso(){
	
	delete &nombre;
	delete &id;
	delete &cupos;
	delete &prioridad;
	delete [] listaAsignados;
	delete [] listaEspera;
	delete [] candidatos;
	
}
