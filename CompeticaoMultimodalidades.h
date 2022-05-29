#ifndef COMPETICAOMULTIMODALIDADES_H
#define COMPETICAOMULTIMODALIDADES_H

#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "Competicao.h"
#include "TabelaComOrdem.h"
#include "TabelaComPontos.h"

#include<stdexcept>
#include<iostream>
#include<string>
#include<list>
#include<vector>

using namespace std;

class CompeticaoMultimodalidades:public Competicao
{
    public:
        CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade);
        virtual ~CompeticaoMultimodalidades();

        void adicionar(Modalidade* m);
        list<Modalidade*>* getModalidades();

        static void setPontuacao(vector<int>* pontos);
        static int getPontoPorPosicao(int posicao);
        Tabela* getTabela();

        void imprimir();

    private:

        list<Modalidade*>* modalidades;
        static vector<int>* pontuacao;
        static vector<int>* auxiliar;
};

#endif // COMPETICAOMULTIMODALIDADES_H
