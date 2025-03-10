#pragma once
#include "GerenciadorGrafico.h"
#include "ID.h"
#include <math.h>

#define CAMINHO "./Imagens/"

namespace CASTELOpp {
	
	class Ente
	{
	private:
		const ID id;
	protected:
		static Gerenciador::GerenciadorGrafico* pGerGrafico;
		sf::Texture textura;
	public:
		Ente(ID id);
		~Ente();
		virtual void Atualizar(double t) = 0;
		ID getId();
	};
}