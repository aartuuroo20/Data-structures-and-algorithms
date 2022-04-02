#include <iostream>
#include <vector>
#include <string>
using namespace std;

void selection_sort(vector<string> & elements){
    for(int i=0; i<elements.size(); i++){
        int indice = i;
        for(int k = i+1; k<elements.size(); k++){
            if(elements.at(k) < elements.at(indice)){
                indice = k;
            }
        }
        swap(elements.at(i), elements.at(indice));
    }
}





int main() {
  vector<string> elementos{"Arturo", "Javier", "Alberto", "David", "Alejandro"};
  cout << "Vector inicial es: " << "\n";
  for(auto elem: elementos){
    cout << elem << "-";
  }

  cout << "\n";

  cout << "El vector final es: " << "\n";

  selection_sort(elementos);
  for(auto elem: elementos){
    cout << elem << "-";
  }






}
