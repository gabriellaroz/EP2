#include "PersistenciaDeUsuario.h"

PersistenciaDeUsuario::PersistenciaDeUsuario() {}

PersistenciaDeUsuario::~PersistenciaDeUsuario(){}

list<Usuario*>* PersistenciaDeUsuario::carregar(string arquivoProfessor, string arquivoAluno) {
    ifstream input;
    input.open(arquivoProfessor);

    int nusp;
    input >> nusp;
    string nome;
    input >> nome;
}