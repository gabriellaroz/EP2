#ifndef BOLSA_PEEG_H
#define BOLSA_PEEG_H

#include "Bolsa.h"
#include <string>

using namespace std;

class BolsaPeeg : public Bolsa{
public: 
   BolsaPeeg(Data* inicio, Data* fim, string disciplina); 
   virtual ~BolsaPeeg(); 
   string getDisciplina();

   double getValor(Data* d);  
    void imprimir();           

private: 
string disciplina;
};

#endif