#include "Competicao.h"
#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"

#include <iostream>
#include <string>

using namespace std;

Competicao::Competicao(string nome, Equipe** equipes, int quantidade)
{
    this->nome = nome;
    this->equipes = equipes;
    this->quantidade = quantidade;

    if(quantidade<2)throw new invalid_argument("Quantidade de equipes invalida em comp");

}

Competicao::~Competicao()
{

}

string Competicao::getNome()
{
    return this->nome;
}

Equipe** Competicao::getEquipes()
{
    return this->equipes;
}

int Competicao::getQuantidadeDeEquipes()
{
    return this->quantidade;
}





