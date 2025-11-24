#include "Professor.h"
#include <iostream>
#include <string>

using namespace std;

Professor::Professor(int nusp, string nome, string unidade)
    : Usuario(nusp, nome), unidade(unidade) {}

Professor::~Professor() {}

std::string Professor::getUnidade() {
    return unidade;
}

void Professor::imprimir() {
    cout << "Professor: " << getNome()
              << ", Unidade: " << unidade << endl;
}
