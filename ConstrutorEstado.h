#pragma once
#include "EstadoMenu.h"
#include "EstadoJogar.h"
#include "ConstrutorFase.h"
#include "EstadoRank.h"

namespace CASTELOpp {
	namespace Construtor {
		class ConstrutorEstado
		{
        private:
            Estado::Estado* criarEstadoJogar(const ID Id,int numJogadores);
            Estado::Estado* criaMenu();
            Estado::Estado* criaRank();
        
        public:
            ConstrutorEstado();
            ~ConstrutorEstado();
            Estado::Estado* criarEstado(const ID Id, int num);
        
		};
	}
}


