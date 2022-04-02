#include <iostream>
#include <vector>
#include <string>
using namespace std;

string partition(vector<string> & elements, string left_index, string right_index){
    auto pivote = elements.at(left_index);
    int i = left_index;
    int j = right_index;
    
    while(true){
        while(elements.at(i) <= pivote && i<= j) i++;
        while(elements.at(i) > pivote) --j;
        swap(elements.at(i), elements.at(j));
        
    }
    swap(elements.at(left_index), elements.at(j));
    return j;
}

void quick_sort(vector <string> & elements, int left_index, int right_index){
    if(left_index >= right_index){
        return;
    }else{
        string pivote = partition(elements, left_index, right_index);
        quick_sort(elements, left_index, pivote-1);
        quick_sort(elements, pivote+1, right_index);
    }
    
    
}

int main() {
  vector<string> elementos{"Arturo", "Javier", "Alberto", "David", "Alejandro","Daniel"};
  cout << "Vector inicial es: " << "\n";
  for(auto elem: elementos){
    cout << elem << "-";
  }

  cout << "\n";

  cout << "El vector final es: " << "\n";

  quick_sort(elementos, 0, elementos.size()-1);
  
  for(auto elem: elementos){
    cout << elem << "-";
  }






}
