#include <iostream>
#include "BolsaPeeg.h"
#include "Data.h"           
using namespace std;

BolsaPeeg::BolsaPeeg(Data* inicio, Data* fim, string disciplina)
    : Bolsa(inicio, fim) 
    {
    this->disciplina = disciplina;
    }  

BolsaPeeg::~BolsaPeeg() {}

string BolsaPeeg::getDisciplina() {
    return disciplina;
}

double BolsaPeeg::getValor(Data* d) {

    if (d == nullptr) {
        throw new invalid_argument("mensagem");
    }

    int anoD = d->getAno();
    int mesD = d->getMes();

    int anoInicio = getInicio()->getAno();
    int mesInicio = getInicio()->getMes();

    int anoFim = getFim()->getAno();
    int mesFim = getFim()->getMes();

    bool dataAntesDoInicio = (anoD < anoInicio) || (anoD == anoInicio && mesD < mesInicio);

    bool dataDepoisDoFim = (anoD > anoFim) ||(anoD == anoFim && mesD > mesFim);


    if (dataAntesDoInicio || dataDepoisDoFim){
        return 0;
    }
    return getValorUSP();
}

void BolsaPeeg::imprimir() {
    int mesInicio = getInicio()->getMes();
    int anoInicio = getInicio()->getAno();

    int mesFim = getFim()->getMes();
    int anoFim = getFim()->getAno();

    cout << "(PEEG) "
         << mesInicio << "/" << anoInicio
         << " a "
         << mesFim << "/" << anoFim
         << " - "
         << disciplina
         << endl;
}
