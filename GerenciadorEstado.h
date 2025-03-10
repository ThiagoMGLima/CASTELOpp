#pragma once

#include "ConstrutorEstado.h"

#include "GerenciadorGrafico.h"
#include <stack>
using std::stack;


namespace CASTELOpp {
	namespace Gerenciador {
		class GerenciadorEstado
		{
		private:
            std::stack<Estado::Estado*> pilhaEstados;
            
            //Builder
            Construtor::ConstrutorEstado construtorEstado;

            //padrão de projeto singleton
            static GerenciadorEstado* pGerenciadorEstado;
            GerenciadorEstado();

        public:
            ~GerenciadorEstado();
            static GerenciadorEstado* getGerenciadorEstado();
            void Atualizar(double t);
            void addEstado(const ID Id, int num=0);
            void removerEstado();
            Estado::Estado* getEstadoAtual();
		};
	}
}


