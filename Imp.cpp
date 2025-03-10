#include "Imp.h"

void CASTELOpp::Entidade::Personagens::Inimigo::Imp::Inicializa()
{
	this->setDano(igneo);

	animacao.setAnimacao(CAMINHO "Inimigo/Imp/hell-beast-idle_invertido.png", "ANDA", 6, 0.25f, sf::Vector2f(1.000f, 1.000f));
	animacao.setAnimacao(CAMINHO "Inimigo/Imp/hell-beast-idle_invertido.png", "PARADO", 6, 0.25f, sf::Vector2f(1.000f, 1.00f));
	animacao.setAnimacao(CAMINHO "Inimigo/Imp/hell-beast-breath_invertido.png", "ATACA", 4, 0.25f, sf::Vector2f(1.000f, 1.000f));
	animacao.setAnimacao(CAMINHO "Inimigo/Imp/hell-beast-idle_invertido.png", "PULA", 6, 0.25f, sf::Vector2f(1.000f, 1.00f));
	animacao.setAnimacao(CAMINHO "Inimigo/Imp/hell-beast-death_invertido.png", "MORTE", 4, 0.25f, sf::Vector2f(1.000f, 1.00f));

}

CASTELOpp::Entidade::Personagens::Inimigo::Imp::Imp(const sf::Vector2f Pos, vector<Entidade*>pJogador) :
	Inimigo(Pos,sf::Vector2f(100.0f,120.0f),pJogador),igneo(1)
{
	Inicializa();
}

CASTELOpp::Entidade::Personagens::Inimigo::Imp::~Imp()
{
}

float CASTELOpp::Entidade::Personagens::Inimigo::Imp::getVida() const
{
    return vida;
}

bool CASTELOpp::Entidade::Personagens::Inimigo::Imp::Aparecer() const
{
    return ((getVida() > 0) ? true : false);
}

void CASTELOpp::Entidade::Personagens::Inimigo::Imp::Atacar(Entidade* EntidadeAtacada){

	if (!atacando)
		atacando = true;
	else if (TmpParaAtac.getElapsedTime().asSeconds() > 0.75f) {
		if (!jaAtacou) {
			SoltarFogo(AndarEsq);
			jaAtacou = true;
		}
		if (TmpParaAtac.getElapsedTime().asSeconds() > 1.25f) {
			atacando = false;
			TmpParaAtac.restart();
			jaAtacou = false;
		}
	}
	
}

void CASTELOpp::Entidade::Personagens::Inimigo::Imp::SoltarFogo(bool Esq){
	
	Fase::Fase::pFase->criaProjetil(sf::Vector2f(this->getCorpo().getPosition().x + this->getTam().x / 2, this->getCorpo().getPosition().y + this->getTam().y / 2), Esq);
}
