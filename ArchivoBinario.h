#include<iostream>
#include<fstream>
#include <stdio.h>
#inlcide"Lista.h"


using namespace std;

  /*enum  Mat{ 
	Calculo_Numerico , Arquitectira_del_computador ,Sistema_de_base_de_datos ,Finanzas ,Investigacion_de_operaciones , 
	Sistemas_de_operacion ,Informatica_industrial ,Innovaion_y_desarrollo ,Ingenieroa_del_software ,Lenguaje_de_compiladores 
};	*/
	
fstream archivo;
void readFile(Lista* L){
	
	int id;
    int Cupos;
    archivo.open("ListaMaterias2.txt", ios::in);
    if(archivo.is_open()){
    	int id;//ide de las materias.
    	int prio;//Prioridad .
        int Cupos;//Cupode de las materias.
        char Mat[30];//Vector de caracteres para leer las materias.
        while(!archivo.eof()){
            archivo>>Mat>>id>>Cupos>>prio;
            if (!archivo.eof()){
            cout<<"Materia:  "<<Mat<<" \t id: "<<id<< " - Cupos: "<<Cupos<<" - Prioridad: "<<prio<<endl;
            
            } 
        }
        archivo.close();
    }else{
        cout<< "No se encontro el archivo."<< endl;
    }
}
void Materias(int id){
/*	
 Mat M = Calculo_Numerico;
    for(int i = 0; i < id; i++){
    	
    	switch(i){
    	case 	Calculo_Numerico: cout<<"Calculo Numerico\n"; break;
    	case 	Arquitectira_del_computador: cout<<"Arquitectira del computador\n"; break;
    	case 	Sistema_de_base_de_datos: cout<<"Sistema de base de datos\n"; break;
    	case 	Finanzas: cout<<"Finanzas\n"; break;
    	case 	Investigacion_de_operaciones : cout<<"Investigacion de operaciones\n"; break;
    	case 	Sistemas_de_operacion: cout<<"Sistemas de operacion\n"; break;
    	case 	Informatica_industrial: cout<<"Informatica industrial\n"; break;
    	case 	Innovaion_y_desarrollo: cout<<"Innovaion y desarrollo\n"; break;
    	case 	Ingenieroa_del_software: cout<<"Ingenieroa del software\n"; break;
    	case 	Lenguaje_de_compiladores: cout<<"Lenguaje de compiladores\n"; break;
		}
	}
}*/

int main(){
    
    /*int id = 10;
    Materias(id);*/
   
    cout<<endl;
     readFile();
    return 0;
}

