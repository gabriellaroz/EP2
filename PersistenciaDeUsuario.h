#include <iostream>
#include <fstream>
#include <list>
#include <stdexcept>

#include "Usuario.h"
#include "Professor.h"
#include "Aluno.h"

#ifndef PERSISTENCIA_DE_USUARIO_H
#define PERSISTENCIA_DE_USUARIO_H

using namespace std;

class PersistenciaDeUsuario {
public:
    PersistenciaDeUsuario();
    virtual ~PersistenciaDeUsuario();

    list<Usuario*>* carregar(string arquivoProfessor, string arquivoAluno);
    void salvar(string arquivoProfessor, string arquivoAluno, list<Usuario*>* usuarios);
private:
    list<Usuario*>* usuarios;
};

#endif