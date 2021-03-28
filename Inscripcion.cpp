#include "Inscripcion.h"

Inscripcion::Inscripcion(){
	
	estudiantes = new Lista<Estudiante>;
	cursos = new Lista<Curso>;
	
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
    
            cursos->insertar( new Curso( id, cupos, prioridad ) );
            
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
            
            string str1(nombre);
            string str2(apellido);
            string nombreCompleto = str1 + " " + str2;
				
			estudiantes->insertar( new Estudiante ( nombreCompleto, carrera, cedula, indice, nivel, creditos ) );
			
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
            
            cargarMateriasEstudiante(cedula, materias, MAX_MATERIAS);  

        }
        
        archivo.close();
        
    } else {
    	
        cout<< "No se encontro el archivo."<< endl;
	
	}
}

void Inscripcion::ingresarEstudiantes(){
	
	system("cls");
	cout << "\n\n";
	
	guardar.open("ListaEstudiantes.txt", ios::app);

	int cedula, indice, numero_credito, nivel;
	char nombre[20];
	char apellido[20];
	char carrera[20];
	int materias[MAX_MATERIAS];
	int temp;

   	cout<<"\tNombre: ";
	cin >>nombre;
	
	cout<<"\tApellido: ";
	cin >>apellido;
	
	cout<<"\tCedula: ";
	cin >>cedula;
	
	cout<<"\tCarrera: ";
	cin >>carrera;
	
	cout<<"\tIndice academico: ";
	cin >>indice;
	
	cout<<"\tNivel: ";
	cin >>nivel;
	
	cout<<"\tCreditos aprobados: ";
	cin >>numero_credito;
	
	guardar<<"\n"<<nombre<<"  "<<apellido<<"  "<<cedula<<"  "<< carrera<<"        "<<indice<<"        "<<nivel<<"       "<<numero_credito;
	guardar.close();
	
	system("cls");
	cout << "\n\n";
	
	guardar.open("ListaInscribir.txt", ios::app);
	
	cursos->imprimir();
	
	for ( int i = 0 ; i < MAX_MATERIAS ; i++ ){
		
		materias[i] = 0;
		
	}
		
	cout << "\tIngrese el ID de la materia que desea inscribirn\n";
	cout <<	"\t(-1 para terminar)\n\t";
	
	
	for ( int i = 0 ; i < MAX_MATERIAS ; i++ ){
		
		cin >> temp;
		
		if ( temp == -1 ){
			
			break;
			
		}
		
		else{
			
			materias[i] = temp;
			
		}
		
	}

	guardar <<"\n"<< cedula <<"  " << materias[0] <<"  " << materias[1] <<"  " << materias[2] <<"  " << materias[3] <<"  " << materias[4] <<"  " << materias[5] <<"  " << materias[6] <<"  " << materias[7] <<"  " << materias[8] <<"  " << materias[9];
	
	guardar.close();
	
	system("cls");

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

	while ( estudiantes->hayActual() ){
		
		temp = estudiantes->valorActual();
		
		temp->obtenerMaterias( materias );
		
		for ( int i = 0 ; i < MAX_MATERIAS ; i++ ){
			
			cursos->primero();
			
			while ( cursos->hayActual() ){
				
				if ( materias[i] == cursos->valorActual()->getID() ){
					
					cursos->valorActual()->ingresarCandidato( new Estudiante( temp ) );
					
				}
				
				cursos->siguiente();
				
			}
			
		}
		
		estudiantes->siguiente();
		
	}
	
	
}

void Inscripcion::inscribirEstudiantes(){
	
	cursos->primero();
	
	while ( cursos->hayActual() ){
		
		cursos->valorActual()->generarListaAsignados();
		cursos->siguiente();
		
	}
	
}

void Inscripcion::interseccionEstudiantes(){
	
	cursos->primero();
	
	while ( cursos->hayActual() ){
		
		Cola *colaTemp = new Cola();
		cursos->valorActual()->crearLista ( colaTemp );
		
		while ( !colaTemp->estaVacia() ){
			
			estudiantes->primero();
			Estudiante *temp = colaTemp->desencolar();
			
			while ( estudiantes->hayActual() ){
				
				if ( temp->getCedula() == estudiantes->valorActual()->getCedula() ){
					
					estudiantes->valorActual()->setMaterias( temp );
				
				}
					
				estudiantes->siguiente();
				
		 	}
		 	
		}
		
		cursos->siguiente();		
		
	}
		
}

	
void Inscripcion::procesoInscripcion(){
	
	cargarCursos();
	cargarEstudiantes();
	cargarInscripciones();
	asignarCandidatos();
	inscribirEstudiantes();
	interseccionEstudiantes();
	
}


void Inscripcion::listaCursos(){
	
	bool flag = false;
	int opcion = 0;
	Curso *curso;
	
	while ( !flag ){
		
		system("cls");
		cout << "\n\n";
		cursos->imprimir();
		
		cout << "\tIngrese el ID de la materia para visualizar los resultados del proceso de inscripcion\n";
		cout << "\t(-1 para volver)\n\t";
		
		
		while ( true ) {
			
			cin >> opcion;
			
			if ( opcion == -1 ){
			
				flag = true;
				break;
			
			}
			
			curso = cursos->buscar(opcion);
			
			if ( curso ){
				
				system("cls");
				cout << "\n\n";
				curso->mostrarResultados();
				system("pause");
				flag = false;
				break;
				
			}
				
			else{
			
				cout << "\tEl ID ingresado no corresponde a ningun curso\n\t";
				cin.clear();
				cin.ignore(200, '\n');
				
			}
		}
		
	}
	
}

void Inscripcion::buscarEstudiante(){
	
	bool flag = false;
	int opcion = 0;
	Estudiante *estudiante;
	
	while ( !flag ){
		
		system("cls");
		cout << "\n\n";
		
		cout << "\tIngrese la cedula del estudiante para consultar su informacion\n";
		cout << "\t(-1 para volver)\n\t";
		
		
		while ( true ) {
			
			cin >> opcion;
			
			if ( opcion == -1 ){
			
				flag = true;
				break;
			
			}
			
			estudiante = estudiantes->buscar( opcion );
			
			if ( estudiante ){
				
				system("cls");
				cout << "\n\n";
				estudiante->mostrarInfo();
				estudiante->mostrarMaterias();
				system("pause");
				flag = false;
				break;
				
			}
				
			else{
			
				cout << "\tLa cedula ingresada no corresponde a ningun estudiante\n\t";
				cin.clear();
				cin.ignore(200, '\n');
				
			}
		}
		
	}
	
}

void Inscripcion::contarSinCupo(){
	
	cursos->primero();
	int n = 0;
	
	system("cls");
	cout << "\n\n";
	
	cout << "\t-------------------------------------------" << " \n\n";
	
	while ( cursos->hayActual() ){
		
		cout << "\t" << cursos->valorActual()->listaMaterias( cursos->valorActual()->getID() );
		cout << "\t\t( " << cursos->valorActual()->getEstudiantesSinCupo() << " )\n";
		n = n + cursos->valorActual()->getEstudiantesSinCupo();
		
		cursos->siguiente();
	}
	
	cout << "\n\tTotal: " << n << "\n";
	
	cout << "\t--------------------------------------------" << " \n\n";
	system("pause");
	
}

void Inscripcion::registrarDatos(){
	
	while(true){
		
		system("cls");
		cout << "\n\n";
		
		cout << "\t-------------------------------------------" << " \n\n";
	
		cout << "\n\n\n\t\t1. Registrar estudiante" <<
				"\n\n\t\t2. Registrar asignatura" <<
				"\n\n\t\t3. Regresar";
	
		cout << "\t-------------------------------------------" << " \n\n\t\t";	
	
		bool flag = false;
		int opcion;
	
		while ( !flag ) {
			
			cin >> opcion;
			
			if ( (opcion >= 1) && (opcion <= 3) ){
			
				flag = true;
			
			}
				
			else{
			
				cout << "Error, intente de nuevo.\n";
				cin.clear();
				cin.ignore(200, '\n');
				
			}
		}
	
		switch(opcion){
		
			case 1:
				
				ingresarEstudiantes();
				break;
				
			case 2:
				//ingresarMaterias();
				break;
				
			case 3:
			
				return;
				
		}
		
	}
	
}

void Inscripcion::menuPrincipal(){
	
	while (true){
		
		system("cls");
		cout << "\n\n";
	
		cout << "\t----------------------------------------------------------------------------------------------------" << " \n\n";
		
		cout << "\n\n\n\n\t\t\t\t* * * Simulacion de Proceso de Inscripcion * * *";
	
		cout << "\n\n\n\t\t1. Informacion de asignaduras" <<
				"\n\n\t\t2. Informacion de estudiantes"<<
				"\n\n\t\t3. Conteo de estudiantes sin cupo" <<
				"\n\n\t\t4. Registro de datos" <<
				"\n\n\t\t5. Salir\n\n\n\n";
				
		cout << "\t----------------------------------------------------------------------------------------------------" << " \n\n\t\t";
	
		bool flag = false;
		int opcion;
	
		while ( !flag ) {
			
			cin >> opcion;
			
			if ( (opcion >= 1) && (opcion <= 5) ){
			
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
				
				contarSinCupo();
				break;
				
			case(4):
				
				registrarDatos();
				break;
			
			case(5):
				
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
