#ifndef COMPETICAO_H
#define COMPETICAO_H

#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"

#include<stdexcept>
#include<iostream>
#include<string>

using namespace std;


class Competicao
{
    public:
        Competicao(string nome, Equipe** equipes, int quantidade);
        virtual ~Competicao();

        string getNome();
        Equipe** getEquipes();
        int getQuantidadeDeEquipes();
        virtual Tabela* getTabela() = 0;

        virtual void imprimir() = 0;

    protected:
        string nome;
        Equipe** equipes;
        int quantidade;


};

#endif // COMPETICAO_H
