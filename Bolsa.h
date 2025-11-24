#ifndef BOLSA_H
#define BOLSA_H

class Data;
class Bolsa {
private:
    Data* inicio;
    Data* fim;
    static double valorUSP; // valor da bolsa usp 

public:
    Bolsa(Data* inicio, Data* fim);
    virtual ~Bolsa();

    Data* getInicio();
    Data* getFim();

    // metodos abstratos!!
    virtual double getValor(Data* data) = 0;
    virtual void imprimir() = 0;

    // metodos estaticos!!
    static double getValorUSP();
    static void setValorUSP(double valor);
};

#endif
