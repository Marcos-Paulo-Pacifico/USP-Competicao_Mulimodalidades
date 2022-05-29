#include "Modalidade.h"
#include "Equipe.h"

#include <iostream>
#include <string>

using namespace std;

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade)
{

    this->nome = nome;
    this->participantes = participantes;
    this->quantidade=quantidade;
    tabOrdem = new TabelaComOrdem(participantes, quantidade);
    resultado = false;

    if(quantidade<2)throw new invalid_argument("Quantidade de equipes invalida em mod");



}

Modalidade::~Modalidade()
{

}

string Modalidade::getNome()
{
    return this->nome;
}

Equipe** Modalidade::getEquipes()
{
    return this->participantes;
}

int Modalidade::getQuantidadeDeEquipes()
{
    return this->quantidade;
}

void Modalidade::setResultado(Equipe** ordem)
{
    tabOrdem->setResultado(ordem);
    resultado = true;
}

bool Modalidade::temResultado()
{
    return resultado;
}

TabelaComOrdem* Modalidade::getTabela()
{
    return tabOrdem;
}

void Modalidade::imprimir()
{
    cout<<"Modalidade: "<<nome<<endl;
    getTabela()->imprimir();


}
