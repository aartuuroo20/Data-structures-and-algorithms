#include <iostream>
#include <vector>
using namespace std;
 
void selection_sort(vector<float> & elements) {
  for(int i=0; i<elements.size(); i++){
    int index=i;
    for(int k=i+1; k<elements.size(); k++){
      if(elements.at(k) < elements.at(index)){
        index = k;
      }
    }
    swap(elements.at(i), elements.at(index));

  }
  
}
 
int main() {
  vector<float> elementos{1.2,4.5,7.8,9.7,4.2};
  cout << "El vector inicial es: " << "\n";
  for(auto elem: elementos){
    cout << elem << "-";
  }
  
  cout << "\n";

  selection_sort(elementos);
  cout << "El vector final es " << "\n";
  for(auto elem: elementos){
    cout << elem << "-";
  }

 
}