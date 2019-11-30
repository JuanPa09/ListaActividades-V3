#include<iostream>
#include<string>
#include"nodoMatriz.cpp"

class Matriz{
    public:
    nodoMatriz *root=NULL;

    Matriz(){
        root=new nodoMatriz(0,"root","");
    }

    auto buscarFila(int hora){//Buscar hora
        nodoMatriz *temp = root;
        while (temp!=NULL)
        {
            if(temp->hora==hora){
                return temp;
            }
            temp=temp->abajo;
        }

        return temp;        
    }


    auto buscarColumna(string dato){//Buscar Dia
    nodoMatriz *temp = root;
        while (temp!=NULL)
        {
            if(temp->dia==dato){
                return temp;
            }
            temp=temp->siguiente;
        }

        return temp;

    }


    auto insertarOrdenado_Columna(string dia){
        int miindice=myIndex(dia);
        if (dia!="" && miindice!=0)
        {
            
            nodoMatriz *day = new nodoMatriz(0,dia,"");
            if  (this->root->siguiente==NULL){
                //Insertar el dia
                this->root->siguiente=day;
                return day;
            }else{
                nodoMatriz *temp = root;
                nodoMatriz *ant = root;
                temp=temp->siguiente;
                while(temp!=NULL){
                    if(temp->index<miindice&&(temp->siguiente==NULL||temp->siguiente->index>miindice)){
                        day->siguiente=temp->siguiente;
                        temp->siguiente=day;

                        return day;
                        break;
                    }

                    if(temp->index==miindice){
                        return temp;
                        break;
                    }

                    if (temp->index>miindice)
                    {
                        day->siguiente=temp;
                        ant->siguiente=day;
                        return day;
                        break;
                    }
                    ant=temp;
                    temp=temp->siguiente;
                }

            }

        }else{
            cout<<"Compruebe los datos\n";
        }
        

    }


    auto insertarOrdenado_Fila(int hora){
        nodoMatriz *temp = root;
        nodoMatriz *ant = root;
        nodoMatriz *nuevo=new nodoMatriz(hora,"root","");
        
        if  (root->abajo!=NULL){
            temp=temp->abajo;
        
            while (temp!=NULL)
            {
                if (temp->hora<hora&&(temp->abajo==NULL||temp->abajo->hora>hora))
                {
                    
                    nuevo->abajo=temp->abajo;
                    temp->abajo=nuevo;
                    return nuevo;
                }

                if(hora<temp->hora){
                    nuevo->abajo=temp;
                    ant->abajo=nuevo;
                    return nuevo;
                }

                
                
                ant=temp;
                temp=temp->abajo; 
            }
        }else{
            root->abajo=nuevo;
            
            return nuevo;
        }
        return temp;

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

    void insertar(int hora, string dia,string actividad){
        nodoMatriz *fila = buscarFila(hora);
        nodoMatriz *columna = buscarColumna(dia);
        nodoMatriz *nuevo = new nodoMatriz(hora,dia,actividad);

        if(fila!=NULL && columna ==NULL ){
        //Existe la fila pero no la columna
            nodoMatriz *column = insertarOrdenado_Columna(dia);
            insertarActividad(fila,column,nuevo);
        }else if(fila==NULL && columna !=NULL){
        //Existe la columna pero no la fila
            nodoMatriz *row = insertarOrdenado_Fila(hora);
            insertarActividad(row,columna,nuevo);
        }else if(fila==NULL && columna == NULL){
        //No existe ninguna
            nodoMatriz *row = insertarOrdenado_Fila(hora);
            nodoMatriz *column = insertarOrdenado_Columna(dia);
            insertarActividad(row,column,nuevo);
        }else if(fila!=NULL && columna != NULL){
        //Los dos existen
            insertarActividad(fila,columna,nuevo);
        }else{
        }

    }

    void insertarActividad(nodoMatriz *fila, nodoMatriz *columna , nodoMatriz *nuevo){
        nodoMatriz *temp = columna;
        nodoMatriz *ant = columna;
        if (temp->abajo!=NULL)
        {
           
            while (temp!=NULL)
            {          
                if (temp->hora>nuevo->hora)
                {
                    nuevo->abajo=temp;
                    ant->abajo=nuevo;
                    break;
                }else if(temp->hora<nuevo->hora&&(temp->abajo==NULL||temp->abajo->hora>nuevo->hora)){
                    nuevo->abajo=temp->abajo;
                    temp->abajo=nuevo;
                    break;
                }
                
                ant=temp->abajo;
                temp=temp->abajo;
            }
        }else{temp->abajo=nuevo;}   
        
        temp = fila;
        ant = fila;
        if (temp->siguiente!=NULL)
        {
        
            while (temp!=NULL)
            {
                if (temp->index>nuevo->index)
                {
                    nuevo->siguiente=temp;
                    ant->siguiente=nuevo;
                    break;
                }else if(temp->index<nuevo->index&&(temp->siguiente==NULL||temp->siguiente->index>nuevo->index)){
                    nuevo->siguiente=temp->siguiente;
                    temp->siguiente=nuevo;
                    break;
                }
                
                ant=temp;
                temp=temp->siguiente;
            }
        
        }else{temp->siguiente=nuevo;}
    }

    void imprimirDias(){
        nodoMatriz *temp = root;
        temp=temp->siguiente;
        while (temp!=NULL)
        {
            cout<<temp->dia+"\n";
            temp=temp->siguiente;
        }
        
    }

    void imprimirHoras(){
        nodoMatriz *temp = root;
        temp=temp->abajo;
        while (temp!=NULL)
        {
            
            cout<<to_string(temp->hora)+"\n";
            temp=temp->abajo;
        }
    }

    void imprimirActividades(){
        nodoMatriz *temp=root;
        temp=temp->siguiente;
        while (temp!=NULL)
        {   
            cout<<"Imprimiendo actividades del dia "+temp->dia+"\n";
            nodoMatriz *aux=temp;
            aux=aux->abajo;
            while (aux!=NULL)
            {
                cout<<to_string(aux->hora)+": "+aux->actividad+"\n";
                aux=aux->abajo;
            }
            

            temp=temp->siguiente;
        }
        
    }

    void imprimirActividadesDia(string dia){
        nodoMatriz *temp = root;
        while (temp!=NULL)
        {
            if(temp->dia==dia){
                nodoMatriz *aux = temp->abajo;
                while (aux!=NULL)
                {
                    cout<<to_string(aux->hora)+": "+aux->actividad+"\n";
                    aux=aux->abajo;
                }
                return;
            }
            temp=temp->siguiente;
        }
        cout<<"No existen actividades para ese dia\n";
    }


};