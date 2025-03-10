#include "Entidade.h"

CASTELOpp::Entidade::Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam,const ID id) : 
	Ente(id),vel(0, GRAVIDADE),noar(true),dano(0.0f),nPodeAtacar(false),TmpParaAtac(),aparecer(true)
{
	corpo.setPosition(pos);
	corpo.setSize(tam);

}

CASTELOpp::Entidade::Entidade::~Entidade()
{
}

const sf::RectangleShape CASTELOpp::Entidade::Entidade::getCorpo() const
{
	return corpo;
}

const sf::Vector2f CASTELOpp::Entidade::Entidade::getPosition() const {
	return corpo.getPosition();
}

const sf::Vector2f CASTELOpp::Entidade::Entidade::getTam() const
{
	return corpo.getSize();
}

void CASTELOpp::Entidade::Entidade::setVel(sf::Vector2f Vel)
{
	vel = Vel;
}

sf::Vector2f CASTELOpp::Entidade::Entidade::getVel()
{
	return vel;
}

void CASTELOpp::Entidade::Entidade::setNoAr(bool Estado){
	noar = Estado;
}

void CASTELOpp::Entidade::Entidade::mudarPosicao(sf::Vector2f pos)
{
	corpo.setPosition(pos);
}

void CASTELOpp::Entidade::Entidade::setDano(float quantidade)
{
	dano = quantidade;
}

float CASTELOpp::Entidade::Entidade::getDano() const
{
	return dano;
}





