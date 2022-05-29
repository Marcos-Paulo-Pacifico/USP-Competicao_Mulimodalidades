#include "Tabela.h"
#include "Equipe.h"
#include "Modalidade.h"
#include "TabelaComOrdem.h"


using namespace std;

Tabela::Tabela(Equipe** participantes, int quantidade)
{
    this->participantes = participantes;
    this->quantidade = quantidade;

    if (quantidade < 2)
        throw new invalid_argument ("Quantidade de equipes invalida em tab");
}

Tabela::~Tabela()
{
    //destrutor de tabela
}


int Tabela::getQuantidadeDeEquipes()
{
    return this->quantidade;
}
