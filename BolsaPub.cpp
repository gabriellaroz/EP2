#include <iostream>
#include "BolsaPub.h"
#include "Data.h"
#include <stdexcept>

BolsaPub::BolsaPub(Data* inicio, Professor* responsavel)
    : responsavel(responsavel), Bolsa(inicio, new Data(inicio, 11)) {
    for(int i = 0; i < 12; i++) {
        meses[i] = 0;
    }
}

BolsaPub::~BolsaPub() {}

void BolsaPub::setHorasTrabalhadasNoMes(Data* data, int horas) {
    if(!Data::estaDentroDoPeriodo(getInicio(), getFim(), data)) {
        throw new logic_error("Fora do periodo da bolsa");
    }

    mesSelecionado = (data->getAno() - getInicio()->getAno())*12 + (data->getMes() - getInicio()->getMes());
    meses[mesSelecionado] = horas;
}

int BolsaPub::getHorasTrabalhadasNoMes(Data* data) {
    mesSelecionado = (data->getAno() - getInicio()->getAno())*12 + (data->getMes() - getInicio()->getMes());
    return meses[mesSelecionado];
}

Professor* BolsaPub::getResponsavel() {
    return responsavel;
}

double BolsaPub::getValor(Data* data) {
    if(!Data::estaDentroDoPeriodo(getInicio(), getFim(), data)) {
        return 0;
    }

    if(getHorasTrabalhadasNoMes(data) >= NUMERO_DE_HORAS_POR_MES) {
        return getValorUSP();
    } else {
        double valorProporcional = (double(getHorasTrabalhadasNoMes(data))/NUMERO_DE_HORAS_POR_MES)*getValorUSP();
        return valorProporcional;
    }
}

void BolsaPub::imprimir() {
    cout << "(PUB) "
        << getInicio()->getMes() << "/" << getInicio()->getAno()
        << " a "
        << getFim()->getMes() << "/" << getFim()->getAno()
        << " - Responsavel: " << getResponsavel()->getNome() << endl;
}