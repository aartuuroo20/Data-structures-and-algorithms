#ifndef ELEMENTOLISTADOBLE_H
#define ELEMENTOLISTADOBLE_H
#include <iostream>
#include <memory>
#include "client.h"
using namespace std;


class ElementoListaDoble {
public:

    Client dato;
    std::shared_ptr<ElementoListaDoble> next = nullptr;
    std::shared_ptr<ElementoListaDoble> prev = nullptr;
public:

    ElementoListaDoble(const Client & dato_);
};
#endif // ELEMENTOLISTADOBLE_H
