#include <iostream>
#include "BolsaPeeg.h"
#include "Data.h"       
#include "Bolsa.h"      
using namespace std;

BolsaPeeg::BolsaPeeg(Data* inicio, Data* fim, string disciplina)
    : Bolsa(inicio, fim) 
    {
    this->disciplina = disciplina;
    }  

BolsaPeeg::~BolsaPeeg() {}

string BolsaPeeg::getDisciplina() {
    return disciplina;
}

