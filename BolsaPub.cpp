#include <iostream>
#include "BolsaPub.h"
#include "Data.h"

BolsaPub::BolsaPub(Data* inicio, Professor* responsavel) : responsavel(responsavel), Bolsa(inicio, fimBolsaPub) {
    fimBolsaPub = new Data(inicio, 11);
}

BolsaPub::~BolsaPub() {
    delete fimBolsaPub;
}

void BolsaPub::setHorasTrabalhadasNoMes(Data* data, int horas) {
    if(!Data::estaDentroDoPeriodo(getInicio(), fimBolsaPub, data)) {
        throw new logic_error("Fora do periodo da bolsa");
    }

    
}

int BolsaPub::getHorasTrabalhadasNoMes(Data* data) {
    return ;
}