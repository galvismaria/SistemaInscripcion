#ifndef NODO
#define NODO

class Nodo{
	
	private:
		
		Estudiante *estudiante;
		Nodo *siguiente;
		int posicion;
		int prioridad;
		
	public:
		
		Nodo();
		~Nodo();
		Nodo(Estudiante *estudiante, Nodo *siguiente, int posicion);
		Nodo(Estudiante *estudiante, Nodo *siguiente);
		void setEstudiante(Estudiante *estudiante);
		void setSiguiente(Nodo *siguiente);
		void setPosicion(int posicion);
		void setPrioridad(int prioridad);
	
}

#endif
