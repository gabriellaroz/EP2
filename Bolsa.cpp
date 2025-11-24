#include "Bolsa.h"
#include "Data.h"
#include "Professor.h"
#include <stdexcept>

using namespace std;

double Bolsa::valorUSP = 700.0;

Bolsa::Bolsa(Data* inicio, Data* fim, Professor* responsavel)
    : inicio(inicio), fim(fim), responsavel(responsavel)
{
    if (inicio == nullptr) {
        throw new invalid_argument("Data de inicio nula");
    }

    if (fim == nullptr) {
        throw new invalid_argument("Data de fim nula");
    }

   bool anoMaior = (inicio->getAno() > fim->getAno());
   bool mesMaior = (inicio->getAno() == fim->getAno() && inicio->getMes() > fim->getMes());


    if (anoMaior || mesMaior){
        throw new invalid_argument("Data de inicio posterior à data de fim");
    }
}

Bolsa::~Bolsa() {}