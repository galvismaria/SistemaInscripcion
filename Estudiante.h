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
		
		struct Materias{						// Struct con la informaci�n b�sica de una materia							
		
			int id;								// ID de la materia
			bool asignado;						// Si tiene el valor 'true' significa que el estudiante est� inscrito en la materia, y 'false' en caso contrario
			int lugar;							// Indica la posici�n en que qued� el estudiante, ya sea en la lista de asignados o lista de espera
		};
		
		string nombre;							// Nombre del estudiante
		string carrera;							// Carrera que cursa el estudiante
		int cedula;								// Cedula que identifica al estudiante
		float indice;							// �ndice acad�mico 
		int nivel;								// Nivel o semestre actual
		int creditos;							// Cantidad de cr�ditos aprobados
		Materias materias[MAX_MATERIAS];		// Arreglo que almacena las materias que desea inscribir el estudiante y posteriormente se actualiza con los resultados obtenidos
		
	public:
		
		/* ----- M�TODOS ----- */
		
		/* ----- Constructores ----- */
		
		Estudiante();																					// Constructor sin par�metros -> Crea un estudiante sin informaci�n detallada
		Estudiante(string nombre, string carrera, int cedula, float indice, int nivel, int creditos);	// Constructor con par�metros -> Crea un estudiante con un nombre, carrera, c�dula, nivel, nivel y cr�ditos
		Estudiante(Estudiante *estudiante);																// Constructor con par�metros -> Crea un estudiante en base a otro estudiante,
																										// es decir que crea una copia del mismo estudiante
		
		/* ----- Setters ----- */
		
		void setNombre(string nombre);
		void setCarrera(string carrera);
		void setIndice(float indice);
		void setNivel(int nivel);
		void setCreditos(int creditos);
		void setMateria(int id, bool asignado, int lugar);			// A�ade una materia al listado de materias del estudiante, o sobreescribe su informaci�n si la materia ya est� en el listado
		void setMaterias(Estudiante *estudiante);					// Pasa todas las materias que hay en un objeto Estudiante al actual
		
		/* ----- Getters ----- */
		
		string getNombre();
		int getCedula();
		float getIndice();
		int getNivel();
		int getCreditos();
		int getInfo();
		
		/* ----- Procedimientos ----- */
		
		bool tienePrioridad(Estudiante *estudiante, int caso);		// Funci�n que valida si un estudiante tiene prioridad sobre el estudiante actual, seg�n sea el caso:
																	// (1) Compara el �ndice de ambos estudiantes. Devuelve 'true' si el estudiante actual tiene un �ndice mayor,
																	// devuelve 'false' si el otro estudiante tiene un indice mayor.
																	
																	//		-> Si el �ndice es igual, procede a comparar los niveles.
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
		
		void mostrarInfo();											// Imprime la informaci�n del estudiante (nombre, cedula, indice, nivel y creditos)
									
		void mostrarMaterias();										// Imprime las materias almacenadas en el estudiante,
																	// mostrando si tiene cupo y el lugar que ocupa en el listado de asignados o en espera.
		
		string listaMaterias( int id );								// Devuelve el nombre de la materia seg�n su ID
		
		/* ----- Destructor ----- */
		
		~Estudiante();												// Destructor
		
	
};

#endif
