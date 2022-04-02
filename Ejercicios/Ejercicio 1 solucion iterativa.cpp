#include <iostream>
#include <string>

int factor_temporal=0;
std::string message_dream(std::string cadena, int level, int factor_temporal){
	if(level==0){
		return cadena;
	}else{
		std::string ret;
		for(auto e:cadena){
			for(auto i=0;i<factor_temporal;i++){
				ret.push_back(e);
			}
		}
		return message_dream(ret, level-1,factor_temporal);
	}
}
int main() {
  std::cout << message_dream("Hola!",2,2)<<"\n";
	std::cout << message_dream("Soy",1,3)<<" ";
	std::cout << message_dream("Ana",1,3)<<"\n";
}