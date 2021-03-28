#ifndef ESTUDIANTE
#define ESTUDIANTE

#include "Global.h"

/*
	
		Clase que representa a un estudiante
	
*/

using namespace std;

class Estudiante{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		struct Materias{						// Struct con la información básica de una materia							
		
			int id;								// ID de la materia
			bool asignado;						// Si tiene el valor 'true' significa que el estudiante está inscrito en la materia, y 'false' en caso contrario
			int lugar;							// Indica la posición en que quedó el estudiante, ya sea en la lista de asignados o lista de espera
		};
		
		string nombre;							// Nombre del estudiante
		string carrera;							// Carrera que cursa el estudiante
		int cedula;								// Cedula que identifica al estudiante
		float indice;							// Índice académico 
		int nivel;								// Nivel o semestre actual
		int creditos;							// Cantidad de créditos aprobados
		Materias materias[MAX_MATERIAS];		// Arreglo que almacena las materias que desea inscribir el estudiante y posteriormente se actualiza con los resultados obtenidos
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
		
		Estudiante();																					// Constructor sin parámetros -> Crea un estudiante sin información detallada
		Estudiante(string nombre, string carrera, int cedula, float indice, int nivel, int creditos);	// Constructor con parámetros -> Crea un estudiante con un nombre, carrera, cédula, nivel, nivel y créditos
		Estudiante(Estudiante *estudiante);																// Constructor con parámetros -> Crea un estudiante en base a otro estudiante,
																										// es decir que crea una copia del mismo estudiante
		
		/* ----- Setters ----- */
		
		void setNombre(string nombre);
		void setCarrera(string carrera);
		void setIndice(float indice);
		void setNivel(int nivel);
		void setCreditos(int creditos);
		void setMateria(int id, bool asignado, int lugar);			// Añade una materia al listado de materias del estudiante, o sobreescribe su información si la materia ya está en el listado
		void setMaterias(Estudiante *estudiante);					// Pasa todas las materias que hay en un objeto Estudiante al actual
		
		/* ----- Getters ----- */
		
		string getNombre();
		int getCedula();
		float getIndice();
		int getNivel();
		int getCreditos();
		int getInfo();
		
		/* ----- Procedimientos ----- */
		
		bool tienePrioridad(Estudiante *estudiante, int caso);		// Función que valida si un estudiante tiene prioridad sobre el estudiante actual, según sea el caso:
																	// (1) Compara el índice de ambos estudiantes. Devuelve 'true' si el estudiante actual tiene un índice mayor,
																	// devuelve 'false' si el otro estudiante tiene un indice mayor.
																	
																	//		-> Si el índice es igual, procede a comparar los niveles.
																	//		Devuelve 'true' si el estudiante actual tiene mayor o igual nivel, y 'false' si el otro estudiante tiene mayor nivel
																	
																	// (2) Compara el nivel de ambos estudiantes. Devuelve 'true' si el estudiante actual tiene un nivel mayor,
																	// devuelve 'false' si el otro estudiante tiene un nivel mayor.
																	
																	//		-> Si el nivel es igual, procede a comparar los indices.
																	//		Devuelve 'true' si el estudiante actual tiene mayor o igual indice, y 'false' si el otro estudiante tiene mayor indice.
																	
																	// (3) Compara los creditos aprobados de ambos estudiantes. Devuelve 'true' si el estudiante actual tiene mayor cantidad de creditos aprobados,
																	// devuelve 'false' si el otro estudiante tiene mayor cantidad de creditos aprobados.
																	
																	//		-> Si la cantidad de creditos aprobados es igual, procede a comparar los indices.
																	//		Devuelve 'true' si el estudiante actual tiene mayor o igual indice, y 'false' si el otro estudiante tiene mayor indice.
																	
		void obtenerMaterias(int arr[]);							// Ingresa en un arreglo las materias almacenadas en el estudiante
		
		void mostrarInfo();											// Imprime la información del estudiante (nombre, cedula, indice, nivel y creditos)
									
		void mostrarMaterias();										// Imprime las materias almacenadas en el estudiante,
																	// mostrando si tiene cupo y el lugar que ocupa en el listado de asignados o en espera.
		
		string listaMaterias( int id );								// Devuelve el nombre de la materia según su ID
		
		/* ----- Destructor ----- */
		
		~Estudiante();												// Destructor
		
	
};

#endif
