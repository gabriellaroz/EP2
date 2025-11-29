#include "GerenciadorDeUsuario.h"

GerenciadorDeUsuario::GerenciadorDeUsuario() {
    
    this->usuarios = new list<Usuario*>();
}

GerenciadorDeUsuario::GerenciadorDeUsuario(list<Usuario*>* usuarios) {
    this->usuarios = usuarios;
}

GerenciadorDeUsuario::~GerenciadorDeUsuario() {
    if (usuarios != nullptr) {
        list<Usuario*>::iterator i = usuarios->begin();
        while(i != usuarios->end()) {
            delete *i;
            i++;
        }
        delete usuarios;
        usuarios = nullptr;
    }
}

void GerenciadorDeUsuario::adicionar(Usuario* u) {
    list<Usuario*>::iterator i = usuarios->begin();

    while(i != usuarios->end()) {
        if(u->getNusp() == (*i)->getNusp()) {
            throw new logic_error("Usuario existente");
        }
        i++;
    }

    usuarios->push_back(u);
}

list<Usuario*>* GerenciadorDeUsuario::getUsuarios() {
    return usuarios;
}

Usuario* GerenciadorDeUsuario::getUsuario(int nusp) {
    list<Usuario*>::iterator i = usuarios->begin();

    while(i != usuarios->end()) {
        if((*i)->getNusp() == nusp) {
            return *i;
        }
        i++;
    }

    return nullptr;
}
