#ifndef PROFESSOR_H
#define PROFESSOR_H 

#include "Usuario.h"
#include <string>

class Professor: public Usuario {
public: 
    Professor(int nusp, string nome, string unidade); 
    virtual ~Professor(); 
    string getUnidade(); 

    virtual void imprimir();

private: 
    string unidade;
}; 

#endif