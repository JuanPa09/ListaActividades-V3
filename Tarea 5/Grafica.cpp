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

        

        f<<"Raiz->"+raiz->siguiente->dia+"\n";
        f<<"Raiz->"+to_string(raiz->abajo->hora)+"\n";

    }

    void filas(nodoMatriz *raiz){
        nodoMatriz *temp=raiz;
        temp=temp->abajo;
        while(temp->abajo!=NULL){
            f<<to_string(temp->hora)+"->"+to_string(temp->abajo->hora)+"\n";
            temp=temp->abajo;
        }
    }

    void columnas(nodoMatriz *raiz){
        nodoMatriz *temp=raiz;
        temp=temp->siguiente;
        int x=0;
        string same="{rank=same;Raiz";
        while(temp->siguiente!=NULL){
            f<<temp->dia+"->"+temp->siguiente->dia+"[group="+to_string(x)+"]\n";
            x+=1;
            same=same+";"+temp->dia;
            temp=temp->siguiente;
        }
        same=same+";"+temp->dia+"}\n";
        f<<same;
    }

    void nodos(nodoMatriz *raiz){
        nodoMatriz *temp=raiz;
        temp=temp->siguiente;
        int x=0;
        while(temp!=NULL){
            nodoMatriz *aux = temp;

            while(aux->abajo!=NULL){
                aux=aux->abajo;
            }

            x+=1;
            temp=temp->siguiente;
        }

    }


    void graphMatriz(){
        f.open("nuevo.txt",std::ios::out);
        f<<"digraph G{ \n";
        f<<"node [margin=0 ranksep=\"0.1\", nodesep=\"0.1\" width=\"0.1\" height=\"0.1\" shape=Square style=filled]\n";
        root(matrix.root);
        filas(matrix.root);
        columnas(matrix.root);
        f<<"}";
        f.close();
        Grafica();
    }


    void Grafica(){
        system("dot -Tjpg nuevo.txt -o imagen.jpg");
        system("imagen.jpg");                
    }

    

};