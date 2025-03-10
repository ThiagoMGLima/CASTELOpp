#include "Castelo.h"

void CASTELOpp::Fase::Castelo::InstanciaEnt(int numJogadores)
{
	for (int i = 1; i <= numJogadores; i++) {
		criaJogador(sf::Vector2f(150.0f * i, -2000.00f), sf::Vector2f(100.0f, 100.0f));
	}

	vector<Entidade::Entidade*> vJog = getJogador();

	criaPlataforma(sf::Vector2f(-26.0f, 0.0f), sf::Vector2f(26.0f, 960.0f), CAMINHO "Fases/Castelo/parede_castelo.png");
	criaPlataforma(sf::Vector2f(000.0f, 599.0f), sf::Vector2f(543.0f, 181.0f), CAMINHO "Fases/Castelo/chao_castelo.png");
	criaPlataforma(sf::Vector2f(543.0f, 599.0f), sf::Vector2f(160.0f, 181.0f), CAMINHO "Fases/Castelo/toxico_castelo_a.png");
	criaPlataforma(sf::Vector2f(703.0f, 650.0f), sf::Vector2f(150.0f, 22.0f), CAMINHO "Fases/Castelo/plataforma_castelo.png");
	criaPlataforma(sf::Vector2f(853.0f, 599.0f), sf::Vector2f(115.0f, 181.0f), CAMINHO "Fases/Castelo/toxico_castelo_b.png");

	for (int i = 1; i < 5; i++) {
		criaPlataforma(sf::Vector2f(0.0f + 968.0f * i, 599.0f), sf::Vector2f(543.0f, 181.0f), CAMINHO "Fases/Castelo/chao_castelo.png");
		criaPlataforma(sf::Vector2f(1100.0f * i, 450.0f), sf::Vector2f(150.0f, 22.0f), CAMINHO "Fases/Castelo/plataforma_castelo.png");

		criaPlataforma(sf::Vector2f(543.0f + 968.0f * i, 599.0f), sf::Vector2f(160.0f, 181.0f), CAMINHO "Fases/Castelo/toxico_castelo_a.png");
		criaPlataforma(sf::Vector2f(703.0f + 968.0f * i, 650.0f), sf::Vector2f(150.0f, 22.0f), CAMINHO "Fases/Castelo/plataforma_castelo.png");
		criaPlataforma(sf::Vector2f(853.0f + 968.0f * i, 599.0f), sf::Vector2f(115.0f, 181.0f), CAMINHO "Fases/Castelo/toxico_castelo_b.png");
	}


	int num_ale = rand() % 2;

	while (num_ale + 1 < 5) {
		criaToxic(sf::Vector2f(703.0f + 968.0f * (num_ale + 1), 620.0f));
		criaPlataforma(sf::Vector2f(703.0f + 820.0f * (num_ale), 450.0f), sf::Vector2f(150.0f, 22.0f), CAMINHO "Fases/Castelo/plataforma_castelo.png");
		criaImp(sf::Vector2f(500.0f + 450.0f * (num_ale + 1), -2000.0f), vJog);
		criaInimigoFantasma(sf::Vector2f(600.0f + 450.0f * (num_ale + 1), -2000.0f), sf::Vector2f(100.0f, 125.0f), vJog);
		num_ale++;
	}


	criaImp(sf::Vector2f(4500.0f, -2000.0f), vJog);
	criaInimigoFantasma(sf::Vector2f(4600.0f, -2000.0f), sf::Vector2f(100.0f, 125.0f), vJog);

	criaPlataforma(sf::Vector2f(4840.0f, 599.0f), sf::Vector2f(160.0f, 181.0f), CAMINHO "Fases/Castelo/toxico_castelo_a.png");
	criaPlataforma(sf::Vector2f(5000.0f, 750.0f), sf::Vector2f(543.0f, 181.0f), CAMINHO "Fases/Castelo/chao_castelo.png");
	criaPlataforma(sf::Vector2f(5543.0f, 750.0f), sf::Vector2f(543.0f, 181.0f), CAMINHO "Fases/Castelo/chao_castelo.png");

	criaPlataforma(sf::Vector2f(6086.0f, 0.0f), sf::Vector2f(26.0f, 960.0f), CAMINHO "Fases/Castelo/parede_castelo.png");
	criaChefe(sf::Vector2f(5500.0f, -1000.0f), sf::Vector2f(200.0f, 200.0f), vJog);

}

CASTELOpp::Fase::Castelo::Castelo(int numJogadores) :
	Fase(ID::Castelo)
{
	criarFundo();
	InstanciaEnt(numJogadores);
}

CASTELOpp::Fase::Castelo::~Castelo()
{
}

void CASTELOpp::Fase::Castelo::criarFundo() {

	fundo.addCamada(CAMINHO "Fases/Castelo/Castelo_Fundo.png", 0.00075f);
	
}

bool CASTELOpp::Fase::Castelo::acabouFase()
{
	AcaboFase = true;
	for (int i = 0; listaEntidades.lenEnt() > i; i++) {
		if (listaEntidades.operator[](i)->getId() == ID::inimigo && listaEntidades.operator[](i)->Aparecer())
			AcaboFase = false;
	}
	return AcaboFase;
}
