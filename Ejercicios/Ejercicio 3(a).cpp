#include <iostream>
#include <vector>
using namespace std;
 
void bubble_sort(vector<float> & elements) {
  for(int i=0; i<elements.size()-1; i++){
    for(int k=0; k<elements.size()-1; k++){
     if(elements.at(k) > elements.at(k+1)){
        swap(elements.at(k), elements.at(k+1));
      }
    }
  }
}
 
int main() {
  vector<float> elementos{1.2,4.5,7.8,9.7,4.2};
  cout << "El vector inicial es: " << "\n";
  for(auto elem: elementos){
    cout << elem << "-";
  }

  cout << "\n";

  bubble_sort(elementos);
  cout << "Vector ordenado es: " << "\n";
  for(auto elem: elementos){
    cout << elem << "-";
  }
}