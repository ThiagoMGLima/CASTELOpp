#include "Inimigo.h"

//Trocar dps Atualizar Animacao

void CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::Inicializa()
{
	vel = sf::Vector2f(VELOCIDADE_INIMIGO, VELOCIDADE_INIMIGO);
	sorteado = 2;
	jaAtacou = false;
	atacando = false;
}

CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::Inimigo(const sf::Vector2f Pos, const sf::Vector2f Tam, vector<Entidade*> vjogador) :
	Personagem(Pos, Tam, ID::inimigo), vJogadores(vjogador), TempoMorte(0.0f), temJgdrPerto(false)
{
	
	Inicializa();
}

CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::~Inimigo()
{
	if (!vJogadores.empty()) {
		for (int i = 0; i < vJogadores.size(); i++) {
			delete(vJogadores.operator[](i));
		}
		vJogadores.clear();
	}
}

void CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::Persegue(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	if (posJogador.x - posInimigo.x > 0.0f) {
		AndarEsq = false;
		
		//So move se n estiver atacando
		if(!atacando)
			corpo.move(fabs(ds.x), 0.0f);
		else {
			corpo.move(0.0f, 0.0f);
		}
	}
	else {
		AndarEsq = true;
		if (!atacando)
			corpo.move(-fabs(ds.x), 0.0f);
		else {
			corpo.move(0.0f, 0.0f);
		}
	}
	if (noAr()) {
		corpo.move(0.0f, ds.y);
	}
	else {
		vel.y = 0;
	}

}

void CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::moveAle() {
	
	//movimento aleatorio que se mantem por 1s
	
	float dt = relogio.getElapsedTime().asSeconds();
	
	if (dt > 1.0f) {

		sorteado = rand() % 3; 
		relogio.restart();
	}
	if (sorteado == 0) {
		podeAndar = true;
		AndarEsq = false;
		corpo.move(fabs(ds.x), 0.0f);
	}

	else if (sorteado == 1) {
		
		AndarEsq = true;
		corpo.move(-fabs(ds.x), 0.0f);
	}
		

	else {
		podeAndar = false;
		vel.x = 0.0f;
	}

	if (noAr()) {
		corpo.move(0.0f, ds.y);
	}
	else {
		vel.y = 0;
		
	}
	
	noar = true;
	
}

void CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::Atualizar(double t)
{
	if (vida > 0) {

		atualizaDistancia(t);
		move();
		AtualizaAnimacao();
		pGerGrafico->printElemento(getCorpo());
		noar = true; //Sempre no ar ate que colida com algo
	}
	else if (TempoMorte < 0.050f) {
		TempoMorte += t;
		AtualizaAnimacao();
		pGerGrafico->printElemento(getCorpo());
	}

}

void CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::atualizaDistancia(double t)
{
	vel.x += ACELERACAO_X * t + VELOCIDADE_INIMIGO;
	if(vel.x > VEL_MAX_X_I){
		vel.x = VEL_MAX_X_I;
	}
	else if (vel.x < -VEL_MAX_X_I) {
		vel.x = -VEL_MAX_X_I;
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

void CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::move() {
	
	if (fabs(getDistInimJog().x) < RAIO_AGRO && fabs(getDistInimJog().y) < RAIO_AGRO) {
		Persegue(getJogPerto()->getPosition(), this->getPosition());
	}
	else
		moveAle();
		podeAndar = true;		
}

void CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::AtualizaAnimacao()
{
	if (vida > 0) {
		if (atacando) {
			animacao.atualizar(AndarEsq, "ATACA"); 
		}
		else if (podeAndar) {
			animacao.atualizar(AndarEsq, "ANDA");
		}
		else if (noAr()) {
			animacao.atualizar(AndarEsq, "PULA");
		}
		else {
			animacao.atualizar(AndarEsq, "PARADO");
		}
	}
	else {
		animacao.atualizar(AndarEsq, "MORTE");
	}
	
}

sf::Vector2f CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::getDistInimJog()
{
	//retorna distancia do jogador mais proximo

	sf::Vector2f posJogador = getJogPerto()->getPosition();
	sf::Vector2f posInimigo = this->getPosition();

	return (sf::Vector2f(fabs(posJogador.x - posInimigo.x), fabs(posJogador.y - posInimigo.y)));
	
}

bool CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::GerirAtk(Entidade* pEntidade)
{

	if (fabs(this->getPosition().x - pEntidade->getPosition().x) < RAIO_ATK && fabs(this->getPosition().y - pEntidade->getPosition().y) < RAIO_ATK) {
		return true;
	}
	else if (getDistInimJog().x < RAIO_ATK && getDistInimJog().y < RAIO_ATK) {
		return false;
	}
	else {
		TmpParaAtac.restart();
		atacando = false;
		jaAtacou = false;
		return false;
	}
		
}

float CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::getVida() const
{
	return vida;
}

bool CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::Aparecer() const
{
	if (getVida() > 0)
		return true;
	else
		return false;;
}

CASTELOpp::Entidade::Entidade* CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::getJogPerto()
{
	//retorna distancia do jogador mais proximo

	sf::Vector2f posJogador1 = vJogadores.operator[](0)->getPosition();
	sf::Vector2f posInimigo = this->getPosition();

	if (vJogadores.size() > 1 && vJogadores.operator[](1)->Aparecer()) {
		
		sf::Vector2f posJogador2 = vJogadores.operator[](1)->getPosition();


		if (fabs(posJogador1.y - posInimigo.y) < fabs(posJogador2.y - posInimigo.y) && fabs(posJogador1.x - posInimigo.x) < fabs(posJogador2.x - posInimigo.x) && vJogadores.operator[](0)->Aparecer()) {
			return vJogadores.operator[](0);
		}
		else if (fabs(posJogador1.y - posInimigo.y) > fabs(posJogador2.y - posInimigo.y) && fabs(posJogador1.x - posInimigo.x) > fabs(posJogador2.x - posInimigo.x) && vJogadores.operator[](1)->Aparecer()) {
			return vJogadores.operator[](1);
		}
		else {
			if (fabs(posJogador1.x - posInimigo.x) < fabs(posJogador2.x - posInimigo.x) && vJogadores.operator[](0)->Aparecer())
				return vJogadores.operator[](0);
			else {
				return vJogadores.operator[](1);
			}
		}
	}
	else {
		return (vJogadores.operator[](0));
	}
}


void CASTELOpp::Entidade::Personagens::Inimigo::Inimigo::Atacar(Entidade* EntidadeAtacada) {
	
	if (!atacando) {
		atacando = true;
	}
	else if (TmpParaAtac.getElapsedTime().asSeconds() > 0.75f) {
		if (!jaAtacou) {
			EntidadeAtacada->TomaDano(getDano());
			jaAtacou = true;
		}
		if (TmpParaAtac.getElapsedTime().asSeconds() >= 0.75f) {
			atacando = false;
			TmpParaAtac.restart();
			jaAtacou = false;
		}
	}
	
}

