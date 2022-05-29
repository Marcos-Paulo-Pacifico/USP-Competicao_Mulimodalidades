#include "CompeticaoSimples.h"


CompeticaoSimples::CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m):
Competicao(nome,equipes, quantidade)
{


this->m = m;

}

CompeticaoSimples::~CompeticaoSimples()
{
    //dtor
}

Modalidade* CompeticaoSimples::getModalidade()
{
    return m;
}

Tabela* CompeticaoSimples::getTabela()
{
    return m->getTabela();
}

void CompeticaoSimples::imprimir()
{
    cout<<getNome()<<endl;

    getTabela()->imprimir();

}
