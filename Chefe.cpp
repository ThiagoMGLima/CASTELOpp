#include "Chefe.h"

void CASTELOpp::Entidade::Personagens::Inimigo::Chefe::Inicializa()
{
	animacao.setAnimacao(CAMINHO "Inimigo/demon-idle.png", "ANDA", 6, 0.25f, sf::Vector2f(1.000f, 1.000f));
	animacao.setAnimacao(CAMINHO "Inimigo/demon-idle.png", "PARADO", 6, 0.25f, sf::Vector2f(1.000f, 1.00f));
	animacao.setAnimacao(CAMINHO "Inimigo/demon-attack.png", "ATACA", 11, 0.110f, sf::Vector2f(1.000f, 1.000f));
	animacao.setAnimacao(CAMINHO "Inimigo/demon-idle.png", "PULA", 6, 0.25f, sf::Vector2f(1.000f, 1.00f));
	animacao.setAnimacao(CAMINHO "Inimigo/demon-death.png", "MORTE", 6, 0.25f, sf::Vector2f(1.000f, 1.00f));
}

CASTELOpp::Entidade::Personagens::Inimigo::Chefe::Chefe(const sf::Vector2f Pos, const sf::Vector2f Tam, vector<Entidade*> Jogador):
	Inimigo(Pos,Tam,Jogador)
{
	setDano(2.5f);
	Inicializa();
	vida = 15;
}

CASTELOpp::Entidade::Personagens::Inimigo::Chefe::~Chefe()
{
}

float CASTELOpp::Entidade::Personagens::Inimigo::Chefe::getVida() const
{
	return vida;
}

bool CASTELOpp::Entidade::Personagens::Inimigo::Chefe::Aparecer() const
{
	if (getVida() > 0)
		return true;
	else
		return false;
}

void CASTELOpp::Entidade::Personagens::Inimigo::Chefe::Atacar(Entidade* entidadeAtacada)
{
	if (!atacando)
		atacando = true;

	else if (TmpParaAtac.getElapsedTime().asSeconds() > 0.75f) {
		if (!jaAtacou) {
			entidadeAtacada->TomaDano(getDano());
			jaAtacou = true;
		}
		if (TmpParaAtac.getElapsedTime().asSeconds() >= 1.25f) {
			atacando = false;
			TmpParaAtac.restart();
			jaAtacou = false;
		}
		
	}
}
