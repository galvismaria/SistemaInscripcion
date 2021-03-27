#ifndef ESTUDIANTE
#define ESTUDIANTE

#include "Global.h"

using namespace std;

class Estudiante{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		struct Materias{
	
			int id;
			bool asignado;
			int lugar;
		};
		
		string nombre;
		string carrera;
		int cedula;
		float indice;
		int nivel;
		int creditos;
		Materias materias[MAX_MATERIAS];
		int nMaterias;
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
		
		Estudiante();
		Estudiante(string nombre, string carrera, int cedula, float indice, int nivel, int creditos);
		Estudiante(Estudiante *estudiante);
		
		/* ----- Setters ----- */
		
		void setNombre(string nombre);
		void setCarrera(string carrera);
		void setIndice(float indice);
		void setNivel(int nivel);
		void setCreditos(int creditos);
		void setNMaterias(int nMaterias);
		void setMateria(int id, bool asignado, int lugar);
		void setMaterias(Estudiante *estudiante);
		
		/* ----- Getters ----- */
		
		string getNombre();
		int getCedula();
		float getIndice();
		int getNivel();
		int getCreditos();
		int getNMaterias();
		int getInfo();
		bool estaInscrito();
		
		/* ----- Procedimientos ----- */
		
		bool tienePrioridad(Estudiante *estudiante, int caso);
		void obtenerMaterias(int arr[]);
		void mostrarInfo();
		string listaMaterias( int id );
		void mostrarMaterias();
		
		/* ----- Destructor ----- */
		
		~Estudiante();
		
	
};

#endif
