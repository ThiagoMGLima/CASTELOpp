#include "Floresta.h"

void CASTELOpp::Fase::Floresta::InstanciaEnt(int numJogadores)
{
	setNumJog(numJogadores);

	for (int i = 1; i <= numJogadores; i++) {
		criaJogador(sf::Vector2f(150.0f * i, -1000.00f), sf::Vector2f(100.0f, 100.0f));
	}

	criaChao(sf::Vector2f(000.0f, 750.0f), sf::Vector2f(417.0f, 100.0f), false);
	criaChao(sf::Vector2f(417.0f, 780.0f), sf::Vector2f(150.0f, 100.f), false);
	criaChao(sf::Vector2f(567.0f, 750.0f), sf::Vector2f(233.0f, 100.f), false);
	
	vector<Entidade::Entidade*> vJog = getJogador();

	criaInimigoFantasma(sf::Vector2f(350.0f, -1000.0f), sf::Vector2f(100.0f, 125.0f), vJog);
	criaInimigoFantasma(sf::Vector2f(700.0f, -1000.0f), sf::Vector2f(100.0f, 125.0f), vJog);
	criaInimigoFantasma(sf::Vector2f(1000.0f, -1000.0f), sf::Vector2f(100.0f, 125.0f), vJog);

	criaImp(sf::Vector2f(700.0f, -1000.0f), vJog);
	criaImp(sf::Vector2f(417.0f + 800.0f, -1000.0f), vJog);
	criaImp(sf::Vector2f(417.0f + 2400.0f, -1000.0f), vJog);

	criaChao(sf::Vector2f(-10.0f, 0.0f), sf::Vector2f(50.0f, 1000.f), true); 

	criaLama(sf::Vector2f(417.0f, 750.0f));  
	criaToxic(sf::Vector2f(417.0f + 800.0f, 750.0f)); 

	criaLama(sf::Vector2f(417.0f + 1600.0f, 750.0f));  
	criaToxic(sf::Vector2f(417.0f + 2400.0f, 750.0f)); 

	criaLama(sf::Vector2f(417.0f + 3200.0f, 750.0f));  
	criaToxic(sf::Vector2f(417.0f + 4000.0f, 750.0f)); 


	criaPlataforma(sf::Vector2f(417.0f, 600.0f)); 

	criaPlataforma(sf::Vector2f(417.0f + 800.0f, 600.0f)); 

	criaPlataforma(sf::Vector2f(417.0f + 2400.0f, 600.0f)); 


	int num_ale = rand() % 2;

	while (num_ale + 2 < NUM_MAX_INI) {
		criaToxic(sf::Vector2f(417.0f + 800.0f*(num_ale + 1), 750.0f));
		criaPlataforma(sf::Vector2f(417.0f + 800.0f * (num_ale + 1), 600.0f));
		criaImp(sf::Vector2f(417.0f + 800.0f * (num_ale + 1), -1000.0f), vJog);
		criaInimigoFantasma(sf::Vector2f(417.0f + 800.0f * (num_ale + 2), -1000.0f), sf::Vector2f(100.0f, 125.0f),vJog);
		num_ale++;
	}
	for (int i = 1; i <= 7; i++) {
	criaChao(sf::Vector2f(800.0f*i, 750.0f), sf::Vector2f(417.0f, 100.0f), false);
	criaChao(sf::Vector2f(417.0f + 800.0f * i, 780.0f), sf::Vector2f(150.0f, 100.f), false);
	criaChao(sf::Vector2f(567.0f + 800.0f * i, 750.0f), sf::Vector2f(233.0f, 100.f), false);
	}
	//Parede invi Final
	criaChao(sf::Vector2f(6400.f, 0.0f), sf::Vector2f(50.0f, 1000.0f), true);

}

CASTELOpp::Fase::Floresta::Floresta(int numJogadores):
	Fase(ID::Floresta)
{
	criarFundo();
	InstanciaEnt(numJogadores);
}

CASTELOpp::Fase::Floresta::~Floresta()
{
}

void CASTELOpp::Fase::Floresta::criarFundo() {

	
	fundo.addCamada(CAMINHO "FUNDAO3_SemFundo.jpg", 0.00075f);
	
	fundo.addCamada(CAMINHO "Fases/Floresta/night-town-background-clouds.png", 0.05f);
}

bool CASTELOpp::Fase::Floresta::acabouFase()
{
	AcaboFase = true;
	for (int i = 0; listaEntidades.lenEnt() > i; i++) {
		if (listaEntidades.operator[](i)->getId() == ID::inimigo && listaEntidades.operator[](i)->Aparecer())
			AcaboFase = false;
	}
	return AcaboFase;
}
