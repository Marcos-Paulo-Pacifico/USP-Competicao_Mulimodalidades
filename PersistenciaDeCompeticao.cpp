#include "PersistenciaDeCompeticao.h"

PersistenciaDeCompeticao::PersistenciaDeCompeticao()
{
    //ctor
}

PersistenciaDeCompeticao::~PersistenciaDeCompeticao()
{
    //dtor
}
Competicao* PersistenciaDeCompeticao::carregar(string arquivo)
{

    ifstream input;
    input.open(arquivo);

    int quantidadeEquipes = 0;
    int tipoCompeticao = 0;
    int temResultado = 0;
    int quantidadePart  = 0;
    int quantidadeModalidades = 0;
    string nomeEquipe;
    string nomeCompeticao;
    string nomeModalidade;
    string nome;


//    if (filho != NULL){

    if (input.fail())
        throw new invalid_argument ("\n Arquivo nao encontrado");

    input >> quantidadeEquipes;
    Equipe** equipes = new Equipe*[quantidadeEquipes];


    for (int i=0; i<quantidadeEquipes; i++) {
        input >> nomeEquipe;
        Equipe* equipe = new Equipe(nomeEquipe);
        equipes[i] = equipe;
    }

    input >> nomeCompeticao;
    input >> tipoCompeticao;

    if (tipoCompeticao == 0) {
        input >> nomeModalidade;
        Modalidade* mod = new Modalidade(nomeModalidade, equipes, quantidadeEquipes);
        input >> temResultado;
        if (temResultado == 0) {
                Competicao* comp = new CompeticaoSimples(nomeCompeticao, equipes, quantidadeEquipes, mod);
                return comp;
        }

        else {
            Equipe** ordem = new Equipe*[quantidadeEquipes];
            input>>quantidadePart;
            for (int j=0; j<quantidadePart; j++){
                input >> nome;
                for(int i = 0;i<quantidadeEquipes;i++)
                    if(equipes[i]->getNome()==nome)
                        ordem[j] = equipes[i];
            }
            mod->setResultado(ordem);
            Competicao* comp = new CompeticaoSimples(nomeCompeticao, equipes, quantidadeEquipes, mod);

                return comp;
        }
    }
    else {
        input>>quantidadeModalidades;
        Modalidade** modalidades = new Modalidade*[quantidadeModalidades];
        CompeticaoMultimodalidades* comp = new CompeticaoMultimodalidades(nomeCompeticao,equipes,quantidadeEquipes);

        for(int i = 0;i<quantidadeModalidades;i++)
        {
            input>>nomeModalidade;
            Modalidade* mod = new Modalidade(nomeModalidade,equipes,quantidadeEquipes);
            modalidades[i] = mod;
            input>>temResultado;

            if(temResultado == 1)
            {
                Equipe** ordem = new Equipe*[quantidadeEquipes];
                input>>quantidadePart;
                for (int j=0; j<quantidadePart; j++){
                    input >> nome;
                    for(int i = 0;i<quantidadeEquipes;i++)
                        if(equipes[i]->getNome()==nome)
                            ordem[j] = equipes[i];
                }
                modalidades[i]->setResultado(ordem);

            }


           comp->adicionar(modalidades[i]);


        }



        return comp;



    }




    input.close();


}


void PersistenciaDeCompeticao::salvar(string arquivo, Competicao* c)
{
    CompeticaoSimples* filho = dynamic_cast<CompeticaoSimples*>(c);

    if(filho != NULL)
    {
        ofstream output;
        output.open(arquivo,ios_base::app);

        output<< c->getQuantidadeDeEquipes();
        for(int i = 0;i<c->getQuantidadeDeEquipes();i++)
            output<<" " <<c->getEquipes()[i]->getNome();
        output<<endl<<c->getNome()<<endl<<0<<endl;
        output<<filho->getModalidade()->getNome()<<endl;

        if(filho->getModalidade()->temResultado()==true)
        {
            output<< 1 <<" "<< filho->getModalidade()->getQuantidadeDeEquipes();
            for(int i = 0; i < filho->getModalidade()->getQuantidadeDeEquipes();i++)
                output<<" "<<filho->getModalidade()->getTabela()->getEquipesEmOrdem()[i]->getNome();
        } else
            {
                output<<0<<" "<<filho->getModalidade()->getQuantidadeDeEquipes();
                for(int i = 0;i<filho->getModalidade()->getQuantidadeDeEquipes();i++)
                    output<<" "<<filho->getModalidade()->getEquipes()[i]->getNome();
            }
        output.close();
    }

    CompeticaoMultimodalidades* mult = dynamic_cast<CompeticaoMultimodalidades*>(c);

    if(mult != NULL)
    {
        ofstream output;
        output.open(arquivo,ios_base::app);

        output<<mult->getQuantidadeDeEquipes();
        for(int i =0;i<mult->getQuantidadeDeEquipes();i++)
            output<<" "<<mult->getEquipes()[i]->getNome();
        output<<endl<<mult->getNome()<<endl<<1<<endl<<mult->getModalidades()->size()<<endl;

        list<Modalidade*>::iterator j = mult->getModalidades()->begin();

        while(j != mult->getModalidades()->end())
        {
            output<<(*j)->getNome()<<endl;
            if((*j)->temResultado()==true)
            {
                output<<1<<" "<<(*j)->getQuantidadeDeEquipes();
                for(int i = 0;i<(*j)->getQuantidadeDeEquipes();i++)
                    output<<" "<<(*j)->getTabela()->getEquipesEmOrdem()[i]->getNome();
            }else
            {
                 output<<0<<" "<<(*j)->getQuantidadeDeEquipes();
                for(int i = 0;i<(*j)->getQuantidadeDeEquipes();i++)
                    output<<" "<<(*j)->getEquipes()[i]->getNome();
            }
            output<<endl;

            j++;
        }


        output.close();
    }
}
