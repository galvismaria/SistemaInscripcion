#ifndef INSCRIPCION
#define INSCRIPCION

#include "Cola.h"
#include "Lista.h"

using namespace std;

/*
	
		Clase que implementa el proceso de inscripci�n.
	
*/

class Inscripcion{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Lista<Estudiante> *estudiantes;			// Lista de estudiantes que participar�n en el proceso de inscripci�n
		Lista<Curso> *cursos;					// Lista de cursos ofertados durante el proceso de inscripci�n
		fstream archivo;						// Atributo para manejar la lectura/escrito de archivos de texto
		ofstream Guardar;                        //Atributi para manejar la lectura/escrito de archivos de texto
		
	public:
		
		/* ----- M�TODOS ----- */
		
		/* ----- Constructores ----- */
		
		Inscripcion();							// Constructor sin par�metros -> Inicia el proceso de inscripci�n
		
		/* ----- Procedimientos ----- */
		
		void cargarCursos();													// Lee un archivo de texto con la informaci�n referente a los cursos
																				// y los a�ade a la lista de cursos ofertados
																				
		void cargarEstudiantes();												// Lee un archivo de texto con la informaci�n referente a los estudiantes
																				// y los a�ade a la lista de estudiantes que participar�n en las inscripciones
																				
		void cargarInscripciones();												// Lee un archivo de texto con la informaci�n de las materias que cada estudiante quiere inscribir
																				// y actualiza el listado de estudiantes a�adiendo estas materias 
																				
		void cargarMateriasEstudiante( int cedula, int materias[], int n );		// Funci�n que recorre la lista de estudiantes y a�ade las materias que 
																				// cada estudiante quiere inscribir
		
		void ingresarEstudiantes(Estudiante *estudiante);						// Ingresa un estudiante al listado de estudiantes
		
		void ingresarCurso(Curso *curso);										// Ingresa un curso al listado de cursos
		
		void asignarCandidatos();												// Asigna los candidatos para cada materia,
																				// seg�n las materias que cada estudiante quiere inscribir
		
		void inscribirEstudiantes();											// Recorre la lista de cursos y llama a la funci�n que genera
																				// las listas de estudiantes asignados y en lista de espera
		
		void interseccionEstudiantes();											// Una vez realizado el proceso de inscripci�n, se usa esta funci�n
																				// para recorrer las colas de asignados y en espera de cada curso
																				// y actualizar la lista de estudiantes con los resultados de las inscripciones.
																				// Es decir, que el listado de materias de cada estudiante se actualiza
																				// con el estado de inscrito o en espera, y el lugar que ocupa en la cola respectiva
		
		void procesoInscripcion();												// Funci�n que llama a las funciones para llevar a cabo las inscripciones
		
		void listaCursos();														// Muestra la lista de cursos ofertados, y recibe como entrada la ID de un curso
																				// Seg�n esta entrada, se muestran los resultados para la materia indicada
																				
		void buscarEstudiante();												// Recibe como entrada la cedula de un estudiante y muestra
																				// el estado de su inscripci�n
																				
		void contarSinCupo();													// Muestra los estudiantes sin cupo para cada materia y global
		
		void menuPrincipal();													// Muestra el men� principal del programa
		
		void salir();															// Finaliza el programa

		void IngresarEstudiantes();
		
		/* ----- Destructor ----- */
		
		~Inscripcion();															// Destructor
	
};

#endif
