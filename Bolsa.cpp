#include "Bolsa.h"
#include "Data.h"

#include <stdexcept>
using namespace std;


double Bolsa::valorUSP = 700.0;

Bolsa::Bolsa(Data* inicio, Data* fim)
    : inicio(inicio), fim(fim)
{
    if (inicio == nullptr){
        throw new invalid_argument("Data de inicio nula.");
    }
    if (fim == nullptr){
        throw new invalid_argument("Data de fim nula.");
    }

    int anoInicio = inicio->getAno();
    int anoFim = fim->getAno();
    int mesInicio = inicio->getMes();
    int mesFim = fim->getMes();

   
    if (anoInicio > anoFim || (anoInicio == anoFim && mesInicio > mesFim)){
        throw new invalid_argument("Data de inicio posterior à data de fim.");
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
        throw new invalid_argument("Valor USP não pode ser negativo.");
    }
    valorUSP = valor;
}
