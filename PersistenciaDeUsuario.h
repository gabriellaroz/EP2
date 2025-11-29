#ifndef PERSISTENCIA_DE_USUARIO_H
#define PERSISTENCIA_DE_USUARIO_H

#include <list>
#include <string>
#include "Usuario.h"

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
