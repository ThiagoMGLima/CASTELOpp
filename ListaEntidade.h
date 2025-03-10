#pragma once
#include "Lista.h"
#include "Entidade.h"

namespace CASTELOpp {
	namespace Listas {

		class ListaEntidade
		{
		private:
			Lista<CASTELOpp::Entidade::Entidade> objListaEntidade;
		public:
			ListaEntidade();
			~ListaEntidade();
			void pushEnt(CASTELOpp::Entidade::Entidade* entidade);
			void popEnt(int pos);
			int lenEnt();
			CASTELOpp::Entidade::Entidade* operator[](int pos);
			void executar(double t);
			Lista<CASTELOpp::Entidade::Entidade>* getListaEntidade();
		};
	}

}


