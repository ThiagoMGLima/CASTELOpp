#include "ConstrutorFase.h"

CASTELOpp::Construtor::ConstrutorFase::ConstrutorFase()
{
}

CASTELOpp::Construtor::ConstrutorFase::~ConstrutorFase()
{
}

CASTELOpp::Fase::Fase* CASTELOpp::Construtor::ConstrutorFase::criarFase(const ID Id, int numJogadores)
{

    Fase::Fase* fase = nullptr;
    switch (Id)
    {
    case (ID::Castelo):
    {
        fase = criarCastelo(numJogadores);
    }
    break;
    case (ID::Floresta):
    {
        fase = criarFloresta(numJogadores);
    }
    break;
    default:
    {
        std::cout << "CASTELOpp::Construtor::ConstrutorFase::ID da Fase invalido" << std::endl;
        exit(1);
    }
    break;
    }

    fase->criarFundo();

    return fase;
}

CASTELOpp::Fase::Fase* CASTELOpp::Construtor::ConstrutorFase::criarCastelo(int numJogadores)
{
    Fase::Fase* fase = static_cast<Fase::Fase*>(new Fase::Castelo(numJogadores));
    if (fase == nullptr) {
        std::cout << "CASTELOpp::Construtor::ConstrutorFase::nao foi possivel criar Fase Castelo" << std::endl;
        exit(1);
    }
    return fase;
}

CASTELOpp::Fase::Fase* CASTELOpp::Construtor::ConstrutorFase::criarFloresta(int numJogadores)
{
    Fase::Fase* fase = static_cast<Fase::Fase*>(new Fase::Floresta(numJogadores));
    if (fase == nullptr) {
        std::cout << "CASTELOpp::Construtor::ConstrutorFase::nao foi possivel criar Fase Floresta" << std::endl;
        exit(1);
    }
    return fase;
}
