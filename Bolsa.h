#ifndef BOLSA_H
#define BOLSA_H

#define BOLSA_USP 700.0

class Data;

class Bolsa {
private:
    Data* inicio;
    Data* fim;
    static double valorUSP; // valor padrao da bolsa USP

public:
    Bolsa(Data* inicio, Data* fim);
    virtual ~Bolsa();

    Data* getInicio();
    Data* getFim();

    // metodos abstratos!!
    virtual double getValor(Data* data) = 0;
    virtual void imprimir() = 0;

    // mtodos estaticos!!
    static double getValorUSP();
    static void setValorUSP(double valor);
};

#endif
