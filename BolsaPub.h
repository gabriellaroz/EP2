#ifndef BOLSA_PUB_H
#define BOLSA_PUB_H

#include "Bolsa.h"
#include "Professor.h"

using namespace std;

class BolsaPub : public Bolsa{
public:
    static const int NUMERO_DE_HORAS_POR_MES = 40;
    BolsaPub(Data* inicio, Professor* responsavel);
    virtual ~BolsaPub();

    void setHorasTrabalhadasNoMes(Data* data, int horas);
    int getHorasTrabalhadasNoMes(Data* data);

    Professor* getResponsavel();

    double getValor(Data* data) = 0;
private:
    Professor* responsavel;
    Data* fimBolsaPub;
    int mesSelecionado;
    int meses[11];
};

#endif