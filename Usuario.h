#ifndef USUARIO_H
#define USUARIO_H 
#include <string>
using namespace std;

class Usuario {
public: 
    Usuario(int nusp, string nome); 
    virtual ~Usuario(); 
    string getNome(); 
    int getNusp(); 
    virtual void imprimir() = 0; // ele diz no enunciado que o metodo void imprimir deve ser virtual
   
private:
    int nusp;
    string nome;
};
#endif