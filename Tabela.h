#ifndef TABELA_H
#define TABELA_H

#include "Equipe.h"
//#include "Modalidade.h"

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Tabela
{
    public:
        Tabela (Equipe** participantes, int quantidade);
        virtual ~Tabela();

        virtual int getPosicao (Equipe* participante) = 0;
        virtual Equipe** getEquipesEmOrdem() = 0;
        virtual int getQuantidadeDeEquipes();
        virtual void imprimir() = 0;


    protected:
        Equipe** participantes;
        int quantidade;

};

#endif // TABELA_H
