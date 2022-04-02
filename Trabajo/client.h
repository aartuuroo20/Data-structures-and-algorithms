#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
using namespace std;

class Client {
public:
    Client();
    Client(int _max, int _min);

    int time_to_pay = max - min;

 protected:
    int max;
    int min;

};

#endif // CLIENT_H
