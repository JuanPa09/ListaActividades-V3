#include <iostream>

using namespace std;

class Graficar{

public:
    Matriz matrix;
    ofstream f;
    Graficar(Matriz matrix){
        this->matrix=matrix;
    }

    void root(nodoMatriz *raiz){

        f<<"Raiz[label=\"Raiz\" group=0]\n";

        

        f<<"Raiz->"+raiz->siguiente->dia+to_string(raiz->siguiente->hora)+"\n";
        f<<"Raiz->"+raiz->abajo->dia+to_string(raiz->abajo->hora)+"\n";

    }

    void filas(nodoMatriz *raiz){
        nodoMatriz *temp=raiz;
        temp=temp->abajo;
        while(temp!=NULL){
            f<<temp->dia+to_string(temp->hora)+"[label=\""+to_string(temp->hora)+"\" group=0]\n";
            temp=temp->abajo;
        }
    }

    void columnas(nodoMatriz *raiz){
        nodoMatriz *temp=raiz;
        temp=temp->siguiente;
        int x=0;
        string same="{rank=same;Raiz";
        while(temp!=NULL){
            f<<temp->dia+to_string(temp->hora)+"[label=\""+temp->dia+"\" group="+to_string(x)+"]\n";
            x+=1;
            same=same+";"+temp->dia+to_string(temp->hora);
            temp=temp->siguiente;
        }
        //same=same+";"+temp->dia+"}\n";
        same=same+"}";
        f<<same;
    }

    void efilas(nodoMatriz *raiz){
        nodoMatriz *temp=raiz;
        temp=temp->abajo;
        while (temp->abajo!=NULL)
        {
            f<<temp->dia+to_string(temp->hora)+"->"+temp->abajo->dia+to_string(temp->abajo->hora)+"\n";
            temp=temp->abajo;
        }
        
    }


    void ecolumnas(nodoMatriz *raiz){
        nodoMatriz *temp=raiz;
        temp=temp->siguiente;
        while (temp->siguiente!=NULL)
        {
            f<<temp->dia+to_string(temp->hora)+"->"+temp->siguiente->dia+to_string(temp->siguiente->hora)+"\n";
            temp=temp->siguiente;
        }
    }

    void nodos(nodoMatriz *raiz){
        nodoMatriz *temp=raiz;
        int x=0;
        temp=temp->siguiente;
        while(temp!=NULL){
            
            nodoMatriz *aux=temp->abajo;
            
            while(aux!=NULL){
                f<<aux->dia+to_string(aux->hora)+"[label=\""+aux->actividad+"\" group="+to_string(x)+"]\n";
                aux=aux->abajo;
            }
            x++;
            temp=temp->siguiente;

        }
    }

    void enodos(nodoMatriz *raiz){
        nodoMatriz *temp=raiz;
        temp=temp->siguiente;
        while (temp!=NULL)
        {
            nodoMatriz *aux= temp;
            while (aux->abajo!=NULL)
            {
                f<<aux->dia+to_string(aux->hora)+"->"+aux->abajo->dia+to_string(aux->abajo->hora)+"\n";
                aux=aux->abajo;
            }
            
            temp=temp->siguiente;
        }

        
        temp=raiz;
        temp=temp->abajo;
        while (temp!=NULL)
        {
            string same="{rank=same";
            nodoMatriz *aux=temp;
            while (aux->siguiente!=NULL)
            {
                f<<aux->dia+to_string(aux->hora)+"->"+aux->siguiente->dia+to_string(aux->siguiente->hora)+"\n";
                same+=";"+aux->dia+to_string(aux->hora);
                aux=aux->siguiente;
            }
                same+=";"+aux->dia+to_string(aux->hora)+"}\n";
                f<<same;
            temp=temp->abajo;
        }
        
        
    }

    


    void graphMatriz(){
        f.open("nuevo.txt",std::ios::out);
        f<<"digraph G{ \n";
        f<<"node [margin=0 ranksep=\"0.1\", nodesep=\"0.1\" width=\"0.1\" height=\"0.1\" shape=Square style=filled]\n";
        root(matrix.root);
        filas(matrix.root);
        columnas(matrix.root);
        efilas(matrix.root);
        ecolumnas(matrix.root);
        nodos(matrix.root);
        enodos(matrix.root);

        cout<<"Columna";
        f<<"}";
        f.close();
        Grafica();
    }


    void Grafica(){
        system("dot -Tjpg nuevo.txt -o imagen.jpg");
        system("imagen.jpg");                
    }

    

};