#include "Personagem.h"


CASTELOpp::Entidade::Personagens::Personagem::Personagem::Personagem(const sf::Vector2f Pos, const sf::Vector2f Tam, const ID id) :
	Entidade::Entidade(Pos, Tam, id), ds(0, 0), animacao(&corpo),atacando(false),vida(10)
{	
	corpo = sf::RectangleShape(sf::Vector2f(Tam));
	corpo.setPosition(Pos);
}

CASTELOpp::Entidade::Personagens::Personagem::Personagem::~Personagem()
{
}


void CASTELOpp::Entidade::Personagens::Personagem::Personagem::andar(const bool paraEsquerda) {
	podeAndar = true;
	AndarEsq = paraEsquerda;
}

void CASTELOpp::Entidade::Personagens::Personagem::Personagem::parar() {
	podeAndar = false;
}

/*void CASTELOpp::Entidade::Personagens::Personagem::colisao(Entidade* entidadeColidida, sf::Vector2f desl)
{
	
}
*/

bool CASTELOpp::Entidade::Personagens::Personagem::noAr() {
	return noar;
}

float CASTELOpp::Entidade::Personagens::Personagem::getVida()
{
	return vida;
}

bool CASTELOpp::Entidade::Personagens::Personagem::GerirAtk(Entidade* pEntidade)
{
	return false;
}

void CASTELOpp::Entidade::Personagens::Personagem::Atacar(Entidade* EntidadeAtacada)
{
}

void CASTELOpp::Entidade::Personagens::Personagem::TomaDano(float quantidade)
{
	vida -= quantidade;
}
