#pragma once
#define VIDA_INICIAL 15
#define VEL_JOGADOR 30.5f
#define RANGE_ATK_J 165.0f

#define PULO 20000.0f    //Arrumar
#define ATRITO 000000000.0f 

#include "Personagem.h"
#include <math.h>

namespace CASTELOpp {
	
	namespace Entidade {
		
		namespace Personagens {
		
			namespace Jogador {
			
				class Jogador: 
					public Personagem {
				private:
					float TempoMorte;
					void inicializa();
					

				public:
					Jogador(const sf::Vector2f Pos, const sf::Vector2f Tam);
					~Jogador();
					void Atualizar(double t);
					void AtualizaDistancia(double t);
					void AtualizaAnimacao();
					void Atacar();
					void Atacar(Entidade* EntidadeAtacada);
					void Pular();
					void move();
					virtual void TomaDano(ID id);
					bool GerirAtk(Entidade* pEntidade);
					float getVida() const;
					bool Aparecer() const;
				};
			}
		}
	}
}