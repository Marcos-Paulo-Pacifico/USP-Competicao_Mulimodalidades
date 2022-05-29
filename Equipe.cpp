#include <iostream>
#include <string>

#include "Equipe.h"

using namespace std;

Equipe::Equipe(string nome)
{
    this->nome = nome;
}

Equipe::~Equipe()
{

}

string Equipe::getNome()
{
    return this->nome;
}

void Equipe::imprimir()
{
    cout << "Equipe " <<  getNome() << endl;
}
