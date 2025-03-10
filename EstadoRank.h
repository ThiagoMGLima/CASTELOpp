#pragma once
#include "Estado.h"
#include "MenuRank.h"

namespace CASTELOpp {
	namespace Estado {
		class EstadoRank :
			public Estado
		{
		private:
			Menu::MenuRank* pMenuRank;
		public:
			EstadoRank();
			~EstadoRank();
			void Atualizar(double t);
			Menu::MenuRank* getRank() const;
		};
	}
}