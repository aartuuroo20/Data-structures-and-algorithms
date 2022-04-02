#include <iostream>
#include <string>
using namespace std;

std::string message_dream(std::string word, int level, int factor_temporal){
    
    if(level==0) {return word;} //devuelve la palabra sin modificar
     else{
        std::string ret; //creamos una variable string donde se almacenara la nueva palabra 
        for (auto c: word) { //mira letra por letra
            if(c==' '){ //si encuentra un espacio 
                ret.push_back(' '); //No lo repite y lo añade solo una vez 
            }else{ //Si no encuentra un espacio añade las letras de forma continua
            for (auto i=0; i<factor_temporal; i++) { //repite las letras en funcion del factor temporal
                ret.push_back(c); //las añade 
            }
        }
    }
        
        return message_dream(ret, level-1, factor_temporal); //RESTAR EL NIVEL HASTA LLEGAR A 0 

    }
 }

int main() {
    cout << message_dream("Hola!", 2, 2) << endl; // HHHHoooollllaaaa!!!!
    cout << message_dream("Soy Ana", 1, 3) << endl; // SSSoooyyy AAAnnnaaa
    cout << message_dream("Apruebame", 2, 2)<< endl; 
    
}

// el nivel indica cuantas veces se tiene que multiplicar el factor temporal por si mismo
