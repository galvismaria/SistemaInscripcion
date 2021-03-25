#ifndef LISTA
#define LISTA

#include "Curso.h"

using namespace std;

class Lista{
	
    private:
    	
    	/* ----- ATRIBUTOS ----- */
    	
    	class Nodo{
    		
    		public:
    			
    			Curso *curso;
    			Nodo *siguiente;
    		
		};
    	
        Nodo* principio;
        Nodo* actual;

    public:
    	
    	/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
    	
        Lista();
        
        /* ----- Procedimientos ----- */
        
        void insertar(Curso *curso);
        Curso* valorActual();
        bool listaVacia();
        bool haySiguiente();
        bool hayActual();
        void siguiente();
        void primero();
        void ultimo();        
        void mostrar();
        
        /* ----- Destructor ----- */
        
        ~Lista();
        
};

#endif
