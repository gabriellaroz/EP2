#ifndef BOLSAPIBIC_H
#define BOLSAPIBIC_H

#include "Bolsa.h"
#include "Professor.h"
#include "Data.h"

class BolsaPibic : public Bolsa {
public:
    BolsaPibic(Data* inicio, Professor* orientador);
    virtual ~BolsaPibic();

    void entregarRelatorioParcial(Data* data);

    Data* getDataEntregaRelatorioParcial();
    Professor* getOrientador();

    virtual double getValor(Data* d);
    virtual void imprimir();  

private:
    Data* dataRelatorio;
    Professor* orientador;
};

#endif
