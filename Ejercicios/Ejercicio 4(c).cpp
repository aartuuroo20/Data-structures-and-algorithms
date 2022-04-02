#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> merge(const vector<string> lhs, const vector<string> rhs){
    vector<string> ret;
    auto left_iterator = 0;
    auto right_iterator = 0;

    while(left_iterator != lhs.size() && right_iterator != rhs.size()){
        if(lhs.at(left_iterator) < rhs.at(right_iterator)){
            ret.push_back(lhs.at(left_iterator));
            left_iterator++;
        }else{
            ret.push_back(rhs.at(right_iterator));
            right_iterator++;
        }
    }
    for(int i=left_iterator; i < lhs.size(); i++){
        ret.push_back(lhs.at(i));
    }
    for(int i=right_iterator; i < rhs.size(); i++){
        ret.push_back(rhs.at(i));
    }
    return ret;
}

vector<string> merge_sort(const vector<string> & elements){
    if(elements.size() <= 1){
        return elements;
    }else{
        auto middle = elements.size()/2;
        vector<string> left{elements.begin(), elements.begin()+middle};
        vector<string> right{elements.begin()+middle, elements.end()};

        left = merge_sort(left);
        right = merge_sort(right);

        return merge(left, right);
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

  elementos = merge_sort(elementos);
  for(auto elem: elementos){
    cout << elem << "-";
  }






}
