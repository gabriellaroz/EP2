#ifndef GERENCIADOR_DE_USUARIO_H
#define GERENCIADOR_DE_USUARIO_H
#include <list>
#include "Usuario.h"

using namespace std;

class GerenciadorDeUsuario {
private:
    Usuario* usuario;
public:
    GerenciadorDeUsuario();
    GerenciadorDeUsuario(list<Usuario*>* usuarios);
    virtual ~GerenciadorDeUsuario();

    void adicionar(Usuario* u);

    list<Usuario*>* getUsuarios();
    Usuario* getUsuario(int nusp);

};

#endif