#include "Aluno.h"
#include "BolsaPeeg.h"
#include "BolsaPibic.h"
#include "BolsaPub.h"

Aluno::Aluno(int nusp, string nome) : Usuario(nusp, nome) {
    vector<Bolsa*>* bolsas = new vector<Bolsa*>();
    this->bolsas = bolsas;
}

Aluno::~Aluno() {
    vector<Bolsa*>::iterator i = bolsas->begin();
    
    while(i != bolsas->end()) {
        delete *i;
        i++;
    }

    delete bolsas;
}

void Aluno::adicionar(Bolsa* bolsa) {
    vector<Bolsa*>::iterator i = bolsas->begin();

    while(i != bolsas->end()) {
        if(Data::temInterseccao(bolsa->getInicio(), bolsa->getFim(), (*i)->getInicio(), (*i)->getFim())) {
            throw new logic_error("Periodo de bolsas conflitante");
        }
        i++;
    }

    bolsas->push_back(bolsa);
}

vector<Bolsa*>* Aluno::getBolsas() {
    return bolsas;
}

double Aluno::getValor(Data* data) {
    vector<Bolsa*>::iterator i = bolsas->begin();

    while(i != bolsas->end()) {
        if(Data::estaDentroDoPeriodo((*i)->getInicio(), (*i)->getFim(), data)) {
            return (*i)->getValorUSP();
        }
        i++;
    }
    return 0;
}

void Aluno::imprimir() {
    cout << "Aluno: " << getNome() << endl;
    
    if(bolsas->empty()) {
        cout << "Sem bolsas" << endl;
    } else {
        vector<Bolsa*>::iterator i = bolsas->begin();

        while(i != bolsas->end()) {
            (*i)->imprimir();
            i++;    
        }
    }
}
