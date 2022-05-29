#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "Competicao.h"
#include "TabelaComOrdem.h"
#include "TabelaComPontos.h"
#include "CompeticaoMultimodalidades.h"
#include "CompeticaoSimples.h"
#include "PersistenciaDeCompeticao.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int quantidadequipes;
    int quantidadeModalidades;
    int posicao = 0;
    int numEquipe;
    string nomeEquipe;
    string nomeModalidade;
    string nomeCompeticao;
    string carregarCompeticao;
    string tipoCompeticao;
    string temResultado;
    string salvarCompeticao;
    string nomeArquivo;

    try {

    cout << "Deseja carregar uma competicao? " ;
    cin >> carregarCompeticao ;

    if (carregarCompeticao == "n") {

        cout << "\n\n" << "Informe a quantidade de equipes: ";
        cin >> quantidadequipes ;

        Equipe** participantes = new Equipe*[quantidadequipes];

        for (int i=0; i<quantidadequipes; i++){
            cout << "Informe o nome da equipe " << i+1 << ": " ;
            cin >> nomeEquipe;
            Equipe* equipe = new Equipe(nomeEquipe);
            participantes[i] = equipe;
        }

        cout << "\n" << "Informe o nome da competicao: ";
        cin >> nomeCompeticao;

        cout << "Competicao simple (s) ou multimodalidades (m) ?: ";
        cin >> tipoCompeticao;

        if (tipoCompeticao == "s") {
            cout << "\n" << "Informe o nome da modalidade: ";
            cin >> nomeModalidade;
            Modalidade* modalidade = new Modalidade(nomeModalidade, participantes, quantidadequipes);
            CompeticaoSimples* competicaoSimples = new CompeticaoSimples(nomeCompeticao, participantes, quantidadequipes, modalidade);
            cout << "Tem resultado (s/n): ";
            cin >> temResultado;
            if (temResultado == "s") {
                Equipe** ordem = new Equipe*[quantidadequipes];
                cout << "\n";
                for (int j=0; j<quantidadequipes; j++) {
                    cout <<"Informe a equipe " << j+1 << "a colocada: ";
                    cin >> numEquipe;
                    ordem[j] = participantes[numEquipe - 1];
                }
                modalidade->setResultado(ordem);
            }

                cout <<"\n"<<"Deseja salvar a competicao (s/n)? ";
                cin >> salvarCompeticao;

                if (salvarCompeticao == "s") {
                    cout << "\n" << "Digite o nome do arquivo: ";
                    cin >> nomeArquivo;
                    PersistenciaDeCompeticao*p = new PersistenciaDeCompeticao;
                    p->salvar(nomeArquivo, competicaoSimples);
                    competicaoSimples->imprimir();
                }
                else
                    competicaoSimples->imprimir();
        }

        else {
            cout << "\n" << "Informe a quantidade de modalidades: ";
            cin >> quantidadeModalidades;

            CompeticaoMultimodalidades* competicaoMulti = new CompeticaoMultimodalidades(nomeCompeticao, participantes, quantidadequipes);

            Modalidade**modalidades = new Modalidade*[quantidadeModalidades];
            for (int i=0; i<quantidadeModalidades; i++) {
                cout <<  "\n" << "Informe o nome da modalidade " << i+1 << ": ";
                cin >> nomeModalidade;
                Modalidade* modalidade = new Modalidade(nomeModalidade,participantes,quantidadequipes);
                modalidades[i] = modalidade;
                cout << "Tem resultado (s/n): ";
                cin >> temResultado;
                if (temResultado == "s"){
                    Equipe** ordem = new Equipe*[quantidadequipes];
                    for (int j=0; j<quantidadequipes; j++){
                        cout << "Informe a equipe " << j+1 << "a colocada: ";
                        cin >> posicao;
                        ordem[j] = participantes[posicao - 1];
                    }
                    modalidades[i]->setResultado(ordem);
                }

               competicaoMulti->adicionar(modalidades[i]);
            }
            cout <<"\n"<<"Deseja salvar a competicao (s/n)? ";
            cin >> salvarCompeticao;

            if (salvarCompeticao == "s") {
                cout << "\n" << "Digite o nome do arquivo: ";
                cin >> nomeArquivo;
                cout<<"\n";
                PersistenciaDeCompeticao*p = new PersistenciaDeCompeticao;
                p->salvar(nomeArquivo, competicaoMulti);
                competicaoMulti->imprimir();
            }
            else{
                cout<<"\n";
                competicaoMulti->imprimir();
            }
        }




    } else {
        cout<<"\nDigite o nome do arquivo: ";
        cin>>nomeArquivo;


        PersistenciaDeCompeticao* p = new PersistenciaDeCompeticao();
        p->carregar(nomeArquivo)->imprimir();

    }


    } catch (invalid_argument*e)
    {
        cout<<"\n Erro: "<<e->what();
        delete e;
    }catch (logic_error*e)
    {
        cout<<"\n Erro: "<<e->what();
        delete e;
    }

    return 0;
}
