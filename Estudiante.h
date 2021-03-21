#ifndef ESTUDIANTE
#define ESTUDIANTE

class Estudiante{
	
	private:
		
		string nombre;
		string carrera;
		int cedula;
		float indice;
		int nivel;
		int ucAprbados;
		bool estado;
		
	public:
		
		Estudiante();
		~Estudiante();
		Estudiante(string nombre, string carrera, int cedula, float indice, int nivel, int ucAprobados);
		void setNombre(string nombre);
		void setCarrera(string carrera);
		void setIndice(float indice);
		void setNivel(int nivel);
		void setCreditosAprobados(int ucAprobados);
		void setEstado(bool estado);
	
};

#endif
