#include "EstadoJogar.h"

CASTELOpp::Estado::EstadoJogar::EstadoJogar(const ID Id, Fase::Fase* fase):
	Estado(Id),fase(fase)
{
  
}

CASTELOpp::Estado::EstadoJogar::~EstadoJogar()
{
    if (fase) {
        delete(fase);
        fase = nullptr;
    }
}

CASTELOpp::Fase::Fase* CASTELOpp::Estado::EstadoJogar::getFase() const
{
    return fase;
}

void CASTELOpp::Estado::EstadoJogar::Atualizar(double t)
{

    if (fase->acabouFase()) {
        fase->clearvJogadores();
        if (fase->getId() == ID::Floresta) {
            delete(fase);
            fase = new Fase::Castelo(fase->getNumJog());
        }
        else {
            addpontuacao(fase->getTmpfase());
            fase->zeraTmpfase();
            fase->clearvJogadores();
            setRemover(true);
        }
    }

    if (fase->JogadoresMorreram()) {
        fase->clearvJogadores();
        setRemover(true);
    }
    fase->Atualizar(t);
}

vector<CASTELOpp::Entidade::Entidade*> CASTELOpp::Estado::EstadoJogar::getJgdr()
{  
    return fase->getJogador();
}
