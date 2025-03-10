#include "Plataforma.h"

CASTELOpp::Entidade::Obstaculo::Plataforma::Plataforma(sf::Vector2f pos)
	:Obstaculo(pos, sf::Vector2f(200.0f, 50.0f),ID::Plataforma),qualTextura(1)
{
	
	qualTextura = rand() % 3;

	
	if (qualTextura == 0) {
		setTextura(pGerGrafico->CarregarTextura(CAMINHO "Plataforma.png"));
		
	}
	else if (qualTextura == 1) {
		setTextura(pGerGrafico->CarregarTextura(CAMINHO "Plataforma3_2.png"));
	}
	else if (qualTextura == 2) {
		setTextura(pGerGrafico->CarregarTextura(CAMINHO"Plat/PLATA.png"));
	}
	
	corpo.setTexture(&Textura);

}

CASTELOpp::Entidade::Obstaculo::Plataforma::Plataforma(sf::Vector2f pos,sf::Vector2f tam,bool invi):
	Obstaculo(pos,tam,ID::Plataforma),qualTextura()
{
	if(invi)
		corpo.setFillColor(sf::Color::Transparent);
	else {
		setTextura(pGerGrafico->CarregarTextura(CAMINHO "Fases/night-town-background-sky.png"));
		corpo.setTexture(&Textura);
	}
}

CASTELOpp::Entidade::Obstaculo::Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, const char* caminhoTextura):
	Obstaculo(pos,tam,ID::Plataforma),qualTextura()
{
	setTextura(pGerGrafico->CarregarTextura(caminhoTextura));
	corpo.setTexture(&Textura);
}

CASTELOpp::Entidade::Obstaculo::Plataforma::~Plataforma()
{
}

bool CASTELOpp::Entidade::Obstaculo::Plataforma::GerirAtk(Entidade* pEntidade)
{
	return false;
}

void CASTELOpp::Entidade::Obstaculo::Plataforma::Atacar(Entidade* entidadeatacada)
{
}
