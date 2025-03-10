#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>

#include "Menu.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorEstado.h"


namespace CASTELOpp {
	
	class Jogo {

	private:
		
		static Gerenciador::GerenciadorGrafico* pGrafico;
		static Gerenciador::GerenciadorEventos* pEventos;
		static Gerenciador::GerenciadorEstado* pEstado;
		
		
		//Tempo de um volta no loop principal do jogo
		sf::Clock Tempo;

	public:
		Jogo();
		~Jogo();
		//void InstanciaEnt();
		void executar();
		double getTempo();
		
	};
}


