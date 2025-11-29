#include "PersistenciaDeUsuario.h"
#include "Professor.h"
#include "Aluno.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

PersistenciaDeUsuario::PersistenciaDeUsuario() {
    this->usuarios = new list<Usuario*>();
}

PersistenciaDeUsuario::~PersistenciaDeUsuario() {
    if (usuarios != nullptr) {
        list<Usuario*>::iterator it = usuarios->begin();
        while(it != usuarios->end()) {
            delete *it;
            it++;
        }
        delete usuarios;
        usuarios = nullptr;
    }
}

list<Usuario*>* PersistenciaDeUsuario::carregar(string arquivoProfessor, string arquivoAluno) {
    // limpa lista interna caso existam dados antigos
    usuarios->clear();

    ifstream input;
    input.open(arquivoProfessor);
    if (input.fail()) {
        // arquivo pode existir vazio: apenas retorne lista vazia
        // se quiser forçar erro, jogue logic_error; aqui seguimos enunciado (assumir que existe)
    } else {
        int nusp;
        string nome, departamento;
        // ler enquanto conseguir extrair os três campos
        while (input >> nusp >> nome >> departamento) {
            usuarios->push_back(new Professor(nusp, nome, departamento));
        }
        // se houve falha diferente de eof, lançar erro
        if (!input.eof() && input.fail()) {
            throw new logic_error("Erro de leitura do arquivo de professores");
        }
        input.close();
    }

    input.open(arquivoAluno);
    if (input.fail()) {
        // idem: se precisar forçar erro, lançar
    } else {
        int nusp;
        string nome;
        while (input >> nusp >> nome) {
            usuarios->push_back(new Aluno(nusp, nome));
        }
        if (!input.eof() && input.fail()) {
            throw new logic_error("Erro de leitura do arquivo de alunos");
        }
        input.close();
    }

    return usuarios;
}

void PersistenciaDeUsuario::salvar(string arquivoProfessor, string arquivoAluno, list<Usuario*>* usuarios) {
    ofstream output;
    // salva professores
    output.open(arquivoProfessor);
    if(output.fail()) {
        throw new logic_error("Erro ao escrever arquivo de professores");
    } else {
        list<Usuario*>::iterator i = usuarios->begin();
        while(i != usuarios->end()) {
            Professor* prof = dynamic_cast<Professor*>((*i));
            if(prof != nullptr) {
                output << prof->getNusp() << " " << prof->getNome() << " " << prof->getUnidade() << endl;
            }
            i++; // <<-- NÃO ESQUECER
        }
    }
    output.close();

    // salva alunos
    output.open(arquivoAluno);
    if(output.fail()) {
        throw new logic_error("Erro ao escrever arquivo de alunos");
    } else {
        list<Usuario*>::iterator i = usuarios->begin();
        while(i != usuarios->end()) {
            Aluno* aluno = dynamic_cast<Aluno*>((*i));
            if(aluno != nullptr) {
                output << aluno->getNusp() << " " << aluno->getNome() << endl;
            }
            i++; // <<-- NÃO ESQUECER
        }
    }
    output.close();
}
