#include "Inscripcion.h"

Inscripcion::Inscripcion(){
	
	estudiantes = new Cola();
	cursos = new Lista();
	
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
		
		cursos->valorActual()->mostrarListaCandidatos();
		cursos->valorActual()->generarListaAsignados();
		cursos->valorActual()->mostrarListaAsignados();

		
		cursos->siguiente();
		
	}
	
	cursos->mostrar();
	
}

<<<<<<< HEAD
void Inscripcion::cargarCursos(){
    
    archivo.open("ListaMaterias.txt", ios::in);
    
    if ( archivo.is_open() ){
    	
    	int id;
    	int prioridad;
        int cupos;
        char Mat[30];
        
        while( !archivo.eof() ){
        	
            archivo >> Mat >> id >> cupos >> prioridad;
            
=======
void Inscripcion::readList(Lista *ListaM){

    archivo.open("ListaMaterias2.txt", ios::in);
    if(archivo.is_open()){
    	int id;//ide de las materias.
    	int prio;//Prioridad .
        int Cupos;//Cupode de las materias.
        char Mat[30];//Vector de caracteres para leer las materias.
        while(!archivo.eof()){
            archivo>>Mat>>id>>Cupos>>prio;
>>>>>>> 44491220eba8445c6b9f4a9718f5f3cdc2b175ab
            if (!archivo.eof()){
            	
            	cout << "Materia:  " << Mat << " \t id: " << id << " - Cupos: " << cupos << " - Prioridad: " << prioridad << endl;
            	cursos->insertar( new Curso( id, cupos, prioridad ) );
            
            } 
        }
        
        archivo.close();
        
    } else {
    	
        cout<< "No se encontro el archivo."<< endl;
    }
<<<<<<< HEAD
    
}

Inscripcion::~Inscripcion(){
	;
=======

  archivo.open("ListaEstudiantes.txt", ios::in);
    if(archivo.is_open()){
		char name[10];//Vector de caracteres para leer los nombre.
		char surname[10];//Vector de caracteres para leer apellido.
		char carrer[12];//carrera del estudiante
		int cedula, Index, Level, Credits; //cedula, indice, nivel, creditos del estudiante
        while(!archivo.eof()){
            archivo>>name>>surname>>cedula>>carrer>>Index>>Level>>Credits;
            if (!archivo.eof()){
            cout<<"Nombre del estudiante:  "<<name<<" Apellido: "<<surname<< " Cédula: "<<cedula<<" Carrera: "<<carrer<<"Indice:"<<Index<<"Nivel: "<< Level<<"Créditos: "<<Credits<<endl;
            } 
        }
        archivo.close();
    }else{
        cout<< "No se encontro el archivo."<< endl;
>>>>>>> 44491220eba8445c6b9f4a9718f5f3cdc2b175ab
}
