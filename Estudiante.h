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
		bool inscrito;
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
		void setEstado(bool inscrito);
		void setNMaterias(int nMaterias);
		void setMateria(int id, bool asignado, int lugar);
		string getNombre();
		
		/* ----- Getters ----- */
		
		float getIndice();
		int getNivel();
		int getCreditos();
		int getNMaterias();
		bool estaInscrito();
		
		/* ----- Procedimientos ----- */
		
		bool tienePrioridad(Estudiante *estudiante, int caso);
		void obtenerMaterias(int arr[]);
		void mostrarEstatus();
		void mostrarMaterias();
		
		/* ----- Destructor ----- */
		
		~Estudiante();
		
	
};

#endif
