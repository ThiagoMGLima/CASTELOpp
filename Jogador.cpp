#include "Jogador.h"

//vector<CASTELOpp::Entidade::Personagens::Jogador::Jogador*>* CASTELOpp::Entidade::Personagens::Jogador::Jogador::vJgdr = new vector<CASTELOpp::Entidade::Personagens::Jogador::Jogador*>;
//CASTELOpp::Gerenciador::GerenciadorEventos* CASTELOpp::Gerenciador::GerenciadorEventos::pGerEventos = nullptr;

void CASTELOpp::Entidade::Personagens::Jogador::Jogador::inicializa(){
	vel = sf::Vector2f(VEL_JOGADOR, 0.0f);
	//corpo.setFillColor(sf::Color::Blue);
	podeAndar = false;
	noar = true;
	atacando = false;
	setDano(3);
	vida = VIDA_INICIAL;
	animacao.setAnimacao(CAMINHO "Jogador/gothic-hero-run.png", "ANDA", 12, 0.25f, sf::Vector2f(1.00f, 1.000f));
	animacao.setAnimacao(CAMINHO "Jogador/gothic-hero-idle.png", "PARADO", 4, 0.25f, sf::Vector2f(1.00f,1.00f));
	animacao.setAnimacao(CAMINHO "Jogador/gothic-hero-attack.png", "ATACA", 6, 0.083f, sf::Vector2f(1.500f, 1.00f));
	animacao.setAnimacao(CAMINHO "Jogador/gothic-hero-jump.png", "PULA", 5, 0.25f, sf::Vector2f(1.00f, 1.00f));
	animacao.setAnimacao(CAMINHO "Jogador/gothic-hero-hurt.png", "MORTE", 3, 0.6f, sf::Vector2f(1.00f, 1.00f));
	
}

CASTELOpp::Entidade::Personagens::Jogador::Jogador::Jogador(const sf::Vector2f Pos, const sf::Vector2f Tam) :
	Personagem(Pos, Tam, ID::jogador), TempoMorte(0.0f)
{
	inicializa();
}

CASTELOpp::Entidade::Personagens::Jogador::Jogador::~Jogador()
{
}

void CASTELOpp::Entidade::Personagens::Jogador::Jogador::Atualizar(double t)
{	
	if (vida > 0) {
		AtualizaDistancia(t);
	
		move();

		AtualizaAnimacao();
		//Sempre esta no ar ate que colida com algo em baixo
	
		if (atacando && TmpParaAtac.getElapsedTime().asSeconds() > 0.65f) {
			atacando = false;
		}
	

		pGerGrafico->printElemento(this->getCorpo());

		noar = true; //Sempre no ar ate que colida com algo

	}
	else if (TempoMorte < 0.050f) {
		
		TempoMorte += t;
		AtualizaAnimacao();
		pGerGrafico->printElemento(this->getCorpo());
	}

	//std::cout << this->getPosition().y<<std::endl;
	
}

void CASTELOpp::Entidade::Personagens::Jogador::Jogador::AtualizaDistancia(double t) {
	
	//altera ds se for menor ou maior que a vel max permitida 

	//Deslocamento = deslocamento_inicial.t + (a*t^2)/2
	

	vel.x += ACELERACAO_X * t + VEL_JOGADOR;
	if (vel.x > VEL_MAX_X_J) {
		vel.x = VEL_MAX_X_J;
	}
	else if (vel.x < -VEL_MAX_X_J) {
		vel.x = -VEL_MAX_X_J;
	}
	ds.x = t * vel.x;

	if (noAr()) {
		vel.y += GRAVIDADE * t;
		if (vel.y > VEL_MAX_Y) {
			vel.y = VEL_MAX_Y;
		}
		ds.y = t * vel.y;
	}
}

void CASTELOpp::Entidade::Personagens::Jogador::Jogador::AtualizaAnimacao()
{
	//std::cout << atacando << std::endl;
	if (vida > 0) {
		if (atacando) {
			animacao.atualizar(AndarEsq, "ATACA");
		}
		else if (noAr()){
			animacao.atualizar(AndarEsq, "PULA");
		}
		else if (podeAndar) {
			animacao.atualizar(AndarEsq, "ANDA");
		}
		else {
			animacao.atualizar(AndarEsq, "PARADO");
		}
	}
	else {
		animacao.atualizar(AndarEsq, "MORTE");
	}
	

}

void CASTELOpp::Entidade::Personagens::Jogador::Jogador::move()
{

	if (podeAndar) {
		if (AndarEsq)
			corpo.setPosition(corpo.getPosition().x - fabs(ds.x), corpo.getPosition().y);
		else
			corpo.setPosition(corpo.getPosition().x + fabs(ds.x), corpo.getPosition().y);
	}
	else {
		vel.x = 0.0;
	}

	if (noAr()) {
		corpo.setPosition(corpo.getPosition().x, corpo.getPosition().y + ds.y);

	}

}
void CASTELOpp::Entidade::Personagens::Jogador::Jogador::TomaDano(ID id)
{
}
bool CASTELOpp::Entidade::Personagens::Jogador::Jogador::GerirAtk(Entidade* pEntidade)
{
	if (fabs(this->getPosition().x - pEntidade->getPosition().x) < RANGE_ATK_J && fabs(this->getPosition().y - pEntidade->getPosition().y) < RANGE_ATK_J && nPodeAtacar)
		return true;
	else
		return false;
}

float CASTELOpp::Entidade::Personagens::Jogador::Jogador::getVida() const
{
	return vida;
}

bool CASTELOpp::Entidade::Personagens::Jogador::Jogador::Aparecer() const
{
	if (getVida() > 0)
		return true;
	else
		return false;
}


void CASTELOpp::Entidade::Personagens::Jogador::Jogador::Atacar()
{

	if (!nPodeAtacar && TmpParaAtac.getElapsedTime().asSeconds() > 0.5) {
		nPodeAtacar = true;
	}
	else {
		nPodeAtacar = false;
	}
	if (!atacando && TmpParaAtac.getElapsedTime().asSeconds() > 0.5f) {
			atacando = true;
			TmpParaAtac.restart();
	}
	
}

void CASTELOpp::Entidade::Personagens::Jogador::Jogador::Atacar(Entidade* EntidadeAtacada)
{
	EntidadeAtacada->TomaDano(getDano());
	nPodeAtacar = false;
}

void CASTELOpp::Entidade::Personagens::Jogador::Jogador::Pular() {
	
	if (!noAr()) {
		noar = true;
		vel.y = -PULO;
	}
}