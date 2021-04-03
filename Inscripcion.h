#ifndef INSCRIPCION
#define INSCRIPCION

#include "Cola.h"
#include "Lista.h"

using namespace std;

/*
	
		Clase que implementa el proceso de inscripcion.
	
*/

class Inscripcion{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Lista<Estudiante> *estudiantes;			// Lista de estudiantes que participaran en el proceso de inscripcion
		Lista<Curso> *cursos;					// Lista de cursos ofertados durante el proceso de inscripcion
		fstream archivo;						// Atributo para manejar la lectura de archivos de texto
		ofstream guardar;                       // Atributo para manejar la escritura de archivos de texto
		
	public:
		
		/* ----- METODOS ----- */
		
		/* ----- Constructores ----- */
		
		Inscripcion();							// Constructor sin parametros -> Inicia el proceso de inscripcion
		
		/* ----- Procedimientos ----- */
		
		void cargarCursos();													// Lee un archivo de texto con la informacion referente a los cursos
																				// y los añade a la lista de cursos ofertados
																				
		/* El formato del archivo de cursos es el siguiente: */
		/* Nombre-de-la-Materia   ID		Cupos	Prioridad   */
																				
		void cargarEstudiantes();												// Lee un archivo de texto con la informacion referente a los estudiantes
																				// y los añade a la lista de estudiantes que participaron en las inscripciones
		
		/* El formato del archivo de estudiantes es el siguiente: */
		/* Cedula	Nombre-del-Estudiante	Nombre-de-la-Carrera	Indice	Nivel	Creditos  */
																				
		void cargarInscripciones();												// Lee un archivo de texto con la informacion de las materias que cada estudiante quiere inscribir
																				// y actualiza el listado de estudiantes añadiendo estas materias 
		
		/* El formato del archivo de inscripciones es el siguiente: */
		/* Cedula	ID1		ID2		ID3		ID4	*/
		/* En caso de lugares en blanco, se debe colocar 0 como ID*/
																				
		void cargarMateriasEstudiante(int cedula, int materias[], int n);		// Funcion que recorre la lista de estudiantes y añade las materias que 
																				// cada estudiante quiere inscribir
		
		void ingresarEstudiantes();												// Función que permite registrar estudiantes nuevos para el proceso de inscripción
		
		void ingresarMaterias();												// Función que permite registrar cursos nuevos para el proceso de inscripción
		
		void ingresarEstudiantes(Estudiante *estudiante);						// Ingresa un estudiante al listado de estudiantes
		
		void ingresarCurso(Curso *curso);										// Ingresa un curso al listado de cursos
		
		void asignarCandidatos();												// Asigna los candidatos para cada materia,
																				// segun las materias que cada estudiante quiere inscribir
		
		void inscribirEstudiantes();											// Recorre la lista de cursos y llama a la funcion que genera
																				// las listas de estudiantes asignados y en lista de espera
		
		void interseccionEstudiantes();											// Una vez realizado el proceso de inscripcion, se usa esta funcion
																				// para recorrer las colas de asignados y en espera de cada curso
																				// y actualizar la lista de estudiantes con los resultados de las inscripciones.
																				// Es decir, que el listado de materias de cada estudiante se actualiza
																				// con el estado de inscrito o en espera, y el lugar que ocupa en la cola respectiva
		
		string nombreCurso(int id);												// Devuelve el nombre del curso según el ID que se indique
		
		void imprimirListaCursos();												// Imprime la lista de cursos
		
		void imprimirDetalleCurso(int id);										// Imprime los detalles del curso que se especifique
		
		void imprimirMateriasEstudiante(int cedula);							// Imprime ls detalles del estudiante que se especifique
		
		void procesoInscripcion();												// Funcion que llama a las funciones para llevar a cabo las inscripciones
		
		void listaCursos();														// Muestra la lista de cursos ofertados, y recibe como entrada la ID de un curso
																				// Segun esta entrada, se muestran los resultados para la materia indicada
																				
		void buscarEstudiante();												// Recibe como entrada la cedula de un estudiante y muestra
																				// el estado de su inscripcion
																				
		void contarSinCupo();													// Muestra los estudiantes sin cupo para cada materia y global
		
		void registrarDatos();
		
		void menuPrincipal();													// Muestra el menu principal del programa
		
		void salir();															// Finaliza el programa
		
		/* ----- Destructor ----- */
		
		~Inscripcion();															// Destructor
	
};

#endif
