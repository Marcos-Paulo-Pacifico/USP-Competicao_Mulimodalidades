#ifndef PERSISTENCIADECOMPETICAO_H
#define PERSISTENCIADECOMPETICAO_H

#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "Competicao.h"
#include"CompeticaoMultimodalidades.h"
#include"CompeticaoSimples.h"
#include "TabelaComOrdem.h"
#include "TabelaComPontos.h"

#include<stdexcept>
#include<iostream>
#include<string>
#include<list>
#include<vector>
#include <fstream>

using namespace std;

class PersistenciaDeCompeticao
{
    public:

        PersistenciaDeCompeticao();
        virtual ~PersistenciaDeCompeticao();

        Competicao* carregar(string arquivo);
        void salvar(string arquivo, Competicao* c);

    private:
};

#endif // PERSISTENCIADECOMPETICAO_H
