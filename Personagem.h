#pragma once
#include "SFML/Graphics.hpp"
#include "Entidade.h"
#include "Animacao.h"
#include <vector>
using std::vector;

namespace CASTELOpp {
	
	namespace Entidade {
		
		namespace Personagens {
			
			class Personagem : 
			public Entidade {

			protected:

				bool atacando;
				Animacao::Animacao animacao;
				float vida;
				//movimento
				bool podeAndar;
				bool AndarEsq;
				sf::Vector2f ds;
			public:
				Personagem(const sf::Vector2f Pos, const sf::Vector2f Tam,const ID id);
				~Personagem();
				virtual void Atualizar(double t) {};
				virtual void atualizaDistancia(double t) {};
				void andar(const bool paraEsquerda);
				void parar();
				//virtual void colisao(Entidade* entidadeColidida, sf::Vector2f desl);
				virtual void AtualizaAnimacao() = 0;
				bool noAr();
				float getVida();
				virtual bool GerirAtk(Entidade* pEntidade);
				virtual void Atacar(Entidade* EntidadeAtacada);
				void TomaDano(float quatidade);
				virtual bool Aparecer() const { return true; };
			};
		}
		
	}
}

