#include <iostream>
#include <vector>
using namespace std;

vector<float> merge(const vector<float>& lhs, const vector<float>& rhs){
  vector<float> ret;
  auto izquierda_iterador = 0;
  auto derecha_iterador = 0;
  while(izquierda_iterador != lhs.size() && derecha_iterador != rhs.size()){
     if (lhs.at(izquierda_iterador) < rhs.at(derecha_iterador)) {
            ret.push_back(lhs.at(izquierda_iterador));
            izquierda_iterador++;
      }else{
         ret.push_back(rhs.at(derecha_iterador));
          derecha_iterador++;
        }
      }
  for (int i=izquierda_iterador; i<lhs.size(); i++) {
        ret.push_back(lhs.at(i));
    }
  for (int i=derecha_iterador; i<rhs.size(); i++) {
        ret.push_back(rhs.at(i));
    }
    return ret;
}
 
vector<float> merge_sort(const vector<float> & elements) {
  if(elements.size() <= 1){
    return elements;
  }else{
    auto medio = elements.size()/2;
    vector<float> izquierda{elements.begin(), elements.begin()+medio};
    vector<float> derecha{elements.begin()+medio, elements.end()};

    izquierda = merge_sort(izquierda);
    derecha = merge_sort(derecha);

    return merge(izquierda, derecha);
  }
}
 
int main() {
  vector<float> elementos{1.2,4.5,7.8,9.7,4.2};
  cout << "El vector inicial es: " << "\n";
  for(auto elem: elementos){
    cout << elem << "-";
  }
  
  cout << "\n";

  elementos = merge_sort(elementos);
  cout << "El vector final es " << "\n";
  for(auto elem: elementos){
    cout << elem << "-";
  }

 
}