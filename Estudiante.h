#ifndef ESTUDIANTE
#define ESTUDIANTE

#include <string>
#include <iostream>

using namespace std;

class Estudiante{
	
	private:
		
		string nombre;
		string carrera;
		int cedula;
		float indice;
		int nivel;
		int creditos;
		bool estado;
		
	public:
		
		Estudiante();
		~Estudiante();
		Estudiante(string nombre, string carrera, int cedula, float indice, int nivel, int creditos);
		void setNombre(string nombre);
		void setCarrera(string carrera);
		void setIndice(float indice);
		void setNivel(int nivel);
		void setCreditos(int creditos);
		void setEstado(bool estado);
		string getNombre();
		float getIndice();
		int getNivel();
		int getCreditos();
		bool operator <(const Estudiante &estudiante);
		bool tienePrioridad(Estudiante *estudiante, int caso);
		
	
};

#endif
