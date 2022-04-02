#include <iostream>
#include "Colas.h"
#include "client.h"
#include <array>
#include <fstream>
using namespace std;


void add_new_client_shortest_lane(array<Queue, 4>& lanes) { //Añadir cliente a la cola mas corta
    Client client{};
    int shortest_idx = 0;
    for (int i=0; i<lanes.size(); i++) {
        if (lanes[i].size() < lanes[shortest_idx].size()) {
            shortest_idx = i;
        }
    }
    lanes[shortest_idx].push(client);
}

void add_new_client_aleatory_lane(array<Queue, 4>& lanes) { //Añadir cliente a una caja al azar
    Client client{};
    int n= rand() % 3;
    lanes[n].push(client);
}

int main()
{
    //Una cola por Caja, los clientes se añaden a la cola mas corta

    ofstream data;
    data.open("output.txt");

    cout << "Introduce segundos maximos para la generacion de nuevo cliente: ";
    int max; cin >> max;

    cout << "Introduce segundos minimos para la generacion de nuevo cliente: ";
    int min; cin >> min;
    int time_new_client = min + rand() % (max - min);

    cout << endl;

    cout << "Quiere que se añada a la cola mas corta o de forma aleatoria, 1.Aleatorio o 2.Cola mas corta: ";
    int opcion; cin >> opcion;

    int segundos = 0;
    array<Queue, 4> lanes;
    while (segundos < 10000) {
        for (auto& lane: lanes) {
            if (!lane.empty()) {
                auto& front_client = lane.front();
                front_client.time_to_pay--;
                if (front_client.time_to_pay <= 0) {
                    lane.pop();
                }
            }
        }

        if (segundos % time_new_client == 0) {

            if(opcion == 1){
                add_new_client_aleatory_lane(lanes);
            }else{
                add_new_client_shortest_lane(lanes);
            }
        }
        int total = 0;
        data << segundos << " ";
        for (auto & lane: lanes) {
            data << lane.size() << " ";
            total += lane.size();
        }
        data << total << endl;
        segundos += 1;
    }
    data.close();

    //Sistema de cola unica, solo existe una cola a la cual se añaden todos los clientes

    array<Client, 4> cajas;
    int segundos2 = 0;
    Queue clientes;
    while(segundos2 < 10000){
        for (int i=0; i<cajas.size(); i++) {
            cajas.at(i).time_to_pay--;
            if (cajas.at(i).time_to_pay <= 0) {
                if (!clientes.empty()) {
                    auto front_client = clientes.front();
                    clientes.pop();
                    cajas.at(i) = front_client;
                }
            }
        }
        if(segundos2 % time_new_client == 0){
            clientes.push(Client{});
        }

        segundos2 += 1;


    }




}
