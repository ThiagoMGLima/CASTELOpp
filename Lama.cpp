#include "Lama.h"

CASTELOpp::Entidade::Obstaculo::Lama::Lama(sf::Vector2f Pos):
	Obstaculo(Pos,sf::Vector2f(150.0f,30.0f),ID::Lama)
{
	setTextura(pGerGrafico->CarregarTextura(CAMINHO"/Lama/Lama.png")); //Colocar Textura Lama
	corpo.setTexture(&Textura);
}

CASTELOpp::Entidade::Obstaculo::Lama::~Lama()
{
}

bool CASTELOpp::Entidade::Obstaculo::Lama::GerirAtk(Entidade* pEntidade)
{
	return true;
}

void CASTELOpp::Entidade::Obstaculo::Lama::Atacar(Entidade* EntidadeAtacada)
{
	EntidadeAtacada->setVel(sf::Vector2f(EntidadeAtacada->getVel().x * 0.95f, EntidadeAtacada->getVel().y));
}
