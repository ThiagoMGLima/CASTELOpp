#include "GerenciadorColisao.h"

CASTELOpp::Gerenciador::GerenciadorColisao::GerenciadorColisao(Listas::ListaEntidade* pListaEntidades):
	pListaPersonagens(new Listas::ListaEntidade),pListaObstaculos(new Listas::ListaEntidade)
{
	
}

CASTELOpp::Gerenciador::GerenciadorColisao::~GerenciadorColisao()
{
	if (pListaPersonagens)
		delete(pListaPersonagens);
	pListaPersonagens = NULL;

	if (pListaObstaculos)
		delete(pListaObstaculos);
	pListaObstaculos = NULL;
	
}

const sf::Vector2f CASTELOpp::Gerenciador::GerenciadorColisao::calculaColisao(Entidade::Entidade* ent1, Entidade::Entidade* ent2)
{
	
	sf::Vector2f pos1 = ent1->getPosition();
	sf::Vector2f pos2 = ent2->getPosition();

	sf::Vector2f tam1 = ent1->getTam();
	sf::Vector2f tam2 = ent2->getTam();
	
	

	sf::Vector2f extremosDasEnts(fabs((pos1.x + tam1.x / 2.00f) - (pos2.x + tam2.x / 2.0f)),
								  fabs((pos1.y + tam1.y / 2.00f) - (pos2.y + tam2.y / 2.0f))
								);


	sf::Vector2f somaLarguraEntidades(tam1.x / 2.00f + tam2.x/2.000f, tam1.y / 2.00f + tam2.y/2.000f);


	sf::Vector2f repulsao(extremosDasEnts.x - somaLarguraEntidades.x, extremosDasEnts.y - somaLarguraEntidades.y);

	return repulsao;

}

void CASTELOpp::Gerenciador::GerenciadorColisao::executar() //Melhorar
{
	//colisao com Personagens
	
	for (int i = 0; i < pListaPersonagens->lenEnt(); i++) {
		for (int j = i + 1; j < pListaPersonagens->lenEnt(); j++) {
			if (pListaPersonagens->operator[](j)->Aparecer() && pListaPersonagens->operator[](i)->Aparecer()){
				if (pListaPersonagens->operator[](i)->getId() != pListaPersonagens->operator[](j)->getId()) {
					sf::Vector2f deslocamento = calculaColisao(pListaPersonagens->operator[](i), pListaPersonagens->operator[](j));
					if (deslocamento.x <= 0 && deslocamento.y <= 0) {
						Colisao(pListaPersonagens->operator[](i), pListaPersonagens->operator[](j), deslocamento);
					}
				}
			}
		}
	//}
	
	//Colisao com Obstaculos
	//for (int i = 0; i < pListaPersonagens->lenEnt(); i++) {
		for (int j = 0; j < pListaObstaculos->lenEnt(); j++) {
			sf::Vector2f deslocamento = calculaColisao(pListaPersonagens->operator[](i), pListaObstaculos->operator[](j));
			if (deslocamento.x <= 0 && deslocamento.y <= 0) {
				if (pListaObstaculos->operator[](j)->getId() == ID::Plataforma)
					Colisao(pListaPersonagens->operator[](i), pListaObstaculos->operator[](j), deslocamento);

				else if (pListaPersonagens->operator[](i)->getId() == ID::jogador && (pListaObstaculos->operator[](j)->getId() == ID::Toxico || pListaObstaculos->operator[](j)->getId() == ID::Lama) || (pListaObstaculos->operator[](j)->getId() == ID::Projetil && pListaObstaculos->operator[](j)->Aparecer())) {
					if (pListaObstaculos->operator[](j)->GerirAtk(pListaPersonagens->operator[](i))) {
						pListaObstaculos->operator[](j)->Atacar(pListaPersonagens->operator[](i));
					}
				}
			}

		}
	//}
	//AtK com Personagens
	//for (int i = 0; i < pListaPersonagens->lenEnt(); i++) {
		for (int j = 0; j < pListaPersonagens->lenEnt(); j++) {
			if (pListaPersonagens->operator[](j)->Aparecer() && pListaPersonagens->operator[](i)->Aparecer()) {
				if (pListaPersonagens->operator[](i)->getId() != pListaPersonagens->operator[](j)->getId()) { //Retira fogo amigo
					if (pListaPersonagens->operator[](i)->GerirAtk(pListaPersonagens->operator[](j))) {
						pListaPersonagens->operator[](i)->Atacar(pListaPersonagens->operator[](j));
					}
				}
			}
		}
	}
}

void CASTELOpp::Gerenciador::GerenciadorColisao::Colisao(Entidade::Entidade* Entidade, Entidade::Entidade* EntidadeColidida,sf::Vector2f desl)
{

	if (desl.y >= desl.x)  //colisao vertical
	{
		if (Entidade->getPosition().y <= EntidadeColidida->getPosition().y) //colisao em cima da plataforma
		{

			Entidade->setVel(sf::Vector2f(Entidade->getVel().x,0.0f));
			Entidade->setNoAr(false);
			Entidade->mudarPosicao(sf::Vector2f(Entidade->getPosition().x, Entidade->getPosition().y + desl.y)); //define a posicao em cima da plataforma
		}
		else //colisao em baixo
		{
			Entidade->setVel(sf::Vector2f(Entidade->getVel().x, 0.0f)); //bateu a cabeca
			Entidade->mudarPosicao(sf::Vector2f(Entidade->getPosition().x, Entidade->getPosition().y - desl.y)); //define a posicao em baixo da plataforma
		}

	}
	else if (desl.y < desl.x) //colisao horizontal
	{
		if (Entidade->getPosition().x < EntidadeColidida->getPosition().x) { //caso a colisao ocorra no lado esquerdo
			Entidade->mudarPosicao(sf::Vector2f(Entidade->getPosition().x + desl.x, Entidade->getPosition().y));
		}
		else
		{
			Entidade->mudarPosicao(sf::Vector2f(Entidade->getPosition().x - desl.x, Entidade->getPosition().y));
		}
	}

}

void CASTELOpp::Gerenciador::GerenciadorColisao::AtualizaListas(Entidade::Entidade* entCriada)
{
	if (entCriada->getId() == ID::jogador || entCriada->getId() == ID::inimigo) {
		
		pListaPersonagens->pushEnt(entCriada);
	}
	else {
		pListaObstaculos->pushEnt(entCriada);
	}
}