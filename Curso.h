#ifndef CURSO
#define CURSO

#include "Cola.h"
#include "Lista.h"

using namespace std;

/*

		Clase que representa un curso que se oferta durante el proceso de inscripción.

*/

class Curso{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		string nombre;												// Nombre
		int id;														// ID que representa a la materia
		int cupos;													// Cantidad de cupos disponibles para la materia
		int prioridad;												// Número que representa el tipo de prioridad que tendrá la materia durante el proceso de inscripción
		Cola *listaAsignados;										// Cola donde ingresarán los estudiantes asignados a la materia 
		Cola *listaEspera;											// Cola donde ingresarán los estudiantes en espera a la materia
		Cola *candidatos;											// Cola donde ingresarán los candidatos a la materia
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
		
		Curso();													// Constructor sin parámetros -> Crea un curso sin información detallada
		Curso(string nombre, int id, int cupos, int prioridad);		// Constructor con parámetros -> Crea un curso con su ID, cantidad de cupos y tipo de prioridad
		
		/* ----- Setters ----- */
		
		void setID(int id);
		void setCupos(int cupos);
		void setPrioridad(int prioridad);
		
		/* ----- Getters ----- */
		
		string getNombre();
		int getID();
		int getInfo();
		int getEstudiantesInscritos();
		int getEstudiantesSinCupo();
		
		/* ----- Procedimientos ----- */
		
		void generarListaAsignados();								// Genera la lista de estudiantes asignados para cada materia, según la cantidad de cupos disponibles
																	// En caso de que se acaben los cupos y todavía hayan estudiantes candidatos, pasarán a la lista de espera
		
		void asignarMaterias();										// Recorre las colas listaAsignados y listaEspera, y actualiza el estado de la materia en el listado del estudiante
		
		void ingresarCandidato(Estudiante *estudiante);				// Ingresa a un candidato a la materia a la cola de candidatos
		
		void mostrarInfo();											// Imprime la información general de cada curso (ID y nombre)
		
		void mostrarDetalles();										// Imprime los detalles de cada curso (cantidad de cupos y tipo de prioridad)
		
		void mostrarListaAsignados();								// Imprime la lista de estudiantes asignados para el curso
		
		void mostrarListaEspera();									// Imprime la lista de estudiantes que quedaron en espera para el curso
		
		void mostrarListaCandidatos();								// Imprime la lista de candidatos para el curso
		
		void mostrarResultados();									// Imprime los resultados del proceso de inscripcion de la materia
																	// (Nombre del curso, detalles, lista de asignados y lista en espera)

		void crearLista(Cola *cola);								// Une en una nueva cola los estudiantes asignados y lista de espera,
																	// paso previo para realizar una intersección de los estudiantes en la cola
		
		/* ----- Destructor ----- */
		
		~Curso();													// Destructor
	
};

#endif
