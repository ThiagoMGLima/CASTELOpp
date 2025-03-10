#include "Toxico.h"

CASTELOpp::Entidade::Obstaculo::Toxico::Toxico(sf::Vector2f pos):
	Obstaculo(pos, sf::Vector2f(150.0f, 30.0f), ID::Toxico)
{
	setTextura(pGerGrafico->CarregarTextura(CAMINHO"/Toxic/TOXIC_2.png"));
	setDano(0.001f);
	corpo.setTexture(&Textura);
}

CASTELOpp::Entidade::Obstaculo::Toxico::~Toxico()
{
}

bool CASTELOpp::Entidade::Obstaculo::Toxico::GerirAtk(Entidade* pEntidade)
{
	return true;
}

void CASTELOpp::Entidade::Obstaculo::Toxico::Atacar(Entidade* EntidadeAtacada)
{
	if (TempoTox.getElapsedTime().asSeconds() > 10.0f)
		TempoTox.restart();
	EntidadeAtacada->TomaDano(getDano() * TempoTox.getElapsedTime().asSeconds());
}
