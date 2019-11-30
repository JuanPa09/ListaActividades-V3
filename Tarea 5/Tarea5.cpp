#include <iostream>
#include "Matriz.cpp"
#include "caragaMasiva.cpp"

using namespace std;

Matriz matrix;

class Menu{
    public:
    void ingresar(){
        system("cls");
        string dia,actividad;
        int hora;
        cout<<"Ingrese el dia en minusculas:\n";
        cin>>dia;
        cout<<"Ingrese la hora en formato de 24 horas (Solo el numero entero)\n";
        cin>>hora;
        cout<<"Ingrese la actividad:\n";
        cin>>actividad;
        matrix.insertar(hora,dia,actividad);
        system("pause");
        menu();
    }

    void cargamasiva(){
        system("cls");
        cargaMasiva cm;
        string narchivo;
        cout<<"Ingrese el nombre del archivo:\n";
        cin>>narchivo;
        cm.cargar(narchivo,matrix);
        cout<<"Datos cargados correctamente ";
        system("pause");
        menu();
    }

    void impresion(){
        system("cls");
        string respuesta;
        cout<<"1. dia especifico\n";
        cout<<"2. todos los dias\n";
        cout<<"3. Regresar\n";
        cin>>respuesta;
        if (respuesta=="1")
        {
            string day;
            cout<<"Ingrese el dia\n";
            cin>>day;
            matrix.imprimirActividadesDia(day);
            system("pause");
            impresion();
        }else if(respuesta=="2"){
            matrix.imprimirActividades();
            system("pause");
            impresion();
        }else if(respuesta=="3") {
            menu();
        }else{
            impresion();
        }
        
    }


    void menu(){
        system("cls");
        string respuesta;
        cout<<"1. Ingresar actividad\n";
        cout<<"2. Imprimir actividad\n";
        cout<<"3. Carga Masiva\n";
        cout<<"4. Salir\n";
        cin>>respuesta;
        if (respuesta=="1")
        {
            ingresar();
        }else if(respuesta=="2"){
            impresion();
        }else if(respuesta=="3"){
            cargamasiva();
        }else if(respuesta=="4") {
            exit(0);
        }else{
            menu();
        }
        
    }

};








int main(){
    /*
    Matriz matrix;
    matrix.insertar(5,"sabado","Jugar");
    matrix.insertar(15,"martes","Almorzar");
    matrix.insertar(5,"miercoles","Programar");
    matrix.insertar(2,"lunes","Estudiar");
    matrix.insertar(15,"sabado","Jugar futbol");
    matrix.insertar(16,"jueves","Vacaciones");
    matrix.insertar(1,"lunes","Levantarse");
    
    //matrix.imprimirActividades();

    matrix.imprimirActividadesDia("sabado");
    */
   
   Menu menu;
   menu.menu();
}