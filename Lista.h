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
    			
    			int posicion;			// Lugar que ocupa el nodo en la lista
    			T *info;				// Dato que se almacena en la lista
    			Nodo *siguiente;		// Apuntador al siguiente elemento
    		
		};
    	
        Nodo* principio;				// Nodo que apunta al principio de la lista
        Nodo* actual;					// Nodo que se mueve por la lista
        int elementos;					// Cantidad de elementos que hay en la lista

    public:
    	
    	/* ----- M�TODOS ----- */
		
		/* ----- Constructores ----- */
    	
        Lista();						// Constructor sin par�metros -> Crea una lista vac�a
        
        /* ----- Procedimientos ----- */
        
        void insertar(T *info);			// Inserta un elemento en la lista
        
        T* valorActual();				// Retorna el elemento almacenado en el nodo actual de la lista
        
        int cantElementos();			// Devuelve la cantidad de elementos guardados en la lista
		
		int posicionActual();			// Devuelve la posicion que ocupa el nodo actual
        
        bool listaVacia();				// Retorna 'true' si la lista est� vac�a, y 'false' en caso contrario
        
        bool haySiguiente();			// Retorna 'true' si el siguiente nodo es v�lido, y 'false' en caso contrario
        
        bool hayActual();				// Retorna 'true' si el nodo actual es v�lido, y 'false' en caso contrario
        
        void siguiente();				// Avanza al siguiente nodo de la lista
        
        void primero();					// Se ubica en el primer nodo de la lista
        
        void ultimo();					// Se ubica al final de la lista
        
		void imprimir();				// Imprime la informaci�n guardada en el nodo
		
		void imprimirConPosiciones(); 	// Imprime la informaci�n guardada en el nodo y adicionalmente muestra el lugar que ocupa en la lista
		
		T* buscar(int info);       		// Busca un nodo seg�n el dato que se pase como par�metro
										// Si se trata de una lista de estudiantes recibe una c�dula como par�metro,
										// y si se trata de una lista de cursos recibe un ID de materia como par�metro
										
		void asignarPosiciones();		// Recorre la lista y asigna a cada nodo la posici�n que ocupa en la lista
        
        /* ----- Destructor ----- */
        
        ~Lista();
        
};

#endif
