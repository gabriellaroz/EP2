#ifndef GERENCIADOR_DE_USUARIO_H
#define GERENCIADOR_DE_USUARIO_H
#include <list>
#include "Usuario.h"
#include <stdexcept>

using namespace std;

class GerenciadorDeUsuario {
private:
    list<Usuario*>* usuarios;
public:
    GerenciadorDeUsuario();
    GerenciadorDeUsuario(list<Usuario*>* usuarios);
    virtual ~GerenciadorDeUsuario();

    void adicionar(Usuario* u);

    list<Usuario*>* getUsuarios();
    Usuario* getUsuario(int nusp);

};

#endif