#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include "Bolsa.h"
#include "Data.h"

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

class Aluno : public Usuario {
public:
    Aluno(int nusp, string nome);
    virtual ~Aluno();

    void adicionar(Bolsa* bolsa);
    vector<Bolsa*>* getBolsas();

    double getValor(Data* data);

    void imprimir();
private:
    vector<Bolsa*>* bolsas;
};

#endif