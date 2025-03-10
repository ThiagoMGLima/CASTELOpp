#pragma once

#include "Imagem.h"
#include <map>

namespace CASTELOpp {
	namespace Animacao {
		
		class Animacao
		{
		private:
			sf::RectangleShape* corpo;
			std::map<std::string, Imagem*> mapImagem;
			sf::Clock clock;
			std::string imgAtual;
		public:
			Animacao(sf::RectangleShape* corpo);
			~Animacao();
			void atualizar(const bool paraEsquerda, std::string imgAtual);
			void setAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImagem, const float tempo, const sf::Vector2f escala);
		};
	}
}