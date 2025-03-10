#pragma once
#include "Castelo.h"
#include "Floresta.h"

namespace CASTELOpp {
	namespace Construtor {
		class ConstrutorFase
		{
		public:
			ConstrutorFase();
			~ConstrutorFase();
			Fase::Fase* criarFase(const ID Id, int numJogadores);
		private:
			Fase::Fase* criarCastelo(int numJogadores);
			Fase::Fase* criarFloresta(int numJogadores);
		};
	}
}


