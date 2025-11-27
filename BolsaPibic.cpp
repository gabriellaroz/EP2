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

Professor* BolsaPibic::getOrientador(){
    return orientador;
}

double BolsaPibic::getValor(Data* d){ // logica mais punk
    
    if (d == nullptr) // se não passou data, retorna 0, não recebe nada
        return 0;


    Data* inicial = getInicio(); // pega o inicio da bolsa
    Data* fim = getFim(); // pega o fim da bolsa

    int dMes = d->getMes(); // extrai o mes e ano da data pedida
    int dAno = d->getAno();

    int iMes = inicial->getMes(); // extrai o mes o ano do inicio
    int iAno = inicial->getAno();

    int fMes = fim->getMes(); // extrai o mes e ano do fim
    int fAno = fim->getAno();


    bool antes = (dAno < iAno) || (dAno == iAno && dMes < iMes); // verifica se a data é antes do inicio
    bool depois = (dAno > fAno) || (dAno == fAno && dMes > fMes); // verifica se a data é depois do fim

    if (antes || depois) // se estiver fora do periodo, nao recebe bolsa
        return 0;


    int md = 0; // aqui calcula quantos meses passaram desde o inicio
    md += (dAno - iAno) * 12; // soma meses referentes a diferença de anos
    md += (dMes - iMes); // soma diferença dos meses


    if (md < 6) // se ainda esta nos primeiro meses, recebe!
        return getValorUSP();

    if (dataRelatorio == nullptr) //se apos 6 meses so recebe se tiver relatorio
        return 0;

    // apega mes e ano do relatorio
    int rMes = dataRelatorio->getMes();
    int rAno = dataRelatorio->getAno();

    // verifica se a data d é igual ou depois da entrega do relatorio
    bool aposRel = (dAno > rAno) || (dAno == rAno && dMes >= rMes);

    // se estiver antes, nao recebe
    if (!aposRel)
        return 0;

    // se passou por tudo, recebe
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
         << orientador->getNome()
         << endl;
}

