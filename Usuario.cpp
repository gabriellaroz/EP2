#include "Usuario.h"

Usuario::Usuario(int nusp, string nome) : 
nusp(nusp), nome(nome){}

Usuario::~Usuario(){}

string Usuario::getNome(){
    return nome;
}

int Usuario::getNusp(){
    return nusp;
}