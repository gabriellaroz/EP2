#include "Bolsa.h"
#include "Data.h"

#include <stdexcept>
using namespace std;


double Bolsa::valorUSP = 700.0;

Bolsa::Bolsa(Data* inicio, Data* fim)
    : inicio(inicio), fim(fim)
{
    if (inicio == nullptr){
        throw new invalid_argument("n sei oq por");
    }
    if (fim == nullptr){
        throw new invalid_argument("n sei oq por");
    }

    int inicioano = inicio->getAno();
    int anofinal = fim->getAno();
    int iniciomes = inicio->getMes();
    int mesfinal = fim->getMes();

   
    if (inicioano > anofinal){
    throw new invalid_argument("eu nao sei oq por ainda");
}

    if (inicioano == anofinal){
        if (iniciomes > mesfinal){
        throw new invalid_argument("eu nao sei oq por ainda");
    }
}
}

Bolsa::~Bolsa() {
    delete inicio;
    delete fim;
}

Data* Bolsa::getInicio() {
    return inicio;
}

Data* Bolsa::getFim() {
    return fim;
}


double Bolsa::getValorUSP() {
    return valorUSP;
}

void Bolsa::setValorUSP(double valor) {
    if (valor < 0) {
        throw new invalid_argument("n sei oq por ainda");
    }
    valorUSP = valor;
}
