#include "Jogo.h"

//Inicializar statica Tempo

CASTELOpp::Gerenciador::GerenciadorGrafico* CASTELOpp::Jogo::pGrafico = pGrafico->getGerGrafico();
CASTELOpp::Gerenciador::GerenciadorEstado* CASTELOpp::Jogo::pEstado = pEstado->getGerenciadorEstado();
CASTELOpp::Gerenciador::GerenciadorEventos* CASTELOpp::Jogo::pEventos = pEventos->getGerEventos();


CASTELOpp::Jogo::Jogo():
	Tempo()
{
	
	if (pGrafico == nullptr) {
		std::cout << "ERROR::CASTELOpp::Jogo nao foi possivel criar o GerenciadorGrafico" << std::endl;
		exit(1);
	}
	
	if (pEventos == nullptr) {
		std::cout << "ERROR::CASTELOpp::Jogo nao foi possivel criar um GerenciadorEvento" << std::endl;
		exit(1);
	}
	
	srand((unsigned int)time(NULL));

	pEstado->addEstado(ID::Menu);
	//pEstado->addEstado(ID::Floresta);
	//criaFase(ID::Castelo);

	executar();
}

CASTELOpp::Jogo::~Jogo() {

}

/*
void CASTELOpp::Jogo::InstanciaEnt()
{
	

	Entidade::Personagens::Jogador::Jogador* jogador1 = new Entidade::Personagens::Jogador::Jogador(sf::Vector2f(100.0f, 0.0f), sf::Vector2f(100.0f, 100.0f));
	
	Entidade::Personagens::Inimigo::Inimigo* inimigo = new Entidade::Personagens::Inimigo::Inimigo(sf::Vector2f(500.0f, 300.0f), sf::Vector2f(50.0f, 50.0f), jogador1);
	Entidade::Personagens::Inimigo::Inimigo* inimigo2 = new Entidade::Personagens::Inimigo::Inimigo(sf::Vector2f(60.0f, 100.0f), sf::Vector2f(50.0f, 50.0f), jogador1);

	
	Entidade::Obstaculo::Obstaculo* chao2 = new Entidade::Obstaculo::Obstaculo(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(300.0f, 100.0f), "C:/Users/thiag/Desktop/utfpr/Tec_Prog/1-reuniao-main/1-reuniao-main/Project_Simao2/chao.jpg");
	Entidade::Obstaculo::Obstaculo* chao1 = new Entidade::Obstaculo::Obstaculo(sf::Vector2f(500.0f, 350.0f), sf::Vector2f(300.0f, 100.0f), "C:/Users/thiag/Desktop/utfpr/Tec_Prog/1-reuniao-main/1-reuniao-main/Project_Simao2/chao.jpg");
	Entidade::Obstaculo::Obstaculo* chao3 = new Entidade::Obstaculo::Obstaculo(sf::Vector2f(000.0f, 650.0f), sf::Vector2f(1000.0f, 300.0f),"C:/Users/thiag/Desktop/utfpr/Tec_Prog/1-reuniao-main/1-reuniao-main/Project_Simao2/chao.jpg");


	Entidade::Entidade* p1 = static_cast<Entidade::Entidade*>(jogador1);
	Entidade::Entidade* p2 = static_cast<Entidade::Entidade*>(inimigo);
	Entidade::Entidade* p3 = static_cast<Entidade::Entidade*>(inimigo2);

	Entidade::Entidade* pl1 = static_cast<Entidade::Entidade*>(chao1);
	Entidade::Entidade* pl2 = static_cast<Entidade::Entidade*>(chao2);
	Entidade::Entidade* pl3 = static_cast<Entidade::Entidade*>(chao3);

	
	listaEntidades.pushEnt(p1);
	listaEntidades.pushEnt(p2);
	listaEntidades.pushEnt(p3);
	
	listaEntidades.pushEnt(pl1);
	listaEntidades.pushEnt(pl2);
	listaEntidades.pushEnt(pl3);

	pEventos->setJogador(jogador1);
}
*/

void CASTELOpp::Jogo::executar()
{
	
	while (pGrafico->VerificaJanela()) {


		pEventos->executar();
		
		pGrafico->LimpaTela();

		pEstado->Atualizar(getTempo());

		pGrafico->MostraTela();

		Tempo.restart();

	}
	
}

double CASTELOpp::Jogo::getTempo()
{
	return Tempo.getElapsedTime().asSeconds();
}
/*
void CASTELOpp::Jogo::criaFase(ID Id)
{
	if (Id == ID::Floresta) {
		Fase::Floresta* Aux = new Fase::Floresta;
		fase = static_cast<Fase::Fase*>(Aux);
	}
	else {
		if (fase)
			delete(fase);
		Fase::Castelo* Aux = new Fase::Castelo;
		fase = static_cast<Fase::Fase*>(Aux);
	}
}
*/