#include "TabelaComPontos.h"

TabelaComPontos::TabelaComPontos(Equipe** participantes, int quantidade) : Tabela (participantes, quantidade)
{
    ordemPontos = new Equipe*[quantidade];
    pontuacoes = new int [quantidade];
    for (int i = 0; i < quantidade ; i++) {
        pontuacoes[i]=0;
    }

    if (quantidade < 2)
        throw new invalid_argument ("Quantidade de equipes invalida em tabpontos");
}


TabelaComPontos::~TabelaComPontos()
{
    //dtor
}

int TabelaComPontos::getPosicao(Equipe* participante)
{
    int posicao = 1;
    int points = 0;

    if (!temPontos)
        throw new logic_error ("Pontuacao ainda nao definida");

        for (int i=0; i<quantidade; i++) {
            if (participante == participantes[i]) {
                points = pontuacoes[i];

                for (int j=0; j<quantidade; j++) {
                    if (points < pontuacoes[j])
                        posicao = posicao + 1;
                }
                return posicao;
            }

        }

    throw new invalid_argument ("Equipe nao eh participante");

}


int TabelaComPontos::getPontos(Equipe* participante)
{


    for (int i = 0; i < quantidade; i++) {
        if (participante == participantes[i]) {
            return pontuacoes[i];
         }
    }

        throw new invalid_argument ("Equipe nao e participanteeeee");
}

void TabelaComPontos::pontuar(Equipe* participante, int pontos)
{
    bool ehParticipante = false;

    for (int i = 0; i < quantidade; i++)
        if (participante == participantes[i]) {
            pontuacoes[i] = pontuacoes[i] + pontos;
            temPontos = true;
            ehParticipante = true;
        }
    if(!ehParticipante)
        throw new invalid_argument ("Equipe nao eh participante");
}


Equipe** TabelaComPontos::getEquipesEmOrdem()
{
int posicaoDesejada = 1;
int i =0;
bool encontrou;

while(i<quantidade)
{
    encontrou = false;
    for(int j = 0;j<quantidade&&encontrou == false;j++)
    {
        if(getPosicao(participantes[j])==posicaoDesejada)
        {
        ordemPontos[posicaoDesejada-1] = participantes[j];
        encontrou = true;

        for(int k = 0;k<quantidade;k++)
        {
            if(getPosicao(participantes[k])==getPosicao(participantes[j]))
                ordemPontos[posicaoDesejada] = participantes[k];
        }

        posicaoDesejada++;
        }
    }
    i++;
}

return ordemPontos;

}

void TabelaComPontos::imprimir()
{
    Equipe**resultado = getEquipesEmOrdem();

    if(!temPontos)
        for(int i = 0;i<quantidade;i++)
            cout<<"\t"<<participantes[i]->getNome()<<endl;
    else
        for(int j = 0;j<quantidade;j++)
            cout<<"\t"<<getPosicao(resultado[j])<<"o "<<resultado[j]->getNome()<<" ("<<getPontos(resultado[j])<<"pontos)"<<endl;
}
