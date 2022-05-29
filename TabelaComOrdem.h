#ifndef TABELACOMORDEM_H
#define TABELACOMORDEM_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "Tabela.h"

using namespace std;

class TabelaComOrdem : public Tabela
{
    public:
        TabelaComOrdem (Equipe** participantes, int quantidade);
        virtual ~TabelaComOrdem();

        int getPosicao (Equipe* participante);
        void setResultado (Equipe** ordem);

        Equipe** getEquipesEmOrdem();
        void imprimir();

    protected:
        Equipe** ordem;
        bool temResultado = false;

};

#endif // TABELACOMORDEM_H
