#include "Obstaculo.h"

CASTELOpp::Entidade::Obstaculo::Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam,ID Id) :
	Entidade(pos, tam, Id),Textura()
{

	vel = sf::Vector2f(0, GRAVIDADE);
}

CASTELOpp::Entidade::Obstaculo::Obstaculo::~Obstaculo()
{
}

void CASTELOpp::Entidade::Obstaculo::Obstaculo::Atualizar(double t)
{
	pGerGrafico->printElemento(this->getCorpo());
}

void CASTELOpp::Entidade::Obstaculo::Obstaculo::colisao(Entidade* entidade,sf::Vector2f desl)
{

}

bool CASTELOpp::Entidade::Obstaculo::Obstaculo::GerirAtk(Entidade* pEntidade)
{
	return false;
}

void CASTELOpp::Entidade::Obstaculo::Obstaculo::Atacar(Entidade* EntidadeAtacada)
{
}

void CASTELOpp::Entidade::Obstaculo::Obstaculo::setTextura(sf::Texture textura)
{
	Textura = textura;
}
