#include <iostream>
#include <fstream>
#include<vector>
using namespace std;
typedef std::vector<std::string>  StringVector;

StringVector Explode(const std::string & str, char separator )
{
   StringVector  result;
   size_t pos1 = 0;
   size_t pos2 = 0;
   while ( pos2 != str.npos )
   {
      pos2 = str.find(separator, pos1);
      if ( pos2 != str.npos )
      {
         if ( pos2 > pos1 )
            result.push_back( str.substr(pos1, pos2-pos1) );
         pos1 = pos2+1;
      }
   }
   result.push_back( str.substr(pos1, str.size()-pos1) );
    
    return result;
    
}


class cargaMasiva{
public:

    void cargar(string nombreArchivo,Matriz matrix){

        ifstream archivo;
        string dato;
        StringVector palabra;
        archivo.open(nombreArchivo);
        getline(archivo,dato);
        while(getline(archivo,dato)){
            string hora,dia,actividad;
            palabra=Explode(dato,',');
            hora=palabra[0];
            dia=palabra[1];
            actividad=palabra[2];
            matrix.insertar(stoi(hora),dia,actividad);
        }
    }


};