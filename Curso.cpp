#include "Curso.h"

Curso::Curso(){
	
	nombre = "\0";
	id = 0;
	cupos = 0;
	prioridad = 0;
	listaAsignados = new Cola();
	listaEspera = new Cola();
	candidatos = new Cola();
	
}

Curso::Curso(string nombre, int id, int cupos, int prioridad){
	
	this->nombre = nombre;
	this->id = id;
	this->cupos = cupos;
	this->prioridad = prioridad;
	listaAsignados = new Cola();
	listaEspera = new Cola();
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
	
	return listaAsignados->getElementos();
	
}

int Curso::getEstudiantesSinCupo(){
	
	return listaEspera->getElementos();
	
}

void Curso::generarListaAsignados(){
	
	if ( !candidatos->estaVacia() ){
		
		candidatos->ordenarPrioridad( prioridad );
	
		while ( listaAsignados->getElementos() < this->cupos && !candidatos->estaVacia()  ){
		
			listaAsignados->encolar ( candidatos->desencolar() );
			listaAsignados->asignarPosiciones();
		
		}
		
		while ( !candidatos->estaVacia() ){
		
			listaEspera->encolar ( candidatos->desencolar() );
			listaEspera->asignarPosiciones();
		
		}
	
		asignarMaterias();
		
	}
	
}

void Curso::asignarMaterias(){
	
	if ( !listaAsignados->estaVacia() ){
		
		Nodo *recorr = listaAsignados->getInicio();
		Estudiante *aux = new Estudiante();
		
		while ( recorr ){
			
			recorr->getEstudiante()->setMateria ( this->id, true, recorr->getPosicion() );
			recorr = recorr->getSiguiente();
			
		}
		
	}
	
	if ( !listaEspera->estaVacia() ){
		
		Nodo *recorr = listaEspera->getInicio();
		Estudiante *aux = new Estudiante();
		
		while ( recorr ){
			
			recorr->getEstudiante()->setMateria ( this->id, false, recorr->getPosicion() );
			recorr = recorr->getSiguiente();
			
		}
		
	}
	
}

void Curso::ingresarCandidato( Estudiante *estudiante ){
	
	candidatos->encolar( estudiante );
	
}

string Curso::listaMaterias( int id ){
	
	char *MATERIAS[] = { "Simulacion informatica",
							"Arquitectira del computador", 
							"Sistema de bases de datos",
							"Redes de computadoras",
							"Sistemas distribuidos",
							"Sistemas de operacion",
							"Informatica industrial",
							"Innovacion y desarrollo",
							"Ingenieria del software",
							"Lenguajes de compiladores",
							"Investigacion de operaciones"
							 };
	
	string str(MATERIAS[id-1]);
	
	return str;
	
}

void Curso::mostrarInfo(){
	
	cout << "\t(ID: " << this->getID() << ") " << listaMaterias( this->getID() ) << " \n";
	cout << " \n";
	
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
	
}


void Curso::mostrarListaAsignados(){
	
	if ( !listaAsignados->estaVacia() ){
		
		cout << "\t\t\t- Asignados -" << " \n\n";
		listaAsignados->imprimir();
		
	}
	
	else{
		cout << "\tNo hay estudiantes asignados\n\n";
	}
	
}

void Curso::mostrarListaEspera(){
	
	if ( !listaEspera->estaVacia() ){
		
		cout << "\t\t\t- En espera -" << " \n\n";
		listaEspera->imprimir();
		
	}
	
	else{
		cout << "\tNo hay estudiantes en lista de espera\n\n";
	}
	
}

void Curso::mostrarListaCandidatos(){
	
	if ( !candidatos->estaVacia() ){
		
		cout << "\t\t* * * " << listaMaterias( id ) << " * * *" << " \n\n";
		
		cout << "\t\t\t- Candidatos -" << " \n\n";
		candidatos->imprimir();
		
	}
	
	else{
		cout << "\tNo hay estudiantes candidatos\n\n";
	}
	
}

void Curso::mostrarResultados(){
	
	cout << "\t--------------------------------------------------------------------------" << " \n\n";
	cout << "\t\t* * * " << listaMaterias( id ) << " * * *" << " \n\n";
	mostrarInfo();
	cout << "\n";
	mostrarListaAsignados();
	mostrarListaEspera();
	cout << "\t--------------------------------------------------------------------------" << " \n\n";
	
}

void Curso::crearLista(Cola *cola){
	
	if ( !listaAsignados->estaVacia() ){
		
		Nodo *temp = listaAsignados->getInicio();
	
		while ( temp ){
			
			cola->encolar( new Estudiante( temp->getEstudiante() ) );
			temp = temp->getSiguiente();
		}
		
	}
	
	if ( !listaEspera->estaVacia() ){
		
		Nodo *temp = listaEspera->getInicio();
		
		while ( temp ){
			
			cola->encolar( new Estudiante( temp->getEstudiante() ) );
			temp = temp->getSiguiente();
			
		}
		
	}
	
}

Curso::~Curso(){
	;
}
