#include "Projetil.h"

CASTELOpp::Entidade::Projetil::Projetil(const sf::Vector2f pos, const bool Esq):
    Entidade::Entidade(pos, sf::Vector2f(15.0f,15.0f), ID::Projetil),JaAtacou(false)
{
    if (Esq) {
        setVel(sf::Vector2f(-VEL_PROJETIL, GRAVIDADE));
    }
    else {
        setVel(sf::Vector2f(VEL_PROJETIL, GRAVIDADE));
    }
    
    corpo.setFillColor(sf::Color::Red);
    setDano(1);
}

CASTELOpp::Entidade::Projetil::~Projetil()
{
}

void CASTELOpp::Entidade::Projetil::darDano(Entidade* pJog) {
    pJog->TomaDano(getDano());
    JaAtacou = true;
}

bool CASTELOpp::Entidade::Projetil::GerirAtk(Entidade* pEntidade)
{
    return true;;
}

void CASTELOpp::Entidade::Projetil::TomaDano(float quantidade)
{
}

void CASTELOpp::Entidade::Projetil::Atacar(Entidade* pEntidade)
{
    if (pEntidade->getId() == ID::jogador) {
        darDano(pEntidade);
    }
    
}

bool CASTELOpp::Entidade::Projetil::Aparecer() const
{
    return (JaAtacou ? false : true);
}

void CASTELOpp::Entidade::Projetil::Atualizar(double t)
{
    if (!JaAtacou) {
        corpo.setPosition(this->getPosition().x + vel.x * (float)t, this->getPosition().y);
        pGerGrafico->printElemento(getCorpo());
    }

}
