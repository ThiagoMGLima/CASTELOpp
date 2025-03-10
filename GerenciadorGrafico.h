#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

namespace CASTELOpp {
	
	namespace Gerenciador {
		
		class GerenciadorGrafico
		{
		private:
			sf::RenderWindow* pWindow;
			sf::View camera;

			/*
			Padrao de projeto Singleton
										*/ 
			
			static GerenciadorGrafico* pGerGrafico;
			GerenciadorGrafico();
			
		public:
			~GerenciadorGrafico();
			static GerenciadorGrafico* getGerGrafico();
			sf::RenderWindow* getWindow();
			void printElemento(sf::RectangleShape Elemento);
			void LimpaTela();
			void MostraTela();
			void FechaJanela();
			bool VerificaJanela();
			void atualizaCamera(const sf::Vector2f pos);
			sf::View getCamera() const;
			
			const sf::Texture CarregarTextura(const char* caminhoTextura);
		};
	}
}