#pragma once
#include "Ente.h"

#include "SFML/Graphics.hpp"

#include "ID.h"

#include "GerenciadorGrafico.h"


#define GRAVIDADE 1000000.0f
#define VEL_MAX_Y 10000.0f
#define VEL_MAX_X_I 800.0f
#define VEL_MAX_X_J 10000.0f
#define ACELERACAO_X 1000.0f

namespace CASTELOpp {
	
	namespace Entidade {
		
		class Entidade : public Ente{

		protected:
			sf::Vector2f vel;
			sf::RectangleShape corpo;
			bool noar;
			
			float dano;
			bool nPodeAtacar;
			sf::Clock TmpParaAtac;
			bool aparecer;

		public:
			Entidade(const sf::Vector2f pos, const sf::Vector2f tam,const ID id);
			~Entidade();
			const sf::RectangleShape getCorpo() const;
			const sf::Vector2f getPosition() const;
			const sf::Vector2f getTam() const;
			virtual void Atualizar(double t) {};
			void setVel(sf::Vector2f Vel);
			sf::Vector2f getVel();
			void setNoAr(bool Estado);
			void mudarPosicao(sf::Vector2f pos);
			virtual void TomaDano(float quantidade) = 0;
			void setDano(float quantidade);
			float getDano() const;
			virtual bool GerirAtk(Entidade* pEntidade) = 0;
			virtual void Atacar(Entidade* EntidadeAtacada) = 0;
			virtual bool Aparecer() const = 0;
		};
	}
}


