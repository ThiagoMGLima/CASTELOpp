#include "Fantasma.h"

CASTELOpp::Entidade::Personagens::Inimigo::Fantasma::Fantasma(const sf::Vector2f Pos, const sf::Vector2f Tam, vector<Entidade*> jogador):
	Inimigo(Pos,Tam,jogador),fantasmagorico(2)
{
	Inicializa();
}

CASTELOpp::Entidade::Personagens::Inimigo::Fantasma::~Fantasma()
{
}

float CASTELOpp::Entidade::Personagens::Inimigo::Fantasma::getVida() const
{
	return vida;
}

bool CASTELOpp::Entidade::Personagens::Inimigo::Fantasma::Aparecer() const
{
	if (getVida() > 0)
		return true;
	else
		return false;
}

void CASTELOpp::Entidade::Personagens::Inimigo::Fantasma::Atacar(Entidade* entidadeAtacada)
{
	if (!atacando)
		atacando = true;

	else if (TmpParaAtac.getElapsedTime().asSeconds() > 0.75f) {
		if (!jaAtacou) {
			entidadeAtacada->TomaDano(getDano());
			jaAtacou = true;
		}
		if (TmpParaAtac.getElapsedTime().asSeconds() >= 0.75f) {
			atacando = false;
			TmpParaAtac.restart();
			jaAtacou = false;
		}
	}
}

void CASTELOpp::Entidade::Personagens::Inimigo::Fantasma::Inicializa()
{
	this->setDano(fantasmagorico);

	animacao.setAnimacao(CAMINHO "Inimigo/Fantasma/ghost-idle_invertido.png", "ANDA", 7, 0.25f, sf::Vector2f(1.000f, 1.000f));
	animacao.setAnimacao(CAMINHO "Inimigo/Fantasma/ghost-idle_invertido.png", "PARADO", 7, 0.25f, sf::Vector2f(1.000f, 1.00f));
	animacao.setAnimacao(CAMINHO "Inimigo/Fantasma/ghost-shriek_invertido.png", "ATACA", 4, 0.25f, sf::Vector2f(1.000f, 1.000f));
	animacao.setAnimacao(CAMINHO "Inimigo/Fantasma/ghost-idle_invertido.png", "PULA", 7, 0.25f, sf::Vector2f(1.000f, 1.00f));
	animacao.setAnimacao(CAMINHO "Inimigo/Fantasma/ghost-vanish_invertido.png", "MORTE", 7, 0.25f, sf::Vector2f(1.000f, 1.00f));
}
