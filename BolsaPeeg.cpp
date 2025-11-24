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

    int ano = d->getAno();
    int mes = d->getMes();

    int anoIni = getInicio()->getAno();
    int mesIni = getInicio()->getMes();

    int anoFim = getFim()->getAno();
    int mesFim = getFim()->getMes();

    bool antes = (ano < anoIni) || (ano == anoIni && mes < mesIni);
    bool depois = (ano > anoFim) || (ano == anoFim && mes > mesFim);

    if (antes || depois) {
        return 0;
    }

    return getValorUSP();
}

void BolsaPeeg::imprimir() {
    cout << "(PEEG) "
         << getInicio()->getMes() << "/" << getInicio()->getAno()
         << " a "
         << getFim()->getMes() << "/" << getFim()->getAno()
         << " - "
         << disciplina
         << endl;
}
