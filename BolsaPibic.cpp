#include "BolsaPibic.h"
#include <iostream>
using namespace std;

BolsaPibic::BolsaPibic(Data* inicio, Professor* orientador)
    : Bolsa(inicio, new Data(inicio, 11))
{
    this->orientador = orientador;
    dataRelatorio = nullptr;
}

BolsaPibic::~BolsaPibic() {
    if (dataRelatorio != nullptr) {
        delete dataRelatorio;
    }
}

void BolsaPibic::entregarRelatorioParcial(Data* data) {
    dataRelatorio = data;
}

Data* BolsaPibic::getDataEntregaRelatorioParcial() {
    return dataRelatorio;
}

Professor* BolsaPibic::getOrientador() {
    return orientador;
}


 //VOU ARRUMAR ESSA LOGICA PRA ENTENDER 
double BolsaPibic::getValor(Data* d) {

    if (d == nullptr)
        return 0;

    Data* ini = getInicio();
    Data* fim = getFim();

    int iniMes = ini->getMes();
    int iniAno = ini->getAno();

    int fimMes = fim->getMes();
    int fimAno = fim->getAno();

    int dMes = d->getMes();
    int dAno = d->getAno();

    // Fora do período
    bool antes = (dAno < iniAno) || (dAno == iniAno && dMes < iniMes);
    bool depois = (dAno > fimAno) || (dAno == fimAno && dMes > fimMes);

    if (antes || depois)
        return 0;

    // Mês relativo (0 = mês do início)
    int mesesD = (dAno - iniAno) * 12 + (dMes - iniMes);

    // Primeiros 6 meses → recebe bolsa normal
    if (mesesD < 6)
        return getValorUSP();

    // Depois do sexto mês → depende do relatório
    if (dataRelatorio == nullptr)
        return 0;

    int relMes = dataRelatorio->getMes();
    int relAno = dataRelatorio->getAno();
    int mesesEntrega = (relAno - iniAno) * 12 + (relMes - iniMes);

    if (mesesD < mesesEntrega)
        return 0;

    return getValorUSP();
}

void BolsaPibic::imprimir() {

    Data* ini = getInicio();
    Data* fim = getFim();

    cout << "(PIBIC) "
         << ini->getMes() << "/" << ini->getAno()
         << " a "
         << fim->getMes() << "/" << fim->getAno()
         << " - Orientador: "
         << orientador->getNome();
}

