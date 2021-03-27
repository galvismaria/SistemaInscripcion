#ifndef LISTA
#define LISTA

#include "Curso.h"

using namespace std;

template <typename T>
class Lista{
	
    private:
    	
    	/* ----- ATRIBUTOS ----- */
    	
    	class Nodo{
    		
    		public:
    			
    			T *info;
    			Nodo *siguiente;
    		
		};
    	
        Nodo* principio;
        Nodo* actual;

    public:
    	
    	/* ----- M�TODOS ----- */
		
		/* ----- Constructores ----- */
    	
        Lista();
        
        /* ----- Procedimientos ----- */
        
        void insertar(T *info);
        T* valorActual();
        bool listaVacia();
        bool haySiguiente();
        bool hayActual();
        void siguiente();
        void primero();
        void ultimo();
		void imprimir();
		T* buscar(int info);       
        
        /* ----- Destructor ----- */
        
        ~Lista();
        
};

#endif
