#include "Data.h"
#include <stdexcept>
#include <string>
using namespace std;

Data::Data(int mes, int ano) : //construtor 1
    mes(mes), ano(ano){
    bool mesInvalido = (mes < 1 || mes > 12);
    bool anoInvalido = (ano < 1900);

    if (mesInvalido || anoInvalido) {
        throw new invalid_argument("Data invalida");
    }
}

Data::Data(Data* base, int meses){ //construtor 2

    if (base == nullptr){
        throw new invalid_argument("Data base nula");
    }

    mes = base->getMes();
    ano = base->getAno();
    mes += meses;

    while (mes > 12){
        mes -= 12;
        ano++;
    }
    if (ano < 1900) {
    throw new invalid_argument("Ano resultante invalido");
}

}
Data::~Data(){} //destrutor

bool Data::estaDentroDoPeriodo(Data* inicio, Data* fim, Data* d) {

    if (inicio == nullptr){
        throw new invalid_argument("Data nula");
    }

    if (fim == nullptr){
        throw new invalid_argument("Data nula");
    }
  
    if (d == nullptr){
        throw new invalid_argument("Data nula");
    }

    bool depoisdeiniciar;
    bool antesdofim;

    if (d->getAno() > inicio->getAno()){
        depoisdeiniciar = true;
    } 
    else if (d->getAno() == inicio->getAno() && d->getMes() >= inicio->getMes()){
        depoisdeiniciar = true;
    } 
    else{
        depoisdeiniciar = false;
    }

    if (d->getAno() < fim->getAno()){
        antesdofim = true;
    } 
    else if (d->getAno() == fim->getAno() && d->getMes() <= fim->getMes()){
        antesdofim = true;
    } 
    else{
        antesdofim = false;
    }

    return (depoisdeiniciar && antesdofim);
}

bool Data::temInterseccao(Data* inicio1, Data* fim1, Data* inicio2, Data* fim2){

    if (inicio1 == nullptr){
        throw new invalid_argument("Data nula");
    }

    if (fim1 == nullptr){
        throw new invalid_argument("Data nula");
    }

    if (inicio2 == nullptr){
        throw new invalid_argument("Data nula");
    }

    if (fim2 == nullptr){
        throw new invalid_argument("Data nula");
    }

    bool intervalo1Antes = (fim1->getAno() < inicio2->getAno()) || (fim1->getAno() == inicio2->getAno() && fim1->getMes() < inicio2->getMes());

    bool intervalo2Antes = (fim2->getAno() < inicio1->getAno()) || (fim2->getAno() == inicio1->getAno() && fim2->getMes() < inicio1->getMes());

    if (intervalo1Antes || intervalo2Antes)
        return false;

    return true;
}

int Data::getMes(){
    return mes;
}

int Data::getAno(){
    return ano;
}