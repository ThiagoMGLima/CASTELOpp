#include "Fase.h"

int CASTELOpp::Fase::Fase::num_Jog = 0;
float CASTELOpp::Fase::Fase::tempoemFase = 0.0f;

CASTELOpp::Fase::Fase* CASTELOpp::Fase::Fase::pFase = nullptr;


vector<CASTELOpp::Entidade::Entidade*> CASTELOpp::Fase::Fase::vJogadores = CASTELOpp::Fase::Fase::vJogadores;

CASTELOpp::Fase::Fase::Fase(ID id) :
	Ente(id), listaEntidades(), colisor(new Gerenciador::GerenciadorColisao(&listaEntidades)), fundo(id),AcaboFase(false)
{
	pFase = this;
}

CASTELOpp::Fase::Fase::~Fase()
{
}

bool CASTELOpp::Fase::Fase::JogadoresMorreram()
{
	for (Entidade::Entidade* jogador : vJogadores) {
		if (jogador->Aparecer()) {
			return false;
		}
	}
	vJogadores.clear();
	return true;
}

void CASTELOpp::Fase::Fase::setNumJog(int nJog)
{
	num_Jog = nJog;
}



CASTELOpp::Fase::Fase* CASTELOpp::Fase::Fase::getpFase()
{
	return pFase;
}

int CASTELOpp::Fase::Fase::getNumJog() const
{
	return num_Jog;
}

void CASTELOpp::Fase::Fase::Atualizar(double t)
{
	fundo.Atualizar(t);
	listaEntidades.executar(t);
	colisor->executar();



	for (int i = vJogadores.size() - 1; i >= 0; i--) {
		if (vJogadores.operator[](i)->Aparecer()) {
			pGerGrafico->atualizaCamera(sf::Vector2f(vJogadores.operator[](i)->getPosition().x, 400.0f));
			break;
		}
	}
	
}

void CASTELOpp::Fase::Fase::clearvJogadores()
{
	vJogadores.clear();
}


void CASTELOpp::Fase::Fase::criaJogador(sf::Vector2f pos, sf::Vector2f tam) {

	Entidade::Personagens::Jogador::Jogador* jogador = new Entidade::Personagens::Jogador::Jogador(pos, tam);

	Entidade::Entidade* p1 = static_cast<Entidade::Entidade*>(jogador);

	vJogadores.push_back(p1);

	listaEntidades.pushEnt(p1);

	//add jogador a lista de personagens do ger_Colisao
	colisor->AtualizaListas(p1);
}

void CASTELOpp::Fase::Fase::criaInimigoFantasma(sf::Vector2f pos, sf::Vector2f tam, vector<Entidade::Entidade*> pJog) {
	
	Entidade::Personagens::Inimigo::Fantasma* Cinimigo = new Entidade::Personagens::Inimigo::Fantasma(pos, tam, pJog);
	Entidade::Entidade* In1 = static_cast<Entidade::Entidade*>(Cinimigo);
	listaEntidades.pushEnt(In1);

	//add inimigo a lista de personagens do ger_Colisao
	colisor->AtualizaListas(In1);
}

void CASTELOpp::Fase::Fase::criaPlataforma(sf::Vector2f pos)
{
	Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos);
	Entidade::Entidade* Obs1 = static_cast<Entidade::Entidade*>(plataforma);
	listaEntidades.pushEnt(Obs1);

	//add Plataforma a lista de Obstaculos do ger_Colisao
	colisor->AtualizaListas(Obs1);
}

void CASTELOpp::Fase::Fase::criaPlataforma(sf::Vector2f pos, sf::Vector2f tam, const char* caminhoTextura)
{
	Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos, tam, caminhoTextura);
	Entidade::Entidade* Obs1 = static_cast<Entidade::Entidade*>(plataforma);
	listaEntidades.pushEnt(Obs1);

	//add Plataforma a lista de Obstaculos do ger_Colisao
	colisor->AtualizaListas(Obs1);
}

void CASTELOpp::Fase::Fase::criaChao(sf::Vector2f pos,sf::Vector2f tam,bool invi)
{
	Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos,tam,invi);
	Entidade::Entidade* Obs1 = static_cast<Entidade::Entidade*>(plataforma);
	listaEntidades.pushEnt(Obs1);

	//add Plataforma a lista de Obstaculos do ger_Colisao
	colisor->AtualizaListas(Obs1);
}

void CASTELOpp::Fase::Fase::criaImp(sf::Vector2f pos, vector<Entidade::Entidade*> pJog)
{
	Entidade::Personagens::Inimigo::Imp* pImp = new Entidade::Personagens::Inimigo::Imp(pos,pJog);
	Entidade::Entidade* pEnteImp = static_cast<Entidade::Entidade*>(pImp);
	listaEntidades.pushEnt(pEnteImp);

	colisor->AtualizaListas(pEnteImp);
}

void CASTELOpp::Fase::Fase::criaProjetil(sf::Vector2f pos, bool Esq)
{
	Entidade::Projetil* pProjet = new Entidade::Projetil(pos, Esq);
	Entidade::Entidade* pEntProjet = static_cast<Entidade::Entidade*>(pProjet);
	listaEntidades.pushEnt(pEntProjet);

	colisor->AtualizaListas(pEntProjet);
}

void CASTELOpp::Fase::Fase::criaChefe(sf::Vector2f Pos, sf::Vector2f Tam, vector<Entidade::Entidade*> pJog)
{
	Entidade::Personagens::Inimigo::Chefe* pChefe = new Entidade::Personagens::Inimigo::Chefe(Pos,Tam, pJog);
	Entidade::Entidade* pEnteChefe = static_cast<Entidade::Entidade*>(pChefe);
	listaEntidades.pushEnt(pEnteChefe);

	colisor->AtualizaListas(pEnteChefe);

}

void CASTELOpp::Fase::Fase::criaLama(sf::Vector2f Pos)
{
	Entidade::Obstaculo::Lama* ObstLama = new Entidade::Obstaculo::Lama(Pos);
	Entidade::Entidade* EntLama = static_cast<Entidade::Entidade*>(ObstLama);
	listaEntidades.pushEnt(EntLama);

	colisor->AtualizaListas(EntLama);
}

float CASTELOpp::Fase::Fase::getTmpfase() const
{
	return tempoemFase;
}

void CASTELOpp::Fase::Fase::atualizatmpfase(double t)
{
	tempoemFase += t;
}

void CASTELOpp::Fase::Fase::zeraTmpfase()
{
	tempoemFase = 0.0f;
}

void CASTELOpp::Fase::Fase::criaToxic(sf::Vector2f pos)
{
	Entidade::Obstaculo::Toxico* platToxic = new Entidade::Obstaculo::Toxico(pos);
	Entidade::Entidade* Toxic = static_cast<Entidade::Entidade*>(platToxic);
	listaEntidades.pushEnt(Toxic);

	//add Toxic a lista de Obstaculos do ger_Colisao
	colisor->AtualizaListas(Toxic);
}


vector<CASTELOpp::Entidade::Entidade*> CASTELOpp::Fase::Fase::getJogador()
{
	return vJogadores;
}



