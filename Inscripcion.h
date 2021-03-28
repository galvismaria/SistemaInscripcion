#ifndef INSCRIPCION
#define INSCRIPCION

#include "Cola.h"
#include "Lista.h"

using namespace std;

/*
	
		Clase que implementa el proceso de inscripción.
	
*/

class Inscripcion{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Lista<Estudiante> *estudiantes;			// Lista de estudiantes que participarán en el proceso de inscripción
		Lista<Curso> *cursos;					// Lista de cursos ofertados durante el proceso de inscripción
		fstream archivo;						// Atributo para manejar la lectura/escrito de archivos de texto
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
		
		Inscripcion();							// Constructor sin parámetros -> Inicia el proceso de inscripción
		
		/* ----- Procedimientos ----- */
		
		void cargarCursos();													// Lee un archivo de texto con la información referente a los cursos
																				// y los añade a la lista de cursos ofertados
																				
		void cargarEstudiantes();												// Lee un archivo de texto con la información referente a los estudiantes
																				// y los añade a la lista de estudiantes que participarán en las inscripciones
																				
		void cargarInscripciones();												// Lee un archivo de texto con la información de las materias que cada estudiante quiere inscribir
																				// y actualiza el listado de estudiantes añadiendo estas materias 
																				
		void cargarMateriasEstudiante( int cedula, int materias[], int n );		// Función que recorre la lista de estudiantes y añade las materias que 
																				// cada estudiante quiere inscribir
		
		void ingresarEstudiantes(Estudiante *estudiante);						// Ingresa un estudiante al listado de estudiantes
		
		void ingresarCurso(Curso *curso);										// Ingresa un curso al listado de cursos
		
		void asignarCandidatos();												// Asigna los candidatos para cada materia,
																				// según las materias que cada estudiante quiere inscribir
		
		void inscribirEstudiantes();											// Recorre la lista de cursos y llama a la función que genera
																				// las listas de estudiantes asignados y en lista de espera
		
		void interseccionEstudiantes();											// Una vez realizado el proceso de inscripción, se usa esta función
																				// para recorrer las colas de asignados y en espera de cada curso
																				// y actualizar la lista de estudiantes con los resultados de las inscripciones.
																				// Es decir, que el listado de materias de cada estudiante se actualiza
																				// con el estado de inscrito o en espera, y el lugar que ocupa en la cola respectiva
		
		void procesoInscripcion();												// Función que llama a las funciones para llevar a cabo las inscripciones
		
		void listaCursos();														// Muestra la lista de cursos ofertados, y recibe como entrada la ID de un curso
																				// Según esta entrada, se muestran los resultados para la materia indicada
																				
		void buscarEstudiante();												// Recibe como entrada la cedula de un estudiante y muestra
																				// el estado de su inscripción
																				
		void contarSinCupo();													// Muestra los estudiantes sin cupo para cada materia y global
		
		void menuPrincipal();													// Muestra el menú principal del programa
		
		void salir();															// Finaliza el programa
		
		/* ----- Destructor ----- */
		
		~Inscripcion();															// Destructor
	
};

#endif
