#pragma once

#include "GerenciadorGrafico.h"
#include "GerenciadorEstado.h"

#include <vector>
using std::vector;

namespace CASTELOpp {
	
	namespace Gerenciador {
		
		class GerenciadorEventos
		{
		private:
			
			GerenciadorGrafico* pGerGrafico;
			GerenciadorEstado* pGerEstado;
			
			/*
				Singleton pattern
			*/

			static GerenciadorEventos* pGerEventos;
			GerenciadorEventos();
			
		public:
			~GerenciadorEventos();
			GerenciadorEventos* getGerEventos();
			void TeclaPressionada(sf::Keyboard::Key tecla);
			void TeclaSolta(sf::Keyboard::Key tecla);
			void executar();
		};
	}
}