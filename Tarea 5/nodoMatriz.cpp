#include<iostream>
#include<string>

using namespace std;

class nodoMatriz{
    public:

    nodoMatriz *siguiente;
    nodoMatriz *abajo;
    string dia;
    string actividad;
    int hora;
    int index;

    nodoMatriz(int hora,string dia,string actividad){
        this->siguiente=NULL;
        this->abajo=NULL;
        this->dia=dia;
        this->hora=hora;
        this->actividad=actividad;
        this->index=myIndex(dia);
        
    }

    nodoMatriz(){

    }



    int myIndex(string dia){
        int index;
        if(dia=="lunes"){
            index=1;
        }else if(dia=="martes"){
            index=2;
        }else if(dia=="miercoles"){
            index=3;
        }else if(dia=="jueves"){
            index=4;
        }else if(dia=="viernes"){
            index=5;
        }else if(dia=="sabado"){
            index=6;
        }else if(dia=="domingo"){
            index=7;
        }else{
            index=0;
        }

        return index;

    }

};