#include "CompeticaoMultimodalidades.h"

vector<int>* CompeticaoMultimodalidades:: pontuacao = new vector<int>({13, 10, 8, 7, 5, 4, 3, 2, 1});
vector<int>* CompeticaoMultimodalidades:: auxiliar = new vector<int>();

CompeticaoMultimodalidades::CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade):
Competicao(nome,equipes,quantidade)
{

    modalidades = new list<Modalidade*>();

    auxiliar = new vector<int>();
}

CompeticaoMultimodalidades::~CompeticaoMultimodalidades()
{
    //dtor
}

void CompeticaoMultimodalidades::adicionar(Modalidade* m)
{
    modalidades->push_front(m);
}

list<Modalidade*>* CompeticaoMultimodalidades::getModalidades()
{
    return modalidades;
}

void CompeticaoMultimodalidades::setPontuacao(vector<int>* pontos)
{

   if(pontos->size()<3)throw new invalid_argument("Numero de elementos insuficiente");



    for(unsigned int i = 0;i<pontuacao->size();i++)
    {
        pontuacao->pop_back();
    }

   for(unsigned int i = 0;i<pontos->size();i++)
    {
        int ultimo;
        ultimo = pontos->back();
        pontos->pop_back();
        auxiliar->push_back(ultimo);
    }

    for(unsigned int i = 0;i<auxiliar->size();i++)
    {
        int ultimo;
        ultimo = auxiliar->back();
        auxiliar->pop_back();
        pontuacao->push_back(ultimo);
    }
}

int CompeticaoMultimodalidades::getPontoPorPosicao(int posicao)
{
    if(posicao<=0||posicao>pontuacao->size()) return 0;

    return pontuacao->at(posicao-1);
}

Tabela* CompeticaoMultimodalidades::getTabela()
{


    if(modalidades->empty())throw new invalid_argument("Sem modalidades adicionadas");

    TabelaComPontos* tabPontos = new TabelaComPontos(equipes,quantidade);


    list<Modalidade*>::iterator i = modalidades->begin();

    while(i != modalidades->end())
    {
        if((*i)->temResultado())
        {
            for(int j = 0;j<quantidade;j++)
            {
                tabPontos->pontuar(equipes[j],getPontoPorPosicao((*i)->getTabela()->getPosicao(equipes[j])));
            }
        }
        i++;
    }

    return tabPontos;
}
void CompeticaoMultimodalidades::imprimir()
{
        TabelaComPontos* tabelinha = dynamic_cast<TabelaComPontos*>(getTabela());
        cout<<getNome()<<endl;
        tabelinha->imprimir();
}


