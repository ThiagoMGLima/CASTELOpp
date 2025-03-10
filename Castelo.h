#pragma once
#include "Fase.h"

#define NUM_MAX_INI 4

namespace CASTELOpp {
	namespace Fase {
		class Castelo:
			public Fase
		{
		private:

			void InstanciaEnt(int numJogadores);
		public:
			Castelo(int numJogadores);
			~Castelo();
			void criarFundo();
			bool acabouFase();
		};
	};
}



