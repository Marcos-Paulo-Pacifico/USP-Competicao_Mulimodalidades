#ifndef TABELACOMPONTOS_H
#define TABELACOMPONTOS_H

#include <string>
#include <iostream>
#include <stdexcept>
#include "Tabela.h"

using namespace std;

class TabelaComPontos : public Tabela
{
    public:
        TabelaComPontos (Equipe** participantes, int quantidade);
        virtual ~TabelaComPontos();

        int getPontos (Equipe* participante);
        int getPosicao (Equipe* participante);
        void pontuar (Equipe* participante, int pontos);

        Equipe** getEquipesEmOrdem();
        void imprimir();

    protected:
        bool temPontos = false;
        int*pontuacoes;
        Equipe** ordemPontos;


};

#endif // TABELACOMPONTOS_H
