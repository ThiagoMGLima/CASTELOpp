#include "ConstrutorEstado.h"

CASTELOpp::Construtor::ConstrutorEstado::ConstrutorEstado()
{
}

CASTELOpp::Construtor::ConstrutorEstado::~ConstrutorEstado()
{
}

CASTELOpp::Estado::Estado* CASTELOpp::Construtor::ConstrutorEstado::criarEstado(const ID Id,int num)
{
	Estado::Estado* estado = nullptr;
    switch (Id)
    {
        case (ID::Castelo):
        {
            estado = criarEstadoJogar(Id, num);
        }
        break;

        case (ID::Floresta):
        {
            estado = criarEstadoJogar(Id, num);
        }
        break;

        case(ID::Menu): 
        {
            estado = criaMenu();
        }
        break;
        case(ID::Rank): {
            estado = criaRank();
        }
        
    }
    return estado;
}

CASTELOpp::Estado::Estado* CASTELOpp::Construtor::ConstrutorEstado::criarEstadoJogar(const ID Id,int numJogadores)
{
    Fase::Fase* fase = nullptr;
    Construtor::ConstrutorFase construtorFase;

    fase = construtorFase.criarFase(Id, numJogadores);

    Estado::EstadoJogar* estadoJogar = new Estado::EstadoJogar(Id, fase);
    return static_cast<Estado::Estado*>(estadoJogar);
}

CASTELOpp::Estado::Estado* CASTELOpp::Construtor::ConstrutorEstado::criaMenu()
{
    Estado::Estado* estado = nullptr;
    estado = static_cast<Estado::Estado*>(new Estado::EstadoMenu());

    if(estado == nullptr){
        std::cout << "CASTELOpp::ConstrutorEstado::criaMenu estado era nullptr" << endl;
        exit(1);
    }
    return estado;
}

CASTELOpp::Estado::Estado* CASTELOpp::Construtor::ConstrutorEstado::criaRank()
{
    Estado::Estado* estado = nullptr;
    estado = static_cast<Estado::Estado*>(new Estado::EstadoRank());

    if (estado == nullptr) {
        std::cout << "CASTELOpp::ConstrutorEstado::criaMenu estado era nullptr" << endl;
        exit(1);
    }
    return estado;
}
