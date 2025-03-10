#pragma once
//Biblioteca grafica
#include "SFML/Graphics.hpp"
//Lista de entidades
#include "ListaEntidade.h"

//Biblioteca para obter a funcao do modulo de um numero
#include <math.h>

namespace CASTELOpp {
	namespace Gerenciador {
		
		class GerenciadorColisao
		{
		private:
			Listas::ListaEntidade* pListaPersonagens;
			Listas::ListaEntidade* pListaObstaculos;

		public:
			GerenciadorColisao(Listas::ListaEntidade* pListaEntidades);
			~GerenciadorColisao();
			const sf::Vector2f calculaColisao(Entidade::Entidade* ent1, Entidade::Entidade* ent2);
			void executar();
			void Colisao(Entidade::Entidade* Entidade, Entidade::Entidade* EntidadeColidida, sf::Vector2f desl);
			void AtualizaListas(Entidade::Entidade* entCriada);

		};
	}
}