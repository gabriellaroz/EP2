#include "GerenciadorDeUsuario.h"

GerenciadorDeUsuario::GerenciadorDeUsuario() {  //cria uma lista de usuarios
    list<Usuario*>* usuarios = new list<Usuario*>();
}

GerenciadorDeUsuario::GerenciadorDeUsuario(list<Usuario*>* usuarios) {  //recebe lista de usuarios existente
    this->usuarios = usuarios;
}

GerenciadorDeUsuario::~GerenciadorDeUsuario() {  //apaga cada item da lista e dps a lista
    list<Usuario*>::iterator i = usuarios->begin();

    while(i != usuarios->end()) {
        usuarios->pop_back();
        i++;
    }

    delete usuarios;
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

    return nullptr;  //usuario nao encontrado, retorno nulo
}