#ifndef INSCRIPCION
#define INSCRIPCION

#include "Cola.h"
#include "Lista.h"

using namespace std;

/*
	
		Clase que implementa el proceso de inscripciï¿½n.
	
*/

class Inscripcion{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Lista<Estudiante> *estudiantes;			// Lista de estudiantes que participarï¿½n en el proceso de inscripciï¿½n
		Lista<Curso> *cursos;					// Lista de cursos ofertados durante el proceso de inscripciï¿½n
		fstream archivo;						// Atributo para manejar la lectura/escrito de archivos de texto
		ofstream guardar;                        //Atributi para manejar la lectura/escrito de archivos de texto
		
	public:
		
		/* ----- Mï¿½TODOS ----- */
		
		/* ----- Constructores ----- */
		
		Inscripcion();							// Constructor sin parï¿½metros -> Inicia el proceso de inscripciï¿½n
		
		/* ----- Procedimientos ----- */
		
		void cargarCursos();													// Lee un archivo de texto con la informaciï¿½n referente a los cursos
																				// y los aï¿½ade a la lista de cursos ofertados
																				
		void cargarEstudiantes();												// Lee un archivo de texto con la informaciï¿½n referente a los estudiantes
																				// y los aï¿½ade a la lista de estudiantes que participarï¿½n en las inscripciones
																				
		void cargarInscripciones();												// Lee un archivo de texto con la informaciï¿½n de las materias que cada estudiante quiere inscribir
																				// y actualiza el listado de estudiantes aï¿½adiendo estas materias 
																				
		void cargarMateriasEstudiante( int cedula, int materias[], int n );		// Funciï¿½n que recorre la lista de estudiantes y aï¿½ade las materias que 
																				// cada estudiante quiere inscribir
		
		void ingresarEstudiantes();												// Función que permite registrar estudiantes nuevos para el proceso de inscripción
		
		void ingresarEstudiantes(Estudiante *estudiante);						// Ingresa un estudiante al listado de estudiantes
		
		void ingresarCurso(Curso *curso);										// Ingresa un curso al listado de cursos
		
		void asignarCandidatos();												// Asigna los candidatos para cada materia,
																				// segï¿½n las materias que cada estudiante quiere inscribir
		
		void inscribirEstudiantes();											// Recorre la lista de cursos y llama a la funciï¿½n que genera
																				// las listas de estudiantes asignados y en lista de espera
		
		void interseccionEstudiantes();											// Una vez realizado el proceso de inscripciï¿½n, se usa esta funciï¿½n
																				// para recorrer las colas de asignados y en espera de cada curso
																				// y actualizar la lista de estudiantes con los resultados de las inscripciones.
																				// Es decir, que el listado de materias de cada estudiante se actualiza
																				// con el estado de inscrito o en espera, y el lugar que ocupa en la cola respectiva
		
		void procesoInscripcion();												// Funciï¿½n que llama a las funciones para llevar a cabo las inscripciones
		
		void listaCursos();														// Muestra la lista de cursos ofertados, y recibe como entrada la ID de un curso
																				// Segï¿½n esta entrada, se muestran los resultados para la materia indicada
																				
		void buscarEstudiante();												// Recibe como entrada la cedula de un estudiante y muestra
																				// el estado de su inscripciï¿½n
																				
		void contarSinCupo();													// Muestra los estudiantes sin cupo para cada materia y global
		
		void registrarDatos();
		
		void menuPrincipal();													// Muestra el menï¿½ principal del programa
		
		void salir();															// Finaliza el programa
		
		/* ----- Destructor ----- */
		
		~Inscripcion();															// Destructor
	
};

#endif
