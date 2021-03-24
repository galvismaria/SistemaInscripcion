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
        Curso *getPrincipio();
        Curso *sacarNodo();
        Curso* ValorActual();
        bool listaVacia();
        bool haySiguiente();
        void siguiente();
        void primero();
        void ultimo();        
        void Mostrar();
        
};

#endif
