#ifndef LISTA
#define LISTA

#include "Curso.h"

using namespace std;

class Lista{
	
    private:
    	
    	/* ----- ATRIBUTOS ----- */
    	
    	class Nodo{
    		
    		public:
    			
    			Curso *info;
    			Nodo *siguiente;
    		
		};
    	
        Nodo* principio;
        Nodo* actual;

    public:
    	
    	/* ----- M�TODOS ----- */
		
		/* ----- Constructores ----- */
    	
        Lista();
        
        /* ----- Procedimientos ----- */
        
        void insertar(Curso *info);
        Curso* valorActual();
        bool listaVacia();
        bool haySiguiente();
        bool hayActual();
        void siguiente();
        void primero();
        void ultimo();        
        void imprimir();
        void imprimirResultadoID(int id);
        
        /* ----- Destructor ----- */
        
        ~Lista();
        
};

#endif
