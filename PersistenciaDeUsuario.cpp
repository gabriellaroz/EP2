#include "PersistenciaDeUsuario.h"

PersistenciaDeUsuario::PersistenciaDeUsuario() {}

PersistenciaDeUsuario::~PersistenciaDeUsuario(){}

list<Usuario*>* PersistenciaDeUsuario::carregar(string arquivoProfessor, string arquivoAluno) {
    ifstream input;
    input.open(arquivoProfessor);

    int nusp;
    string nome, departamento;

    while(input) {    
        input >> nusp;
        input >> nome;
        input >> departamento;
        usuarios->push_back(new Professor(nusp, nome, departamento));
    }

    if(!input.eof()) {
        throw new logic_error("Erro de leitura");
    }

    input.close();

    input.open(arquivoAluno);

    if(input.fail()) {
        throw new logic_error("Aequivo nao encontrado");
    }

    while(input) {
        input >> nusp;
        input >> nome;
        usuarios->push_back(new Aluno(nusp, nome));
    }

    if(!input.eof()) {
        throw new logic_error("Erro de leitura");
    }

    input.close();

    return usuarios;

}

void PersistenciaDeUsuario::salvar(string arquivoProfessor, string arquivoAluno, list<Usuario*>* usuarios) {
    ofstream output;
    output.open(arquivoProfessor);

    if(output.fail()) {
        throw new logic_error("Erro ao escrever");
    } else { 
        list<Usuario*>::iterator i = usuarios->begin();
        while(i != usuarios->end()) {
            Professor* prof = dynamic_cast<Professor*>((*i));
            if(prof != nullptr) {
                output << prof->getNusp() << " " << prof->getNome() << " " << prof->getUnidade() << endl;
            }
        }
    }    

    output.close();

    output.open(arquivoAluno);

    if(output.fail()) {
        throw new logic_error("Erro ao escrever");
    } else {
        list<Usuario*>::iterator i = usuarios->begin();
        while(i != usuarios->end()) {
            Aluno* aluno = dynamic_cast<Aluno*>((*i));
            if(aluno != nullptr) {
                output << aluno->getNusp() << " " << aluno->getNome() << endl;
            }
        }
    }

    output.close();

}