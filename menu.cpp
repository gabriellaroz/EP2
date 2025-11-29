#include <iostream>
#include <string>
#include "Aluno.h"
#include "Professor.h"
#include "GerenciadorDeUsuario.h"
#include "BolsaPeeg.h"
#include "BolsaPub.h"
#include "BolsaPibic.h"
#include "PersistenciaDeUsuario.h"

using namespace std;

void menu() {
    int opcao = 6;
    int nusp, nuspBolsa, tipoBolsa, mesInicio, anoInicio, mesFim, anoFim;
    string nome, unidade, disciplina;

    PersistenciaDeUsuario* carregarSalvar = new PersistenciaDeUsuario();
    GerenciadorDeUsuario* gerenciador = new GerenciadorDeUsuario();
    list<Usuario*>* listaGerenciador = gerenciador->getUsuarios();

    list<Usuario*>* listaCarregada = carregarSalvar->carregar("professores.txt", "alunos.txt");

    list<Usuario*>::iterator it = listaCarregada->begin();
    while(it != listaCarregada->end()) {
        gerenciador->adicionar(*it);
        it++;
    }

    if(listaGerenciador->size() != 0) {
        cout << listaGerenciador->size() << " usuarios carregados" << endl;
    }

    while(opcao != 0) {
        cout << "Gestao de bolsas USP" << endl
            << "1) Adicionar aluno" << endl
            << "2) Adicionar professor" << endl
            << "3) Cadastrar bolsa" << endl
            << "4) Consultar usuario" << endl
            << "5) Consultar valor" << endl
            << "0) Sair" << endl
            << "Escolha uma opcao: ";
        cin >> opcao;

        if(opcao == 1) {

            cout << "Cadastro de Aluno" << endl
                << "Digite o NUSP: ";
            cin >> nusp;
            cout << "Digite o nome: ";
            cin >> nome;

            Aluno* aluno = new Aluno(nusp, nome);
            gerenciador->adicionar(aluno);

            cout << "Aluno adicionado com sucesso" << endl;
        }

        else if (opcao == 2) {

            cout << "Cadastro de Professor" << endl
                << "Digite o NUSP: ";
            cin >> nusp;
            cout << "Digite o nome: ";
            cin >> nome;
            cout << "Digite a unidade: ";
            cin >> unidade;

            Professor* professor = new Professor(nusp, nome, unidade);
            gerenciador->adicionar(professor);

            cout << "Professor adicionado com sucesso" << endl;
        }

        else if (opcao == 3) {

            cout << "Cadastro de Bolsa" << endl
                << "Alunos" << endl;
            
            list<Usuario*>::iterator ia = listaGerenciador->begin();
            while(ia != listaGerenciador->end()) {
                Aluno* ehAluno = dynamic_cast<Aluno*>(*ia);
                if(ehAluno != nullptr) {
                    cout << ehAluno->getNusp() << " - " << ehAluno->getNome() << endl;
                }
                ia++;
            }

            cout << "Digite o NUSP do aluno: ";
            cin >> nuspBolsa;

            Usuario* usuarioBolsa = gerenciador->getUsuario(nuspBolsa);
            if(usuarioBolsa == nullptr || dynamic_cast<Aluno*>(usuarioBolsa) == nullptr) {
                cout << "Aluno inexistente" << endl;
                continue;
            }

            cout << "Tipo da bolsa" << endl
                << "1) PEEG" << endl
                << "2) PUB" << endl
                << "3) PIBIC" << endl
                << "Digite a opcao: ";
            cin >> tipoBolsa;

            if(tipoBolsa == 1) {

                cout << "Digite o mes e ano de inicio: ";
                cin >> mesInicio >> anoInicio;
                cout << "Digite o mes e ano de fim: ";
                cin >> mesFim >> anoFim;
                cout << "Digite o codigo da disciplina: ";
                cin >> disciplina;

                BolsaPeeg* peeg = new BolsaPeeg(
                    new Data(mesInicio, anoInicio),
                    new Data(mesFim, anoFim),
                    disciplina
                );

                Aluno* alunoPeeg = dynamic_cast<Aluno*>(usuarioBolsa);
                alunoPeeg->adicionar(peeg);

                cout << "Bolsa cadastrada com sucesso" << endl;
            }

            else {

                cout << "Digite o mes e ano de inicio: ";
                cin >> mesInicio >> anoInicio;

                Data* inicio = new Data(mesInicio, anoInicio);

                cout << "Professores" << endl;

                list<Usuario*>::iterator ip = listaGerenciador->begin();
                while(ip != listaGerenciador->end()) {
                    Professor* professor = dynamic_cast<Professor*>(*ip);
                    if(professor != nullptr) {
                        cout << professor->getNusp() << " - "
                             << professor->getNome() << " - "
                             << professor->getUnidade() << endl;
                    }
                    ip++;
                }

                cout << "Digite o NUSP do professor: ";
                cin >> nusp;

                Usuario* responsavel = gerenciador->getUsuario(nusp);
                Professor* ehProfessor = dynamic_cast<Professor*>(responsavel);

                if(ehProfessor == nullptr) {
                    cout << "Professor inexistente" << endl;
                } 
                else {
                    Aluno* aluno = dynamic_cast<Aluno*>(usuarioBolsa);

                    if(tipoBolsa == 2) {
                        BolsaPub* pub = new BolsaPub(inicio, ehProfessor);
                        aluno->adicionar(pub);
                    } else {
                        BolsaPibic* pibic = new BolsaPibic(inicio, ehProfessor);
                        aluno->adicionar(pibic);
                    }

                    cout << "Bolsa cadastrada com sucesso" << endl;
                }
            }
        }

        else if (opcao == 4) {

            cout << "Consulta de usuario" << endl
                << "Digite o NUSP: ";
            cin >> nusp;

            Usuario* consulta = gerenciador->getUsuario(nusp);

            if(consulta == nullptr) {
                cout << "Usuario nao encontrado" << endl;
            } else if(dynamic_cast<Professor*>(consulta) != nullptr) {
                dynamic_cast<Professor*>(consulta)->imprimir();
            } else {
                dynamic_cast<Aluno*>(consulta)->imprimir();
            }
        }

        else if (opcao == 5) {

            cout << "Digite o NUSP do aluno: ";
            cin >> nusp;

            Usuario* alunoConsulta = gerenciador->getUsuario(nusp);

            if(alunoConsulta == nullptr) {
                cout << "Aluno inexistente" << endl;
            } else {
                cout << "Digite o mes e o ano para consulta: ";
                cin >> mesInicio >> anoInicio;

                Aluno* aluno = dynamic_cast<Aluno*>(alunoConsulta);
                double valor = aluno->getValor(new Data(mesInicio, anoInicio));

                cout << "Valor recebido: R$" << valor << endl;
            }
        }

        else if (opcao == 0) {

            string salvar;

            cout << "Deseja salvar: ";
            cin >> salvar;

            if(salvar == "s") {
                carregarSalvar->salvar("professores.txt", "alunos.txt", listaGerenciador);
                cout << listaGerenciador->size() << " usuarios salvos" << endl;
            }
        }
    }
}
