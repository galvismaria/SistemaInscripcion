#ifndef LISTA
#define LISTA

#include "Curso.h"

using namespace std;

class Lista{
	
    private:
    	
    	class Nodo{
    		
    		public:
    			
    			Curso *curso;
    			Nodo *siguiente;
    		
		};
    	
        Nodo* principio;
        Nodo* actual;

    public:
        Lista();
        ~Lista();
        void insertar(Curso *curso);
        Curso* ValorActual();
        bool listaVacia();
        bool haySiguiente();
        bool hayActual();
        void siguiente();
        void primero();
        void ultimo();        
        void Mostrar();
        
};

#endif
