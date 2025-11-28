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

    PersistenciaDeUsuario* carregarSalvos = new PersistenciaDeUsuario();

    GerenciadorDeUsuario* gerenciador = new GerenciadorDeUsuario();
    list<Usuario*>* listaGerenciador = gerenciador->getUsuarios();

    list<Usuario*>* listaCarregada = carregarSalvos->carregar("professores.txt", "alunos.txt");

    list<Usuario*>::iterator i = listaCarregada->begin();

    while(i != listaCarregada->end()) {
        gerenciador->adicionar((*i));
        i++;
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
        } else if (opcao == 2) {
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
        } else if (opcao == 3) {
            
            cout << "Cadastro de Bolsa" << endl
                << "Alunos" << endl;
            
            list<Usuario*>::iterator i = listaGerenciador->begin();

            while(i != listaGerenciador->end()) {
                Aluno* ehAluno = dynamic_cast<Aluno*>((*i));
                if(ehAluno != nullptr) {
                    cout << (*i)->getNusp() << " - " << (*i)->getNome() << endl;
                }
                i++;
            }

            cout << "Digite o NUSP do aluno: ";
            cin >> nuspBolsa;

            gerenciador->getUsuario(nuspBolsa);

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

                BolsaPeeg* peeg = new BolsaPeeg(new Data(mesInicio, anoInicio), new Data(mesFim, anoFim), disciplina);
                Usuario* usuario = gerenciador->getUsuario(nuspBolsa);
                Aluno* alunoPeeg = dynamic_cast<Aluno*>(usuario);
                alunoPeeg->adicionar(peeg);

                cout << "Bolsa cadastrada com sucesso" << endl;
            } else {
                cout << "Digite o mes e ano de inicio: ";
                cin >> mesInicio >> anoInicio;
                cout << "Professores" << endl;

                Data* inicio = new Data(mesInicio, anoInicio);

                list<Usuario*>::iterator i = listaGerenciador->begin();

                while(i != listaGerenciador->end()) {
                    Professor* professor = dynamic_cast<Professor*>((*i));
                    if(professor != nullptr) {
                        cout << professor->getNome() << " - " << professor->getNome() << " - " << professor->getUnidade() << endl;
                    }
                i++;
                }

                cout << "Digite o NUSP do professor: ";
                cin >> nusp;

                Usuario* profBolsas = gerenciador->getUsuario(nusp);
                Professor* ehProfessor = dynamic_cast<Professor*>(profBolsas);

                if(profBolsas != nullptr) {
                    Usuario* usuario = gerenciador->getUsuario(nuspBolsa);
                    Aluno* alunoPubPibic = dynamic_cast<Aluno*>(usuario);
                    if(tipoBolsa == 2) {
                        BolsaPub* pub = new BolsaPub(inicio, ehProfessor);
                        alunoPubPibic->adicionar(pub);

                    } else {
                        BolsaPibic* pibic = new BolsaPibic(inicio, ehProfessor);
                        alunoPubPibic->adicionar(pibic);
                    }

                    cout << "Bolsa cadastrada com sucesso" << endl;
                } else {
                    cout << "Professor inexistente" << endl;
                }
            }
        } else if (opcao == 4) {
            cout << "Consulta de usuario" << endl
                << "Digite o NUSP: ";
            cin >> nusp;

            Usuario* consulta = gerenciador->getUsuario(nusp);

            if(consulta == nullptr) {
                cout << "Usuario nao encontrado" << endl;
            }
        }
    }    
}