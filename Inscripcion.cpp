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
        string nombre;
        
        while( !archivo.eof() ){
        	
            archivo >> nombre >> id >> cupos >> prioridad;
    
            cursos->insertar( new Curso( nombre, id, cupos, prioridad ) );
            
        }
        
        archivo.close();
        
    } else {
    	
        cout<< "No se encontro el archivo."<< endl;
    }
    
}

void Inscripcion::cargarEstudiantes(){
	
	archivo.open("ListaEstudiantes.txt", ios::in);
	
    if ( archivo.is_open() ){
    	
		string nombre;
		string apellido;
		string carrera;
		int cedula, indice, nivel, creditos;
		
        while ( !archivo.eof() ){
        	
            archivo >> nombre >> apellido >> cedula >> carrera >> indice >> nivel >> creditos;
            
            string nombreCompleto = nombre + " " + apellido;
				
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
	string nombre;
	string apellido;
	string carrera;
	int materias[MAX_MATERIAS];
	int temp;
	bool flag = false;
	int opcion;
	
   	cout<<"\tPrimer nombre: ";
	cin >>nombre;
	
	cout<<"\tPrimer apellido: ";
	cin >>apellido;
	
	cout<<"\tCedula: ";
	cin >>cedula;
	
	cout<<"\t(reemplazar espacios por '-')\n";
	cout<<"\tCarrera: ";
	cin >>carrera;
	
	cout<<"\tIndice academico: ";
	
	while ( !flag ) {
			
		cin >> indice;
			
		if ( (indice >= 0) && (indice <= 10) ){
			
			flag = true;
			
		}
				
		else{
			
			cout << "\n\tValor invalido, intente de nuevo: ";
			cin.clear();
			cin.ignore(200, '\n');
				
		}
	}
	
	flag = false;
	
	cout<<"\tNivel: ";
	
	while ( !flag ) {
			
		cin >>nivel;
			
		if ( (nivel >= 0) && (nivel <= 9) ){
			
			flag = true;
			
		}
				
		else{
			
			cout << "\n\tValor invalido, intente de nuevo: ";
			cin.clear();
			cin.ignore(200, '\n');
				
		}
	}
	
	flag = false;

	cout<<"\tCreditos aprobados: ";
	
	while ( !flag ) {
			
		cin >>numero_credito;
			
		if ( (numero_credito >= 0) && (numero_credito <= 175) ){
			
			flag = true;
			
		}
				
		else{
			
			cout << "\n\tValor invalido, intente de nuevo: ";
			cin.clear();
			cin.ignore(200, '\n');
				
		}
	}
	
	guardar<<"\n"<<nombre<<" "<<apellido<<" "<<cedula<<" "<< carrera<<" "<<indice<<" "<<nivel<<" "<<numero_credito;
	guardar.close();
	
	system("cls");
	cout << "\n\n";
	
	guardar.open("ListaInscribir.txt", ios::app);
	
	cursos->imprimir();
	
	for ( int i = 0 ; i < MAX_MATERIAS ; i++ ){
		
		materias[i] = 0;
		
	}
		
	cout << "\tIngrese el ID de la materia que desea inscribir.\n";
	cout << "\tPuede registrar un maximo de 10 materias.\n";
	cout <<	"\t(-1 para terminar)\n";
	
	Curso *aux;
	
	
	for ( int i = 0 ; i < MAX_MATERIAS ; i++ ){
		
		cout <<"\t";
		cin >> temp;
		
		if ( temp == -1 ){
			
			break;
			
		}
		
		else{
			
			aux = cursos->buscar( temp );
			
			if ( aux ){
				
				materias[i] = temp;
				
			}
			
			else{
				
				cout <<	"\tEl ID ingresado no corresponde a ninguna materia\n\tIntentelo nuevamente\n";
				cin.clear();
				cin.ignore(200, '\n');
				i--;
				
			}
			
		}
		
	}

	guardar << "\n" << cedula << " " << materias[0] << " " << materias[1] << " " << materias[2] << " " << materias[3] << " " << materias[4] << " " << materias[5] << " " << materias[6] << " " << materias[7] << " " << materias[8] << " " << materias[9];
	
	guardar.close();
	
	system("cls");

}

void Inscripcion::ingresarMaterias(){
	
	system("cls");
	cout << "\n\n";
	
	guardar.open("ListaMaterias.txt", ios::app);

	int id, cupos, prioridad;
	string nombre;

   	cout<<"\tNombre (reemplazar espacios por '-'): ";
	cin >>nombre;
	
	cout<<"\tID: ";
	cin >>id;
	
	cout<<"\tCupos: ";
	cin >>cupos;
	
	cout<<"\tTipo de prioridad:\n";
	cout<<"\t\t(1) Indice academico, nivel actual\n";
	cout<<"\t\t(2) Nivel actual, indice academico\n";
	cout<<"\t\t(3) Creditos aprobados, indice academico\n\t";
	cin >>prioridad;
	
	guardar<<"\n"<<nombre<<" "<<id<<" "<<cupos<<" "<< prioridad;
	guardar.close();
	
	system("cls");
	cout << "\n\n";

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

string Inscripcion::nombreCurso( int id ){
	
	Curso *temp = cursos->buscar( id );
	string nombre = "\0";
	
	if ( temp ){
		
		nombre = temp->getNombre();
		
		replace( nombre.begin(), nombre.end(), '-', ' ');
		
	}
	
	return nombre;
	
}

void Inscripcion::imprimirListaCursos(){
	
	cursos->primero();
	
	while ( cursos->hayActual() ){
		
		cout << "\t(ID: " << cursos->valorActual()->getID() << ") " << nombreCurso( cursos->valorActual()->getID() ) << " \n";
		cursos->siguiente();
		
	}
	
}

void Inscripcion::imprimirDetalleCurso( int id ){
	
	Curso *temp = cursos->buscar(id);
	
	if ( temp ){
		
		cout << "\t\t* * * " << nombreCurso( temp->getID() ) << " * * *" << " \n\n";
		temp->mostrarDetalles();
		temp->mostrarResultados();
		
	}
	
}

void Inscripcion::imprimirMateriasEstudiante( int cedula ){
	
	Estudiante *temp = estudiantes->buscar(cedula);
	Curso *aux;
	int materias[MAX_MATERIAS];
	
	if ( temp ){	
		
		temp->obtenerMaterias(materias);
		
		cout << "\n\t--------------------------------------------" << " \n\n";
	
		for ( int i = 0 ; i < MAX_MATERIAS ; i++ ){
		
			if ( materias[i] != 0 ){
				
				aux = cursos->buscar( materias[i] );
				
				if ( aux ){
					
					cout << "\t\t" << nombreCurso( materias[i] ) << "\n\n";
				
					temp->mostrarDetalleMateria( materias[i] );
				
					cout << "\n\n";
				
					cout << "\t--------------------------------------------" << " \n\n";
					
				}
				
				
			
			}
		
		}
	
		
		
	}
	
	
}
	
void Inscripcion::procesoInscripcion(){
	
	estudiantes = new Lista<Estudiante>;
	cursos = new Lista<Curso>;
	
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
		imprimirListaCursos();
		
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
				imprimirDetalleCurso(opcion);
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
				imprimirMateriasEstudiante(opcion);
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
		
		cout << "\t" << nombreCurso( cursos->valorActual()->getID() );
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
	
		cout << "\n\n\t-------------------------------------------" << " \n\n\t\t";	
	
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
				ingresarMaterias();
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
		
		delete estudiantes;
		delete cursos;
		
	}
		
}

void Inscripcion::salir(){
	
	exit(0);
	
}

Inscripcion::~Inscripcion(){
	
	delete estudiantes;
	delete cursos;
	
}
