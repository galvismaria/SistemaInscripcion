#ifndef CURSO
#define CURSO

#include "Cola.h"

using namespace std;

class Curso{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		int id;
		int cupos;
		int prioridad;
		Cola *listaAsignados;
		Cola *listaEspera;
		Cola *candidatos;
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
		
		Curso();
		Curso(int id, int cupos, int prioridad);
		
		/* ----- Setters ----- */
		
		;
		
		/* ----- Getters ----- */
		
		int getID();
		bool hayCandidatos();
		bool hayAsignados();
		
		/* ----- Procedimientos ----- */
		
		void generarListaAsignados();
		void asignarMaterias();
		void ingresarCandidato(Estudiante *estudiante);
		string listaMaterias( int id );
		void mostrarInfo();
		void mostrarListaAsignados();
		void mostrarListaEspera();
		void mostrarListaCandidatos();
		
		/* ----- Destructor ----- */
		
		~Curso();
	
};

#endif
