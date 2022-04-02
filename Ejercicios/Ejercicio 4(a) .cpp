#include <iostream>
#include <vector>
#include <string>
using namespace std;

void bubble_sort(vector<string>& elements){
  for(int i=0; i<elements.size(); i++){
    for(int k=0; k<elements.size()-1; k++){
      if(elements.at(k) > elements.at(k+1)){
      swap(elements.at(k), elements.at(k+1));
    }
    }
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

  bubble_sort(elementos);
  for(auto elem: elementos){
    cout << elem << "-";
  }






}

