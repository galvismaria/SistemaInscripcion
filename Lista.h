#ifndef LISTA
#define LISTA

#include "Curso.h"
#include "Estudiante.h"

using namespace std;

/*

		Clase template que implementa una Lista simplemente enlazada.
		Se implementa como clase template para que la lista pueda usarse para las clases Estudiante y Curso.

*/

template <typename T>
class Lista{
	
    private:
    	
    	/* ----- ATRIBUTOS ----- */
    	
    	class Nodo{						// Clase interna del nodo de la lista
    		
    		public:
    			
    			T *info;				// Dato que se almacena en la lista
    			Nodo *siguiente;		// Apuntador al siguiente elemento
    		
		};
    	
        Nodo* principio;				// Nodo que apunta al principio de la lista
        Nodo* actual;					// Nodo que se mueve por la lista

    public:
    	
    	/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
    	
        Lista();						// Constructor sin parámetros -> Crea una lista vacía
        
        /* ----- Procedimientos ----- */
        
        void insertar(T *info);			// Inserta un elemento en la lista
        
        T* valorActual();				// Retorna el elemento almacenado en el nodo actual de la lista
        
        bool listaVacia();				// Retorna 'true' si la lista está vacía, y 'false' en caso contrario
        
        bool haySiguiente();			// Retorna 'true' si el siguiente nodo es válido, y 'false' en caso contrario
        
        bool hayActual();				// Retorna 'true' si el nodo actual es válido, y 'false' en caso contrario
        
        void siguiente();				// Avanza al siguiente nodo de la lista
        
        void primero();					// Se ubica en el primer nodo de la lista
        
        void ultimo();					// Se ubica al final de la lista
        
		void imprimir();				// Imprime la información guardada en el nodo
		
		T* buscar(int info);       		// Busca un nodo según el dato que se pase como parámetro
        
        /* ----- Destructor ----- */
        
        ~Lista();
        
};

#endif
