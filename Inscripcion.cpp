#include "Inscripcion.h"

Inscripcion::Inscripcion(){
	
	estudiantes = new Lista<Estudiante>;
	cursos = new Lista<Curso>();
	
}

Lista<Estudiante>* Inscripcion::getEstudiantes(){
	
	return estudiantes;
	
}

Lista<Curso>* Inscripcion::getCursos(){
	
	return cursos;
	
}

void Inscripcion::ingresarEstudiantes( Estudiante *estudiante ){
	
	estudiantes->insertar( estudiante );
	
}

void Inscripcion::ingresarCurso( Curso *curso ){
	
	cursos->insertar( curso );
	
}


void Inscripcion::asignarCandidatos(){
	
	Estudiante *temp = new Estudiante();
	
	int materias[MAX_MATERIAS];
	
	estudiantes->primero();

	while ( !estudiantes->hayActual() ){
		
		temp = estudiantes->valorActual();
		
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
            	
            	string str1(nombre);
            	string str2(apellido);
            	string nombreCompleto = str1 + " " + str2;
				
				
				estudiantes->insertar( new Estudiante(nombreCompleto, carrera, cedula, indice, nivel, creditos ) );
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
	
	estudiantes->primero();
	
	while( estudiantes->hayActual() ){
			
		if ( estudiantes->valorActual()->getCedula() == cedula ){
				
			for ( int i = 0 ; i < n ; i++ ){
					
				estudiantes->valorActual()->setMateria( materias[i], false, 0 );
					
			}

		}
			
		estudiantes->siguiente();
			
	}
		
}
	

void Inscripcion::procesoInscripcion(){
	
	cargarCursos();
	cargarEstudiantes();
	cargarInscripciones();
	asignarCandidatos();
	inscribirEstudiantes();
	
}

void Inscripcion::listaCursos(){
	
	int opcion = 0;
	
	while ( opcion != -1 ){
		
		system("cls");
		cout << "\n\n";
		;
		
		cout << "\tIngrese el ID de la materia para visualizar los resultados del proceso de inscripcion\n";
		cout << "\t(-1 para volver)\n\t\t";
		
		cin >> opcion;
		
		system("cls");
		;
		system("pause");
		
	}
	
}

void Inscripcion::buscarEstudiante(){
	
	bool flag = false;
	string opcion;
	
	while ( !flag ){
		
		system("cls");
		cout << "\n\n";
		
		cout << "\tIngrese el nombre del estudiante para consultar su informacion\n";
		cout << "\t(Escriba 'salir' para volver)\n\t\t";
		
		cin >> opcion;
		
		if ( opcion == "salir" ){
			
			flag = true;
			
		}
		else {
			
			system("cls");
			
			system("pause");
		}
		
	}
	
}

void Inscripcion::menuPrincipal(){
	
	while (true){
		
		cout << "\n\n\n\n\t\t\t\t* * * Simulacion de Proceso de Inscripcion * * *";
	
		cout << "\n\n\t\t1. Informacion de asignaduras" <<
				"\n\n\t\t2. Informacion de estudiantes"<<
				"\n\n\t\t3. Conteo de estudiantes sin cupo\n\n" <<
				"\n\n\t\t4. Salir\n\n";
	
		bool flag = false;
		int opcion;
	
		while ( !flag ) {
			
			cin >> opcion;
			
			if ( (opcion >= 1) && (opcion <= 4) ){
			
				flag = true;
			
			}
				
			else{
			
				cout << "Error, intente de nuevo.\n";
				cin.clear();
				cin.ignore(200, '\n');
				
			}
		}
	
		procesoInscripcion();
		
		switch (opcion) {
			
			case(1):
				
				listaCursos();						
				break;
				
			case(2):
				
				buscarEstudiante();
				break;	
				
			case(3):
				;
				break;
			
			case(4):
				salir();			
				
			default:
				break;
		}
		
	}
		
}

void Inscripcion::salir(){
	
	exit(0);
	
}

Inscripcion::~Inscripcion(){
	;
}
