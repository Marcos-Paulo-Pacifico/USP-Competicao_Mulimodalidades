#include "TabelaComOrdem.h"

TabelaComOrdem::TabelaComOrdem(Equipe** participantes, int quantidade) : Tabela(participantes, quantidade)
{

    ordem = new Equipe*[quantidade];
    if (quantidade < 2)
        throw new invalid_argument ("Quantidade de equipes invalida em tabordem");

}

TabelaComOrdem::~TabelaComOrdem()
{
    for (int i=0; i < quantidade; i++)
        delete ordem[i];
    delete [] ordem;
}

int TabelaComOrdem::getPosicao(Equipe* participante)
{
    int posicao = 0;

    if (!temResultado)
        throw new logic_error ("Resultado ainda nao definido");

    for (int i=0; i < quantidade; i++) {
        posicao++;
        if (participante == ordem[i])
            return posicao;
    }

    throw new invalid_argument ("Equipe nao eh participante");

}

void TabelaComOrdem::setResultado(Equipe** ordem)
{
    this->ordem = ordem;
    temResultado = true;
}


Equipe** TabelaComOrdem::getEquipesEmOrdem()
{
    if(!temResultado)throw new logic_error("Nao tem resultado");
    return this->ordem;
}

void TabelaComOrdem::imprimir()
{
    if(!temResultado)
        for(int i = 0;i<quantidade;i++)
            cout<<"\t"<<participantes[i]->getNome()<<endl;
    else
        for(int j = 0;j<quantidade;j++)
            cout<<"\t"<<j+1<<"o "<<getEquipesEmOrdem()[j]->getNome()<<endl;
}
