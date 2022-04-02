#include <iostream>
#include <vector>
using namespace std;

int partition(vector<float>& elements, float left_index, float right_index)
{
    auto pivot = elements.at(left_index);
    float i = left_index, j = right_index;
 
    while(true) {
        while( elements.at(i) <= pivot && i <   ) ++i;
        while( elements.at(j) > pivot ) --j;
        if( i >= j ) break;
        swap(elements.at(i), elements.at(j));
    }
    swap(elements.at(left_index), elements.at(j));
    return j;
}

void quick_sort(vector<float>& elements, float left_index, float right_index){
  
  if(left_index >= right_index){
    return;
  }else{

    float pivote = partition(elements, left_index, right_index);
    quick_sort(elements, left_index, pivote-1);
    quick_sort(elements, pivote+1, right_index);


  }
}

int main() {
  vector<float> elementos{1.2,4.5,7.8,9.7,4.2};

  cout << "Vector inicial es: " << "\n";
  for(auto elem: elementos){
    cout << elem << "-";
  }

  cout << "\n";

  quick_sort(elementos, 0, elementos.size()-1);
  for(auto elem: elementos){
    cout << elem << "-";
  }


  
}
