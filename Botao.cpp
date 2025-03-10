#include "Botao.h"

CASTELOpp::Menu::Botao::Botao(sf::Vector2f Pos, std::string texto) :
	Ente(ID::Botao), fonte(), Selecionado(false), Texto()
{
	//posicao.setPosition(Pos);
	if (!fonte.loadFromFile("./Fonte/Bradley_Gratis.ttf")) {
		std::cout<< "ERROR CASTELOpp::Menu::Botao::Botao, Nao foi possivel carregar Fonte" << std::endl;
		exit(1);
	}
	
	Texto.setFont(fonte);
	Texto.setString(texto);
	Texto.setPosition(Pos);
}

CASTELOpp::Menu::Botao::~Botao()
{
}

void CASTELOpp::Menu::Botao::setSelecionado(const bool selecionado)
{
	if (selecionado) {
		Texto.setFillColor(sf::Color::Red);
	}
	else {
		Texto.setFillColor(sf::Color::White);
	}

	this->Selecionado = selecionado;
}

const bool CASTELOpp::Menu::Botao::getSelecionado() const
{
	return Selecionado;
}

void CASTELOpp::Menu::Botao::desenhar()
{
	pGerGrafico->getGerGrafico()->getWindow()->draw(Texto);
}

std::string CASTELOpp::Menu::Botao::getString() const
{
	return Texto.getString();
}

sf::Vector2f CASTELOpp::Menu::Botao::getPosicao() const
{
	return Texto.getPosition();
}
