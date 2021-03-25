#include "Inscripcion.h"

Inscripcion::Inscripcion(){
	
	estudiantes = new Cola();
	cursos = new Lista();
	
}

void Inscripcion::ingresarEstudiantes(Estudiante *estudiante){
	
	estudiantes->encolar(estudiante);
	
}

void Inscripcion::ingresarCurso(Curso *curso){
	
	cursos->insertar(curso);
	
}


void Inscripcion::asignarCandidatos(){
	
	Estudiante *temp = new Estudiante();
	
	int materias[MAX_MATERIAS];

	while ( !estudiantes->estaVacia() ){
		
		temp = estudiantes->desencolar();
		
		temp->obtenerMaterias(materias);
		
		for ( int i = 0 ; i < temp->getNMaterias() ; i++ ){
			
			cursos->primero();
			
			while ( cursos->hayActual() ){
				
				if ( materias[i] == cursos->ValorActual()->getID() ){
					
					cursos->ValorActual()->ingresarCandidato( new Estudiante(temp) );
					
				}
				
				cursos->siguiente();
			
				
			}
			
		}
		
	}
	
	
}

void Inscripcion::inscribirEstudiantes(){
	
	cursos->primero();
	
	while ( cursos->hayActual() ){
		
		cursos->ValorActual()->mostrarListaCandidatos();
		cursos->ValorActual()->generarListaAsignados();
		cursos->ValorActual()->mostrarListaAsignados();
		cursos->siguiente();
		
	}
	
}

void Inscripcion::readList(Lista *ListaM){

	int id;
    int Cupos;
    archivo.open("ListaMaterias2.txt", ios::in);
    if(archivo.is_open()){
    	int id;//ide de las materias.
    	int prio;//Prioridad .
        int Cupos;//Cupode de las materias.
        char Mat[30];//Vector de caracteres para leer las materias.
        while(!archivo.eof()){
            archivo>>Mat>>id>>Cupos>>prio;
            if (!archivo.eof()){
            cout<<"Materia:  "<<Mat<<" \t id: "<<id<< " - Cupos: "<<Cupos<<" - Prioridad: "<<prio<<endl;
            
            } 
        }
        archivo.close();
    }else{
        cout<< "No se encontro el archivo."<< endl;
    }
}
