#include "Inscripcion.h"

Inscripcion::Inscripcion(){
	
	estudiantes = new Cola();
	cursos = new Lista();
	
}

Cola* Inscripcion::getEstudiantes(){
	
	return estudiantes;
	
}

Lista* Inscripcion::getCursos(){
	
	return cursos;
	
}

void Inscripcion::ingresarEstudiantes( Estudiante *estudiante ){
	
	estudiantes->encolar( estudiante );
	
}

void Inscripcion::ingresarCurso( Curso *curso ){
	
	cursos->insertar( curso );
	
}


void Inscripcion::asignarCandidatos(){
	
	Estudiante *temp = new Estudiante();
	
	int materias[MAX_MATERIAS];

	while ( !estudiantes->estaVacia() ){
		
		temp = estudiantes->desencolar();
		
		temp->obtenerMaterias( materias );
		
		for ( int i = 0 ; i < temp->getNMaterias() ; i++ ){
			
			cursos->primero();
			
			while ( cursos->hayActual() ){
				
				if ( materias[i] == cursos->valorActual()->getID() ){
					
					cursos->valorActual()->ingresarCandidato( new Estudiante( temp ) );
					
				}
				
				cursos->siguiente();
			
				
			}
			
		}
		
	}
	
	
}

void Inscripcion::inscribirEstudiantes(){
	
	cursos->primero();
	
	while ( cursos->hayActual() ){
		
		cursos->valorActual()->generarListaAsignados();
		cursos->siguiente();
		
	}

	
}

void Inscripcion::cargarCursos(){
    
    archivo.open("ListaMaterias.txt", ios::in);
    
    if ( archivo.is_open() ){
    	
    	int id;
    	int prioridad;
        int cupos;
        char Mat[30];
        
        while( !archivo.eof() ){
        	
            archivo >> Mat >> id >> cupos >> prioridad;
            
            if (!archivo.eof()){
            	
            	//cout << "Materia:  " << Mat << " \t id: " << id << " - Cupos: " << cupos << " - Prioridad: " << prioridad << endl;
            	cursos->insertar( new Curso( id, cupos, prioridad ) );
            
            } 
        }
        
        archivo.close();
        
    } else {
    	
        cout<< "No se encontro el archivo."<< endl;
    }
    
}

void Inscripcion::cargarEstudiantes(){
	
	archivo.open("ListaEstudiantes.txt", ios::in);
	
    if ( archivo.is_open() ){
    	
		char nombre[10];
		char apellido[10];
		char carrera[12];
		int cedula, indice, nivel, creditos;
		
        while ( !archivo.eof() ){
        	
            archivo >> nombre >> apellido >> cedula >> carrera >> indice >> nivel >> creditos;
            
            if ( !archivo.eof() ){
            	
            	//cout<<"Nombre:  "<< nombre << " " << apellido << " Cedula: " << cedula << " Carrera: " << carrera << "Indice: " << indice << "Nivel: " << nivel << "Creditos: " << creditos << endl;
            	string str1(nombre);
            	string str2(apellido);
            	string nombreCompleto = str1 + " " + str2;
				
				
				estudiantes->encolar( new Estudiante(nombreCompleto, carrera, cedula, indice, nivel, creditos ) );
			} 
        }
        
        archivo.close();
        
    } else {
    	
        cout<< "No se encontro el archivo."<< endl;
	
	}
}

void Inscripcion::cargarInscripciones(){
	
	archivo.open("ListaInscribir.txt", ios::in);
	
    if ( archivo.is_open() ){
    	
		int cedula;
		int materias[MAX_MATERIAS];
		
        while ( !archivo.eof() ){
        	
            archivo >> cedula >> materias[0] >> materias[1] >> materias[2] >> materias[3] >> materias[4] >> materias[5] >> materias[6] >> materias[7] >> materias[8] >> materias[9];
            
            if ( !archivo.eof() ){
    
            	cargarMateriasEstudiante(cedula, materias, MAX_MATERIAS);
            	
			} 
        }
        
        archivo.close();
        
    } else {
    	
        cout<< "No se encontro el archivo."<< endl;
	
	}
}


void Inscripcion::cargarMateriasEstudiante( int cedula, int materias[], int n ){
	
	if ( !estudiantes->estaVacia() ){
		
		Nodo *temp = estudiantes->getInicio();
		
		while( temp ){
			
			if ( temp->getEstudiante()->getCedula() == cedula ){
				
				for ( int i = 0 ; i < n ; i++ ){
					
					temp->getEstudiante()->setMateria( materias[i], false, 0 );
					
				}

			}
			
			temp = temp->getSiguiente();
			
		}
		
	}
	
}

void Inscripcion::mostrarEstudiantes(){
	
	if ( !estudiantes->estaVacia() ){
		
		estudiantes->imprimir();
		
	}
	
}

void Inscripcion::mostrarCursos(){
	
	if ( !estudiantes->estaVacia() ){
		
		cursos->imprimir();
		
	}
	
}

void Inscripcion::mostrarCandidatos(){
	
	cursos->primero();
	
	cursos->valorActual()->mostrarListaCandidatos();
	
}

Inscripcion::~Inscripcion(){
	;
}
