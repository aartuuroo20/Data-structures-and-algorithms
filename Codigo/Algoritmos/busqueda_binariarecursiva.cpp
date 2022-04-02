//
//  busqueda binaria(recursiva).cpp
//  apuntes algoritmos
//
//  Created by Carlitos B on 5/4/21.
//

#include <stdio.h>


#include <iostream>



#include <vector>
 


std::vector<int> slice(std::vector<int> values, int begin, int end) {
    if (begin >= end) { return std::vector<int>{}; }
    return std::vector<int>(values.begin() + begin, values.begin() + end);
}
 
bool binary_search(std::vector<int> values, int value_to_find) {
   
    if (values.empty()) { return false; } // If the vector is empty, the value is not there
    int middle = values.size() / 2;
    // TODO: Implement algorithm here
    if (value_to_find < values.at(middle)) {
        auto new_vector = slice(values, 0, middle);
        return binary_search(new_vector, value_to_find);
    }
    else if (value_to_find > values.at(middle)) {
        auto new_vector = slice(values, middle+1, values.size());
        return binary_search(new_vector, value_to_find);
    }
    else {
        return true;
    }
}

int BusquedaBinariaRecursiva(const std::vector<int>& v, int valorAbuscar, int primero, int ultimo) { 
    if (primero > ultimo) { // Caso base
        return -1;
    }

    int medio = (primero+ultimo)/2;
    
    if (valorAbuscar < values.(medio)){
        return BusquedaBinariaRecursiva(v, valorAbuscar, primero, medio-1)
    }
    else if(valorAbuscar > values.at(medio)){
        return BusquedaBinariaRecursiva(v, valorAbuscar, medio+1, ultimo);
    }
    else { 
        return medio;
    }
}
 
int main() {
    std::vector<int> values{1, 3, 5, 8, 13};
    bool found = binary_search(values, 8);
    if (found) {
        std::cout << "Element found" << std::endl;
    }
    else {
        std::cout << "Element not found" << std::endl;
    }
}

